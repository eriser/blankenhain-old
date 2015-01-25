#include "Channel.h"

namespace blankenhain {
	Channel::Channel(unsigned int sampleRate_, VoiceManager* voiceManager_) :
		sampleRate(sampleRate_),
		voiceManager(voiceManager_)
	{}

	void Channel::play(Time startTime, Time duration, float* output[2]) {
		for (unsigned int i = 0; i < duration; i++) {
			output[0][i] = 0;
			output[1][i] = 0;
		}
		voiceManager->playAll(this, startTime, duration, output);

		// this would be a good place for some channel effects
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