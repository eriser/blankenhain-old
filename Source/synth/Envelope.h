#ifndef ENVELOPE_H_INCLUDED
#define ENVELOPE_H_INCLUDED

#include "Time.h"

namespace blankenhain {
	struct Envelope {
		float attackTime;
		float decayTime;
		float sustainLevel;
		float releaseTime;

		float value(Time time, float attackMod, float decayMod, float sustainMod, float releaseMod);
	};
}

#endif  // ENVELOPE_H_INCLUDED
