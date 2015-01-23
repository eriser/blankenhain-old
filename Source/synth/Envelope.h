#ifndef ENVELOPE_H_INCLUDED
#define ENVELOPE_H_INCLUDED

#include "Time.h"
#include "EnvelopeSettings.h"

namespace blankenhain {
	struct Envelope {
		Envelope() = default;
		Envelope(const EnvelopeSettings* settings);

		float value(Time time, float attackMod, float decayMod, float sustainMod, float releaseMod);

		const EnvelopeSettings* settings;
	};
}

#endif  // ENVELOPE_H_INCLUDED
