#include "Channel.h"

namespace blankenhain {
	Channel::Channel(unsigned int sampleRate_, VoiceManager* voiceManager_) :
		sampleRate(sampleRate_),
		voiceManager(voiceManager_)
	{}

	void Channel::play(Time startTime, Time duration, float* output[2]) {
		const unsigned int blocks = duration / BLOCKSIZE;
		float* outputLocal[2] = { output[0], output[1] };
		for (unsigned int j = 0; j < blocks; j++) {
			playBlock(startTime, BLOCKSIZE, outputLocal);
			startTime += BLOCKSIZE;
			outputLocal[0] += BLOCKSIZE;
			outputLocal[1] += BLOCKSIZE;
		}
		playBlock(startTime, duration - blocks * BLOCKSIZE, outputLocal);
	}

	void Channel::playBlock(Time startTime, Time duration, float* output[2]) {
		float leftBuffer[BLOCKSIZE]{};
		float rightBuffer[BLOCKSIZE]{};
		float* channelBuffer[2] = { leftBuffer, rightBuffer };
		voiceManager->playAll(this, startTime, duration, channelBuffer);

		// this would be a good place for some channel effects

		for (unsigned int i = 0; i < duration; i++) {
			output[0][i] = leftBuffer[i];
			output[1][i] = rightBuffer[i];
		}
	}

	void Channel::noteOn(Time time, const NoteOnMessage& message) {
		Voice& voice = voiceManager->getFreeVoice(this, message.number);
		voice = Voice(time, this, message.number);
	}

	void Channel::noteOff(Time time, const NoteOffMessage& message) {
		Voice* voice = voiceManager->findVoice(this, message.number);
		if (voice != nullptr) {
			voice->noteOff(time);
		}
	}

	void Channel::parameterChange(const ParameterChangeMessage& message) {
		// TODO
		(void)message;
	}
}