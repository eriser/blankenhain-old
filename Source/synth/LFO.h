#ifndef LFO_H_INCLUDED
#define LFO_H_INCLUDED

#include "Time.h"

namespace blankenhain {
	struct LFO {
		float rate;
		float depth;
		bool synced;

		Time time = 0;
		
		float next(float rateMod, float depthMod);
	};
}

#endif  // LFO_H_INCLUDED
