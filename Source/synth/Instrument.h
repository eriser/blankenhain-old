#ifndef INSTRUMENT_H_INCLUDED
#define INSTRUMENT_H_INCLUDED

#include "Time.h"
#include "VoiceAllocator.h"
#include "Envelope.h"
#include "LFO.h"

class Instrument {
public:
	Instrument(VoiceAllocator& voices);

	Envelope& getEnvelope1();
	Envelope& getEnvelope2();

	void setSampleRate(double sampleRate);
	void noteOn(bh_time time, int number);
	void noteOff(bh_time time, int number);

	bool play(const Note& note, bh_time time, int start, int samples, int channels, float* const * const buffer) const;

private:
	static const int MIDI_MAX_NOTE = 128;

	double sampleRate = 0;
	VoiceAllocator& voices;
	Note* notes[MIDI_MAX_NOTE];
	Envelope envelope1, envelope2;
	LFO lfo1;
};

#endif  // INSTRUMENT_H_INCLUDED
