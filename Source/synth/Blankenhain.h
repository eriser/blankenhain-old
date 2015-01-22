#ifndef BLANKENHAIN_H_INCLUDED
#define BLANKENHAIN_H_INCLUDED

#include "Message.h"
#include "VoiceManager.h"
#include "Channel.h"

namespace blankenhain {
	class Blankenhain {
	public:
		Blankenhain(unsigned int sampleRate);

		const Message* processBlock(float* outputBuffer[2], unsigned int outSamples, const Message* messages, unsigned int maxMessages);

	private:
		Time time;
		bool playing;
		VoiceManager<128> voiceManager;
		Channel channel[16];
	};

}

#endif  // BLANKENHAIN_H_INCLUDED
