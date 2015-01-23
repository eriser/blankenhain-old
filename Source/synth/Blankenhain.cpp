#include "Blankenhain.h"

namespace blankenhain {
	Blankenhain::Blankenhain(unsigned int sampleRate_) :
		time(0)
	{
		for (unsigned int i = 0; i < CHANNELS; i++) {
			channels[i] = Channel(sampleRate_, &voiceManager);
		}
	}

	const Message* Blankenhain::processBlock(float* outputBuffer[2], unsigned int outSamples, const Message* messages, unsigned int maxMessages) {
		unsigned int outputSamplePosition = 0;
		for (unsigned int i = 0; i < maxMessages; i++) {
			const Message& message = *messages;
			for (unsigned int channel = 0; channel < CHANNELS; channel++) {
				channels[channel].play(time + outputSamplePosition, message.time - outputSamplePosition, outputBuffer);
			}
			outputBuffer[0] += message.time - outputSamplePosition;
			outputBuffer[1] += message.time - outputSamplePosition;
			outputSamplePosition = static_cast<unsigned int>(message.time);

			switch (message.type) {
			case MessageType::NOTE_ON:
				channels[message.channel].noteOn(time + message.time, message.noteOn);
				break;
			case MessageType::NOTE_OFF:
				channels[message.channel].noteOff(message.noteOff);
				break;
			case MessageType::PARAMETER_CHANGE:
				channels[message.channel].parameterChange(message.parameterChange);
				break;
			}
			messages++;
		}
		for (unsigned int channel = 0; channel < CHANNELS; channel++) {
			channels[channel].play(time + outputSamplePosition, outSamples - outputSamplePosition, outputBuffer);
		}
		time += outSamples;
		return messages;
	}
}