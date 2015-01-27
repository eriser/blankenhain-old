#ifndef OSCILLATORSETTINGS_H_INCLUDED
#define OSCILLATORSETTINGS_H_INCLUDED

#include "OscillatorType.h"

namespace blankenhain {
	struct OscillatorSettings {
		OscillatorSettings() = default;
		OscillatorSettings(unsigned int sampleRate_, OscillatorType type_, float detune_) :
			sampleRate(sampleRate_),
			type(type_),
			detune(detune_)
		{}

		unsigned int sampleRate;
		OscillatorType type;
		float detune;
	};
}

#endif  // OSCILLATORSETTINGS_H_INCLUDED
