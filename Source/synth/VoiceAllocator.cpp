#include "VoiceAllocator.h"

#include "Instrument.h"

void VoiceAllocator::play(bh_time time, int start, int samples, int channels, float* const * const buffer) {
	int deleted = 0;
	for (int i = 0; i < size; i++) {
		Note& note = getVoice(i);
		if (note.instrument->play(note, time, start, samples, channels, buffer)) {
			note = getVoice(deleted++);
		}
	}
	start += deleted;
}

Note& VoiceAllocator::addVoice(Note _note) {
	Note& note = getVoice(size);
	note = _note;
	if (size < POLYPHONY) {
		size++;
	}
	else {
		start++;
	}
	return note;
}


Note& VoiceAllocator::getVoice(int index) {
	return voices[(start + index) % POLYPHONY];
}