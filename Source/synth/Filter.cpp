#include "Filter.h"

// TODO remove dependency
#include <cmath>

#include "Functions.h"

#pragma warning(disable: 4351)

namespace blankenhain {
	Filter::Filter(const FilterSettings* settings_) :
		settings(settings_),
		x_1{}, y_1{}, y_2{}
	{}

	void Filter::process(float sample[2], float frequencyMod, float qMod) {
		if (!settings->active) {
			return;
		}

		// compute biquad coefficients
		float a1, a2;
		float b0, b1, b2;

		// TODO multiplier/scaling
		const float frequency = clamp(settings->frequency + frequencyMod * 1000.f, 0.f, 1000.f);
		const float Q = clamp(settings->Q + qMod, 0.01f, 1.f);

		const float w0 = 2.0f * acos(-1.0f) * frequency / (settings->sampleRate * 2);
		const float cos_w0 = cos(w0);
		const float sin_w0 = sin(w0);
		const float alpha = sin_w0 / (2 * Q);

		switch (settings->type) {
		case FilterType::LOWPASS:
			b0 = (1 - cos_w0) / 2;
			b1 = 1 - cos_w0;
			b2 = (1 - cos_w0) / 2;
			a1 = -2 * cos_w0;
			a2 = 1 - alpha;
			break;
		case FilterType::HIGHPASS:
			b0 = (1 + cos_w0) / 2;
			b1 = -(1 + cos_w0);
			b2 = (1 + cos_w0) / 2;
			a1 = -2 * cos_w0;
			a2 = 1 - alpha;
			break;
		case FilterType::BANDPASS:
			// constant 0dB peak gain
			b0 = alpha;
			b1 = 0;
			b2 = -alpha;
			a1 = -2 * cos_w0;
			a2 = 1 - alpha;
			break;
		case FilterType::NOTCH:
			b0 = 1;
			b1 = -2 * cos_w0;
			b2 = 1;
			a1 = -2 * cos_w0;
			a2 = 1 - alpha;
			break;
		default:
			b0 = 0;
			b1 = 0;
			b2 = 0;
			a1 = 0;
			a2 = 0;
			break;
		}

		const float a0 = 1.0 + alpha;
		a1 /= a0;
		a2 /= a0;
		b0 /= a0;
		b1 /= a0;
		b2 /= a0;

		const float out[2] = {
			b0 * sample[0] + b1 * x_1[0] + b2 * x_1[0] - a1 * y_1[0] - a2 * y_2[0],
			b0 * sample[1] + b1 * x_1[1] + b2 * x_1[1] - a1 * y_1[1] - a2 * y_2[1],
		};

		const float out2[2] = {
			b0 * sample[0] + b1 * sample[0] + b2 * x_1[0] - a1 * out[0] - a2 * y_1[0],
			b0 * sample[1] + b1 * sample[1] + b2 * x_1[1] - a1 * out[1] - a2 * y_1[1],
		};

		x_1[0] = sample[0];
		x_1[1] = sample[1];
		y_2[0] = out[0];
		y_2[1] = out[1];
		y_1[0] = out2[0];
		y_1[1] = out2[1];

		sample[0] = out2[0];
		sample[1] = out2[1];
	}
}