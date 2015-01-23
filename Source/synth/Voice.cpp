#include "Voice.h"
#include "Channel.h"

// TODO remove dependency
#include <cmath>

namespace blankenhain {
	Voice::Voice() :
		noteOn(false),
		active(false)
	{}

	Voice::Voice(
		Time start_,
		const Channel* channel_,
		unsigned int note_) :
		noteOn(true),
		active(true),
		start(start_),
		channel(channel_),
		note(note_)
	{
		for (unsigned int i = 0; i < OSCILLATORS_PER_CHANNEL; i++) {
			oscillators[i] = Oscillator(&channel->oscillators[i]);
		}
		for (unsigned int i = 0; i < OSCILLATORS_PER_CHANNEL; i++) {
			envelopes[i] = Envelope(&channel->envelopes[i]);
		}
		for (unsigned int i = 0; i < OSCILLATORS_PER_CHANNEL; i++) {
			lfos[i] = LFO(&channel->lfos[i]);
		}
		for (unsigned int i = 0; i < OSCILLATORS_PER_CHANNEL; i++) {
			filters[i] = Filter(&channel->filters[i]);
		}
	}

	void Voice::play(Time startTime, Time duration, float* output[2]) {
	}
}