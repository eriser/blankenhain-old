#ifndef OSCILLATORSETTINGS_H_INCLUDED
#define OSCILLATORSETTINGS_H_INCLUDED

#include "OscillatorType.h"

namespace blankenhain {
	struct OscillatorSettings {
		OscillatorSettings() = default;
		OscillatorSettings(unsigned int sampleRate_, OscillatorType type_) :
			sampleRate(sampleRate_),
			type(type_)
		{}

		unsigned int sampleRate;
		OscillatorType type;
	};
}

#endif  // OSCILLATORSETTINGS_H_INCLUDED
