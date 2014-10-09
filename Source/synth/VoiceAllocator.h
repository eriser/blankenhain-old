#ifndef VOICEALLOCATOR_H_INCLUDED
#define VOICEALLOCATOR_H_INCLUDED

#include "Note.h"

class VoiceAllocator {
public:
	void play(bh_time time, int start, int samples, int channels, float* const * const buffer);
	Note& addVoice(Note note);

private:
	static const int POLYPHONY = 16;

	int start = 0;
	int size = 0;
	Note voices[POLYPHONY];

	Note& getVoice(int index);
};

#endif  // VOICEALLOCATOR_H_INCLUDED
