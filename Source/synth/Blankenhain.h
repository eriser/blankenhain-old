#ifndef BLANKENHAIN_H_INCLUDED
#define BLANKENHAIN_H_INCLUDED

#include "Message.h"
#include "VoiceManager.h"
#include "Channel.h"

namespace blankenhain {
	struct Blankenhain {
		Blankenhain(unsigned int sampleRate);

		const Message* processBlock(float* outputBuffer[2], unsigned int outSamples, const Message* messages, unsigned int maxMessages);

		Time time;
		VoiceManager voiceManager;
		Channel channels[CHANNELS];
	};

}

#endif  // BLANKENHAIN_H_INCLUDED
