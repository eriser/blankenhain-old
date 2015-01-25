#include "Filter.h"

// TODO remove dependency
#include <cmath>

#pragma warning(disable: 4351)

namespace blankenhain {
	Filter::Filter(const FilterSettings* settings_) :
		settings(settings_),
		x_1{}, x_2{}, y_1{}, y_2{}
	{}

	void Filter::process(float sample[2]) {
		if (!settings->active) {
			return;
		}

		// compute biquad coefficients

		float a0, a1, a2;
		float b0, b1, b2;

		const float w0 = 2.0f * acos(-1.0f) * settings->frequency / settings->sampleRate;
		const float cos_w0 = cos(w0);
		const float sin_w0 = sin(w0);
		const float alpha = sin_w0 / (2 * settings->Q);

		switch (settings->type) {
		case FilterType::LOWPASS:
			b0 = (1 - cos_w0) / 2;
			b1 = 1 - cos_w0;
			b2 = (1 - cos_w0) / 2;
			a0 = 1 + alpha;
			a1 = -2 * cos_w0;
			a2 = 1 - alpha;
			break;
		case FilterType::HIGHPASS:
			b0 = (1 + cos_w0) / 2;
			b1 = -(1 + cos_w0);
			b2 = (1 + cos_w0) / 2;
			a0 = 1 + alpha;
			a1 = -2 * cos_w0;
			a2 = 1 - alpha;
			break;
		case FilterType::BANDPASS:
			// constant 0dB peak gain
			b0 = alpha;
			b1 = 0;
			b2 = -alpha;
			a0 = 1 + alpha;
			a1 = -2 * cos_w0;
			a2 = 1 - alpha;
			break;
		case FilterType::NOTCH:
			b0 = 1;
			b1 = -2 * cos_w0;
			b2 = 1;
			a0 = 1 + alpha;
			a1 = -2 * cos_w0;
			a2 = 1 - alpha;
			break;
		default:
			b0 = 0;
			b1 = 0;
			b2 = 0;
			a0 = 1;
			a1 = 0;
			a2 = 0;
			break;
		}

		a1 /= a0;
		a2 /= a0;
		b0 /= a0;
		b1 /= a0;
		b2 /= a0;

		// TODO oversampling
		const float out[2] = {
			b0 * sample[0] + b1 * x_1[0] + b2 * x_2[0] - a1 * y_1[0] - a2 * y_2[0],
			b0 * sample[1] + b1 * x_1[1] + b2 * x_2[1] - a1 * y_1[1] - a2 * y_2[1],
		};

		x_2[0] = x_1[0];
		x_2[1] = x_1[1];
		x_1[0] = sample[0];
		x_1[1] = sample[1];
		y_2[0] = y_1[0];
		y_2[1] = y_1[1];
		y_1[0] = out[0];
		y_1[1] = out[1];
		sample[0] = out[0];
		sample[1] = out[1];
	}
}