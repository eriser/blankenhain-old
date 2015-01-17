#include "Blankenhain.h"

// TODO remove dependency
#include <cmath>

namespace blankenhain {
	Blankenhain::Blankenhain(unsigned int _sampleRate) :
		sampleRate(_sampleRate),
		time(0),
		playing(false)
	{
	}

	const Message* Blankenhain::processBlock(float* outputBuffer[2], unsigned int outSamples, const Message* messages, unsigned int maxMessages) {
		unsigned int outputSamplePosition = 0;
		for (unsigned int i = 0; i < maxMessages; i++) {
			const Message& message = *messages;
			if (playing) {
				for (; outputSamplePosition < message.time; outputSamplePosition++) {
					outputBuffer[0][outputSamplePosition] = sin(440.0 * 2.0 * 3.14 * ((double)outputSamplePosition + time) / sampleRate);
					outputBuffer[1][outputSamplePosition] = outputBuffer[0][outputSamplePosition];
				}
			}

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
			for (; outputSamplePosition < outSamples; outputSamplePosition++) {
				outputBuffer[0][outputSamplePosition] = sin(440.0 * 2.0 * 3.14 * ((double)outputSamplePosition + time) / sampleRate);
				outputBuffer[1][outputSamplePosition] = outputBuffer[0][outputSamplePosition];
			}
		}
		time += outSamples;
		return messages;
	}
}