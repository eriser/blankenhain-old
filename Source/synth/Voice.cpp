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
		const Channel& channel) :
		noteOn(true),
		active(true),
		start(start_),
		sampleRate(channel.sampleRate)
	{
		for (unsigned int i = 0; i < OSCILLATORS_PER_CHANNEL; i++) {
			oscillators[i] = Oscillator(&channel.oscillators[i]);
		}
		for (unsigned int i = 0; i < OSCILLATORS_PER_CHANNEL; i++) {
			envelopes[i] = Envelope(&channel.envelopes[i]);
		}
		for (unsigned int i = 0; i < OSCILLATORS_PER_CHANNEL; i++) {
			lfos[i] = LFO(&channel.lfos[i]);
		}
		for (unsigned int i = 0; i < OSCILLATORS_PER_CHANNEL; i++) {
			filters[i] = Filter(&channel.filters[i]);
		}
	}

	void Voice::play(Time startTime, Time duration, float* output[2]) {
		for (unsigned int i = 0; i < duration; i++) {
			output[0][i] += sin(440.0 * 2.0 * acos(-1.0) * ((double)i + start) / sampleRate);
			output[1][i] += output[0][i];
		}
	}
}