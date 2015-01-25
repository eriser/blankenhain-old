#include "Envelope.h"

namespace blankenhain {
	Envelope::Envelope(const EnvelopeSettings* settings_, Time start) :
		settings(settings_),
		noteOn(true),
		triggerTime(start),
		releaseLevel(0.0)
	{}

	float Envelope::value(Time time, float attackMod, float decayMod, float sustainMod, float releaseMod) {
		// TODO
		(void)attackMod;
		(void)decayMod;
		(void)sustainMod;
		(void)releaseMod;

		const Time timeSinceTrigger = triggerTime - time;
		const unsigned int sampleRate = settings->sampleRate;
		const Time attackSamples = static_cast<Time>(settings->attackTime * sampleRate);
		const Time decaySamples = static_cast<Time>(settings->decayTime * sampleRate);
		const float sustain = settings->sustainLevel;
		const Time releaseSamples = static_cast<Time>(settings->releaseTime * sampleRate);
		if (noteOn) {
			if (timeSinceTrigger <= attackSamples && attackSamples > 0) {
				releaseLevel = static_cast<float>(timeSinceTrigger) / attackSamples;
			}
			else if (timeSinceTrigger - attackSamples <= decaySamples && decaySamples > 0) {
				const float t = static_cast<float>(timeSinceTrigger - attackSamples) / decaySamples;
				releaseLevel = (1 - t) + sustain * t;
			}
			else {
				releaseLevel = sustain;
			}
			return releaseLevel;
		}
		else {
			if (releaseSamples > 0) {
				const float t = static_cast<float>(timeSinceTrigger) / releaseSamples;
				return releaseLevel * (1 - t);
			}
			else {
				return 0.;
			}
		}
	}

	void Envelope::noteOff(Time time) {
		triggerTime = time;
		noteOn = false;
	}
}