#ifndef LFO_H_INCLUDED
#define LFO_H_INCLUDED

#include "Time.h"
#include "Note.h"

class LFO {
public:
	double getValue(const Note& note, double time) const;
};

#endif  // LFO_H_INCLUDED
