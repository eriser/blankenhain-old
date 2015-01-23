#ifndef CHANNEL_H_INCLUDED
#define CHANNEL_H_INCLUDED

#include "LFOSettings.h"
#include "EnvelopeSettings.h"
#include "Voice.h"

namespace blankenhain {
	struct Channel {
		EnvelopeSettings envelopes[2];
		LFOSettings lfos[3];
	};
}

#endif  // CHANNEL_H_INCLUDED
