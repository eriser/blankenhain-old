#ifndef LFO_H_INCLUDED
#define LFO_H_INCLUDED

#include "Time.h"
#include "LFOSettings.h"

namespace blankenhain {
	struct LFO {
		LFO() = default;
		LFO(const LFOSettings* settings);
		
		float value(Time time, float rateMod, float depthMod);

		const LFOSettings* settings;
	};
}

#endif  // LFO_H_INCLUDED
