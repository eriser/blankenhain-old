#include "Voice.h"

// TODO remove dependency
#include <cmath>

namespace blankenhain {
	Voice::Voice() :
		off(true)
	{
	}

	Voice::Voice(Time start_, unsigned int sampleRate_) :
		off(false),
		start(start_),
		sampleRate(sampleRate_)
	{
	}

	bool Voice::isOff() const {
		return off;
	}

	void Voice::play(Time startTime, Time duration, float* output[2]) {
		for (unsigned int i = 0; i < duration; i++) {
			output[0][i] += sin(440.0 * 2.0 * acos(-1.0) * ((double)i + start) / sampleRate);
			output[1][i] += output[0][i];
		}
	}
}