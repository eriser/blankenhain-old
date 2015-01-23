#ifndef VOICEMANAGER_H_INCLUDED
#define VOICEMANAGER_H_INCLUDED

#include "Voice.h"
#include "Config.h"

namespace blankenhain {
	struct VoiceManager {
		Voice& getFreeVoice(Channel* channel, unsigned int note);
		void playAll(Channel* channel, Time startTime, Time duration, float* output[2]);
		Voice* findVoice(Channel* channel, unsigned int note);

		Voice voices[POLYPHONY];
	};
}

#endif  // VOICEMANAGER_H_INCLUDED
