#ifndef LFOSETTINGS_H_INCLUDED
#define LFOSETTINGS_H_INCLUDED

namespace blankenhain {
	struct LFOSettings {
		LFOSettings(float rate_, float depth_, bool synced_) :
			rate(rate_),
			depth(depth_),
			synced(synced_)
		{}

		LFOSettings() {}

		float rate;
		float depth;
		bool synced;
	};
}

#endif  // LFOSETTINGS_H_INCLUDED
