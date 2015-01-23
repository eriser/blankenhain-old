#ifndef ENVELOPESETTINGS_H_INCLUDED
#define ENVELOPESETTINGS_H_INCLUDED

namespace blankenhain {
	struct EnvelopeSettings {
		EnvelopeSettings(
			float attackTime_,
			float decayTime_,
			float sustainLevel_,
			float releaseTime_
			) :
			attackTime(attackTime_),
			decayTime(decayTime_),
			sustainLevel(sustainLevel_),
			releaseTime(releaseTime_)
		{}
		EnvelopeSettings() {}

		float attackTime;
		float decayTime;
		float sustainLevel;
		float releaseTime;
	};
}

#endif  // ENVELOPESETTINGS_H_INCLUDED
