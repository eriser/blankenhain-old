#ifndef NOTE_H_INCLUDED
#define NOTE_H_INCLUDED

#include "Time.h"

class Instrument;

struct Note {
	Instrument* instrument;
	int number;
	bh_time triggerTime;
	bool isOn;
	double releaseLevel;
};

#endif  // NOTE_H_INCLUDED
