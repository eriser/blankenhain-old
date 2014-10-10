#ifndef ENVELOPE_H_INCLUDED
#define ENVELOPE_H_INCLUDED

#include "Time.h"
#include "Note.h"

class Envelope {
public:
	void setAttack(double attack);
	void setDecay(double decay);
	void setSustain(double sustain);
	void setRelease(double release);

	double getAttack() const;
	double getDecay() const;
	double getSustain() const;
	double getRelease() const;
	double getValue(const Note& note, bh_time time) const;
	bool noteFinished(const Note& note, bh_time time) const;

private:
	double attack = 0, decay = 0, sustain = 0, release = 0;
};

#endif  // ENVELOPE_H_INCLUDED
