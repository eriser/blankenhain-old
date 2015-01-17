#ifndef BLANKENHAIN_H_INCLUDED
#define BLANKENHAIN_H_INCLUDED

#include "Message.h"

namespace blankenhain {
	class Blankenhain {
	public:
		Blankenhain(unsigned int sampleRate);

		const Message* processBlock(float* outputBuffer[2], unsigned int outSamples, const Message* messages, unsigned int maxMessages);

	private:
		unsigned int sampleRate;
		Time time;
		bool playing;
	};

}

#endif  // BLANKENHAIN_H_INCLUDED
