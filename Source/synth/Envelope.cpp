#include "Envelope.h"

namespace blankenhain {
	Envelope::Envelope(const EnvelopeSettings* settings_) :
		settings(settings_)
	{}

	float Envelope::value(Time time, float attackMod, float decayMod, float sustainMod, float releaseMod) {
		return 0.0;
	}
}