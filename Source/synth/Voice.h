#ifndef VOICE_H_INCLUDED
#define VOICE_H_INCLUDED

#include "Time.h"

namespace blankenhain {
	class Voice {
	public:
		Voice();
		Voice(Time start, unsigned int sampleRate);

		bool isOff() const;
		void play(Time startTime, Time duration, float* output[2]);
	private:
		Time start;
		bool off;
		unsigned int sampleRate;
	};
}

#endif  // VOICE_H_INCLUDED
