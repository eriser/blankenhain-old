#ifndef OSCILLATOR_H_INCLUDED
#define OSCILLATOR_H_INCLUDED

#include "OscillatorSettings.h"
#include "Time.h"
#include "OscillatorFunction.h"

namespace blankenhain {
	struct Oscillator {
		Oscillator() = default;
		Oscillator(const OscillatorSettings* settings, unsigned int note);

		void value(Time time, float output[2], float volumeMod, float detuneMod);

		const OscillatorSettings* settings;
		int note;
		OscillatorFunction osc;
	};
}

#endif  // OSCILLATOR_H_INCLUDED
