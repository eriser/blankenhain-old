#ifndef OSCILLATORSETTINGS_H_INCLUDED
#define OSCILLATORSETTINGS_H_INCLUDED

#include "OscillatorType.h"

namespace blankenhain {
	struct OscillatorSettings {
		OscillatorSettings() = default;
		OscillatorSettings(unsigned int sampleRate_, OscillatorType type_,  float volume_, float detune_) :
			sampleRate(sampleRate_),
			type(type_),
			volume(volume_),
			detune(detune_)
		{}

		unsigned int sampleRate;
		OscillatorType type;
		float volume;
		float detune;
	};
}

#endif  // OSCILLATORSETTINGS_H_INCLUDED
