#include "LFO.h"

namespace blankenhain {
	LFO::LFO(const LFOSettings* settings_, Time start_) :
		settings(settings_),
		triggerTime(start_)
	{}

	float LFO::value(Time time, float rateMod, float depthMod) {
		// TODO
		(void)rateMod;
		(void)depthMod;

		// TODO sclaing
		float x = 5.f * settings->rate / settings->sampleRate;
		if (settings->synced) {
			x *= time - triggerTime;
		}
		else {
			x *= time;
		}
		return settings->depth * osc.value(settings->type, x);
	}
}