#include "LFO.h"

namespace blankenhain {
	LFO::LFO(const LFOSettings* settings_) :
		settings(settings_)
	{}

	float LFO::value(Time time, float rateMod, float depthMod) {
		return 0.0;
	}
}