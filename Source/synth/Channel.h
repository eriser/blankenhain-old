#ifndef CHANNEL_H_INCLUDED
#define CHANNEL_H_INCLUDED

#include "OscillatorSettings.h"
#include "EnvelopeSettings.h"
#include "LFOSettings.h"
#include "FilterSettings.h"
#include "Voice.h"
#include "Config.h"

namespace blankenhain {
	struct Channel {
		Channel() = default;
		Channel(unsigned int sampleRate);

		OscillatorSettings oscillators[OSCILLATORS_PER_CHANNEL];
		EnvelopeSettings envelopes[ENVELOPES_PER_CHANNEL];
		LFOSettings lfos[LFOS_PER_CHANNEL];
		FilterSettings filters[FILTERS_PER_CHANNEL];

		unsigned int sampleRate;
	};
}

#endif  // CHANNEL_H_INCLUDED
