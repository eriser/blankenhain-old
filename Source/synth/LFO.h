#ifndef LFO_H_INCLUDED
#define LFO_H_INCLUDED

#include "Time.h"
#include "LFOSettings.h"
#include "OscillatorFunction.h"

namespace blankenhain {
	struct LFO {
		LFO() = default;
		LFO(const LFOSettings* settings, Time start);
		
		float value(Time time, float rateMod, float depthMod);

		const LFOSettings* settings;
		Time triggerTime;
		OscillatorFunction osc;
	};
}

#endif  // LFO_H_INCLUDED
