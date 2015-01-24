#ifndef ENVELOPE_H_INCLUDED
#define ENVELOPE_H_INCLUDED

#include "Time.h"
#include "EnvelopeSettings.h"

namespace blankenhain {
	struct Envelope {
		Envelope() = default;
		Envelope(const EnvelopeSettings* settings, Time start);

		float value(Time time, float attackMod, float decayMod, float sustainMod, float releaseMod);
		void noteOff(Time time);

		const EnvelopeSettings* settings;
		bool noteOn;
		Time triggerTime;
		float releaseLevel;
	};
}

#endif  // ENVELOPE_H_INCLUDED
