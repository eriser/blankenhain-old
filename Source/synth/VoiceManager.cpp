#include "VoiceManager.h"

namespace blankenhain {
	Voice& VoiceManager::getFreeVoice(Channel* channel, unsigned int note) {
		// try finding an inactive voice
		for (unsigned int i = 0; i < POLYPHONY; i++) {
			Voice& voice = voices[i];
			if (!voice.active) {
				return voice;
			}
		}
		
		// all voices are active, so we don't check voice.active from now on

		// try finding a voice playing the same note on the same channel
		for (unsigned int i = 0; i < POLYPHONY; i++) {
			Voice& voice = voices[i];
			// actually if there were a note on the same channel which is on, this would lead to 'lost' notes
			// TODO
			if (!voice.noteOn && voice.note == note && voice.channel == channel) {
				return voice;
			}
		}

		// kill oldest note which is off
		Time earliestTime = 0;
		Voice* oldestVoice = nullptr;
		for (unsigned int i = 0; i < POLYPHONY; i++) {
			Voice& voice = voices[i];
			if (!voice.noteOn && voice.start <= earliestTime) {
				oldestVoice = &voice;
			}
		}
		if (oldestVoice != nullptr) {
			return *oldestVoice;
		}

		// fuck it, just kill the oldest note
		for (unsigned int i = 0; i < POLYPHONY; i++) {
			Voice& voice = voices[i];
			if (voice.start <= earliestTime) {
				oldestVoice = &voice;
			}
		}
		return *oldestVoice;
	}

	void VoiceManager::playAll(Channel* channel, Time startTime, Time duration, float* output[2]) {
		for (unsigned int i = 0; i < POLYPHONY; i++) {
			Voice& voice = voices[i];
			if (voice.active && voice.channel == channel) {
				voice.play(startTime, duration, output);
			}
		}
	}

	Voice* VoiceManager::findVoice(Channel* channel, unsigned int note) {
		for (unsigned int i = 0; i < POLYPHONY; i++) {
			Voice& voice = voices[i];
			if (voice.active && voice.channel == channel && voice.note == note && voice.noteOn) {
				return &voice;
			}
		}
		return nullptr;
	}
}