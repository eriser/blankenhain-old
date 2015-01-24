#include "LFO.h"

namespace blankenhain {
	LFO::LFO(const LFOSettings* settings_, Time start_) :
		settings(settings_),
		triggerTime(start_)
	{}

	float LFO::value(Time time, float rateMod, float depthMod) {
		float x = settings->rate;
		if (settings->synced) {
			x *= time - triggerTime;
		}
		else {
			x *= time;
		}
		return settings->depth * osc.value(settings->type, x);
	}
}