#include "Envelope.h"

namespace blankenhain {
	Envelope::Envelope(const EnvelopeSettings* settings_, Time start) :
		settings(settings_),
		noteOn(true),
		triggerTime(start),
		releaseLevel(0.0)
	{}

	float Envelope::value(Time time, float attackMod, float decayMod, float sustainMod, float releaseMod) {
		const Time timeSinceTrigger = triggerTime - time;
		const unsigned int sampleRate = settings->sampleRate;
		const Time attackSamples = settings->attackTime * sampleRate;
		const Time decaySamples = settings->decayTime * sampleRate;
		const Time sustain = settings->sustainLevel * sampleRate;
		const Time releaseSamples = settings->releaseTime * sampleRate;
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