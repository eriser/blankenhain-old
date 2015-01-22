#ifndef ENVELOPE_H_INCLUDED
#define ENVELOPE_H_INCLUDED

#include "Time.h"

namespace blankenhain {
	struct Envelope {
		float attackTime;
		float decayTime;
		float sustainLevel;
		float releaseTime;

		Time time = 0;

		float next(float attackMod, float decayMod, float sustainMod, float releaseMod);
	};
}

#endif  // ENVELOPE_H_INCLUDED
