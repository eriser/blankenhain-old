#ifndef OSCILLATOR_H_INCLUDED
#define OSCILLATOR_H_INCLUDED

#include "OscillatorSettings.h"
#include "Time.h"

namespace blankenhain {
	struct Oscillator {
		Oscillator() = default;
		Oscillator(const OscillatorSettings* settings, unsigned int note);

		void value(Time time, float output[2]);
		float rand();

		const OscillatorSettings* settings;
		float frequency;
		unsigned int randomValue;
	};
}

#endif  // OSCILLATOR_H_INCLUDED
