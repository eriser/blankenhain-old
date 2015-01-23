#ifndef VOICEMANAGER_H_INCLUDED
#define VOICEMANAGER_H_INCLUDED

#include "Voice.h"
#include "Config.h"

namespace blankenhain {
	class VoiceManager {
	public:
		VoiceManager(unsigned int sampleRate_) :
			sampleRate(sampleRate_)
		{
		}

		void play(Time startTime, Time duration, float* output[2]) {
			for (unsigned int i = 0; i < POLYPHONY; i++) {
				if (voices[i].noteOn) {
					voices[i].play(startTime, duration, output);
				}
			}
		}

	private:
		Voice voices[POLYPHONY];
		unsigned int sampleRate;
	};
}

#endif  // VOICEMANAGER_H_INCLUDED
