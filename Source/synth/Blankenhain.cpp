#include "Blankenhain.h"

namespace blankenhain {
	Blankenhain::Blankenhain(unsigned int _sampleRate) :
		time(0),
		playing(false),
		voiceManager(_sampleRate)
	{
	}

	const Message* Blankenhain::processBlock(float* outputBuffer[2], unsigned int outSamples, const Message* messages, unsigned int maxMessages) {
		unsigned int outputSamplePosition = 0;
		for (unsigned int i = 0; i < maxMessages; i++) {
			const Message& message = *messages;
			if (playing) {
				voiceManager.play(time + outputSamplePosition, message.time - outputSamplePosition, outputBuffer);
			}
			outputBuffer[0] += message.time - outputSamplePosition;
			outputBuffer[1] += message.time - outputSamplePosition;
			outputSamplePosition = message.time;

			switch (message.type) {
			case MessageType::NOTE_ON:
				playing = true;
				break;
			case MessageType::NOTE_OFF:
				playing = false;
				break;
			case MessageType::PARAMETER_CHANGE:
				break;
			}
			messages++;
		}
		if (playing) {
			voiceManager.play(time + outputSamplePosition, outSamples - outputSamplePosition, outputBuffer);
		}
		time += outSamples;
		return messages;
	}
}