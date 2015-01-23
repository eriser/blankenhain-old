#include "Channel.h"

namespace blankenhain {
	Channel::Channel(unsigned int sampleRate_, VoiceManager* voiceManager_) :
		sampleRate(sampleRate_),
		voiceManager(voiceManager_)
	{}

	void Channel::play(Time startTime, Time duration, float* output[2]) {
	}

	void Channel::noteOn(const NoteOnMessage& message) {
	}

	void Channel::noteOff(const NoteOffMessage& message) {
	}

	void Channel::parameterChange(const ParameterChangeMessage& message) {
	}
}