#ifndef VOICEMANAGER_H_INCLUDED
#define VOICEMANAGER_H_INCLUDED

#include "Voice.h"

namespace blankenhain {
	template<unsigned int N>
	class VoiceManager {
	public:
		VoiceManager(unsigned int sampleRate_) :
			sampleRate(sampleRate_)
		{
			voices[0] = Voice(0, sampleRate);
		}

		void play(Time startTime, Time duration, float* output[2]) {
			for (unsigned int i = 0; i < N; i++) {
				if (!voices[i].isOff()) {
					voices[i].play(startTime, duration, output);
				}
			}
		}

	private:
		Voice voices[N];
		unsigned int sampleRate;
	};
}

#endif  // VOICEMANAGER_H_INCLUDED
