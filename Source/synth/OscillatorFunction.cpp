#include "OscillatorFunction.h"

// TODO remove dependency
#include <cmath>

namespace blankenhain {
	float OscillatorFunction::value(OscillatorType type, float x) {
		const float TAU = acos(-1.0f) * 2.0f;
		switch (type) {
		case OscillatorType::SINE:
			return sin(x * TAU);
		case OscillatorType::SQUARE:
			return fmod(x * 2.0f, 2.0f) < 1.0f ? 1.0f : -1.0f;
		case OscillatorType::SAW:
			return fmod(x * 2.0f, 2.0f) - 1.0f;
		case OscillatorType::NOISE:
			return rand() * 2.0f - 1.0f;
		default:
			return 0;
		}
	}

	float OscillatorFunction::rand() {
		const unsigned int RAND_MAX = (1U << 31) - 1;
		randomValue = (randomValue * 1103515245 + 12345) & RAND_MAX;
		return static_cast<float>(randomValue) / RAND_MAX;
	}
}