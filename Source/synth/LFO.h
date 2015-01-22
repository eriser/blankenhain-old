#ifndef LFO_H_INCLUDED
#define LFO_H_INCLUDED

#include "Time.h"

namespace blankenhain {
	struct LFO {
		float rate;
		float depth;
		bool synced;
		
		float value(Time time, float rateMod, float depthMod);
	};
}

#endif  // LFO_H_INCLUDED
