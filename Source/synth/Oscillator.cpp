#include "Oscillator.h"
#include "Config.h"

// TODO remove dependency
#include <cmath>

namespace blankenhain {
	Oscillator::Oscillator(const OscillatorSettings* settings_, unsigned int note) :
		settings(settings_)
	{
		frequency = A_FREQUENCY * pow(2.0, (note - 69) / 12.0) / settings->sampleRate;
		randomValue = 0;
	}

	void Oscillator::value(Time time, float output[2]) {
		float sample;
		const float TAU = acos(-1.0) * 2.0;
		switch (settings->type) {
		case OscillatorType::SINE:
			sample = sin(time * frequency * TAU);
			break;
		case OscillatorType::SQUARE:
			sample = fmod(time * frequency, 2.0) < 1.0 ? 1.0 : -1.0;
			break;
		case OscillatorType::SAW:
			sample = fmod(time * frequency, 2.0) - 1.0;
			break;
		case OscillatorType::NOISE:
			sample = rand() * 2.0 - 1.0;
			break;
		}
		output[0] = sample;
		output[1] = sample;
	}

	float Oscillator::rand() {
		const unsigned int RAND_MAX = (1U << 31) - 1;
		randomValue = (randomValue * 1103515245 + 12345) & RAND_MAX;
		return static_cast<float>(randomValue) / RAND_MAX;
	}
}