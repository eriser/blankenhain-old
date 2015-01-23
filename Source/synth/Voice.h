#ifndef VOICE_H_INCLUDED
#define VOICE_H_INCLUDED

#include "Time.h"

namespace blankenhain {
	struct Voice {
		Voice();
		Voice(Time start, unsigned int sampleRate);

		void play(Time startTime, Time duration, float* output[2]);

		Time start;
		bool noteOn;
		bool active;
		unsigned int sampleRate;
	};
}

#endif  // VOICE_H_INCLUDED
