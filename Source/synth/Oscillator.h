#ifndef OSCILLATOR_H_INCLUDED
#define OSCILLATOR_H_INCLUDED

#include "OscillatorSettings.h"
#include "Time.h"
#include "OscillatorFunction.h"

namespace blankenhain {
	struct Oscillator {
		Oscillator() = default;
		Oscillator(const OscillatorSettings* settings, unsigned int note);

		void value(Time time, float output[2]);

		const OscillatorSettings* settings;
		float frequency;
		OscillatorFunction osc;
	};
}

#endif  // OSCILLATOR_H_INCLUDED
