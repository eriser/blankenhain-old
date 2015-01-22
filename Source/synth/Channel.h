#ifndef CHANNEL_H_INCLUDED
#define CHANNEL_H_INCLUDED

#include "LFO.h"
#include "Envelope.h"
#include "Voice.h"

namespace blankenhain {
	struct Channel {
		Envelope envelopes[2];
		LFO lfos[3];
	};
}

#endif  // CHANNEL_H_INCLUDED
