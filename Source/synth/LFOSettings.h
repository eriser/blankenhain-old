#ifndef LFOSETTINGS_H_INCLUDED
#define LFOSETTINGS_H_INCLUDED

#include "OscillatorType.h"

namespace blankenhain {
	struct LFOSettings {
		LFOSettings(unsigned int sampleRate_, OscillatorType type_, float rate_, float depth_, bool synced_) :
			sampleRate(sampleRate_),
			type(type_),
			rate(rate_),
			depth(depth_),
			synced(synced_)
		{}

		LFOSettings() {}

		unsigned int sampleRate;
		OscillatorType type;
		float rate;
		float depth;
		bool synced;
	};
}

#endif  // LFOSETTINGS_H_INCLUDED
