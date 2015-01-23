#ifndef CHANNEL_H_INCLUDED
#define CHANNEL_H_INCLUDED

#include "LFOSettings.h"
#include "EnvelopeSettings.h"
#include "Voice.h"
#include "Config.h"

namespace blankenhain {
	struct Channel {
		EnvelopeSettings envelopes[ENVELOPES_PER_CHANNEL];
		LFOSettings lfos[LFOS_PER_CHANNEL];
	};
}

#endif  // CHANNEL_H_INCLUDED
