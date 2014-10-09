#ifndef INSTRUMENT_H_INCLUDED
#define INSTRUMENT_H_INCLUDED

#include "Time.h"

class Instrument {
public:
	Instrument();

	void setAdsr(const double adsr[4]);
	void setSampleRate(double sampleRate);
	void noteOn(bh_time time, int number);
	void noteOff(bh_time time, int number);

	double getEnvelope(bh_time time) const;
	void play(bh_time time, int start, int samples, int channels, float* const * const buffer) const;

private:
	double adsr[4];
	bh_time triggerTime = 0;
	bool isNoteOn = false;
	double releaseLevel = 0;
	double frequency = 0;
	double sampleRate = 0;
};

#endif  // INSTRUMENT_H_INCLUDED
