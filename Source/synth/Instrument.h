#ifndef INSTRUMENT_H_INCLUDED
#define INSTRUMENT_H_INCLUDED

#include "Time.h"
#include "VoiceAllocator.h"

class Instrument {
public:
	Instrument(VoiceAllocator& voices);

	void setAdsr(const double adsr[4]);
	void setSampleRate(double sampleRate);
	void noteOn(bh_time time, int number);
	void noteOff(bh_time time, int number);
	void play(const Note& note, bh_time time, int start, int samples, int channels, float* const * const buffer) const;

private:
	static const int MIDI_MAX_NOTE = 128;

	double adsr[4];
	double sampleRate = 0;
	VoiceAllocator& voices;
	Note* notes[MIDI_MAX_NOTE];

	double getEnvelope(const Note& note, bh_time time) const;
};

#endif  // INSTRUMENT_H_INCLUDED
