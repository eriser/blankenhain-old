#ifndef OSCILLATOR_H_INCLUDED
#define OSCILLATOR_H_INCLUDED

#include "OscillatorSettings.h"
#include "Time.h"

namespace blankenhain {
	struct Oscillator {
		Oscillator() = default;
		Oscillator(const OscillatorSettings* settings);

		void value(Time time, float output[2]);

		const OscillatorSettings* settings;
	};
}

#endif  // OSCILLATOR_H_INCLUDED
