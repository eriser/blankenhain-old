#ifndef OSCILLATOR_H_INCLUDED
#define OSCILLATOR_H_INCLUDED

#include "OscillatorSettings.h"

namespace blankenhain {
	struct Oscillator {
		Oscillator() = default;
		Oscillator(const OscillatorSettings* settings);

		const OscillatorSettings* settings;
	};
}

#endif  // OSCILLATOR_H_INCLUDED
