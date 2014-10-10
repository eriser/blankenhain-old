#include "Envelope.h"

void Envelope::setAttack(double _attack) {
	attack = _attack;
}

void Envelope::setDecay(double _decay) {
	decay = _decay;
}

void Envelope::setSustain(double _sustain) {
	sustain = _sustain;
}

void Envelope::setRelease(double _release) {
	release = _release;
}


double Envelope::getAttack() const {
	return attack;
}

double Envelope::getDecay() const {
	return decay;
}

double Envelope::getSustain() const {
	return sustain;
}

double Envelope::getRelease() const {
	return release;
}

double Envelope::getValue(const Note& note, bh_time time) const {
	const double attackSamples = attack;
	const double decaySamples = decay;
	const double releaseSamples = release;

	const bh_time timeSinceTrigger = time - note.triggerTime;
	if (note.isOn) {
		if (timeSinceTrigger <= attackSamples && attackSamples > 0) {
			return timeSinceTrigger / attackSamples;
		}
		else if (timeSinceTrigger - attackSamples - 1 <= decaySamples && decaySamples > 0) {
			const double t = (timeSinceTrigger - attackSamples - 1) / decaySamples;
			return (1 - t) + sustain * t;
		}
		else {
			return sustain;
		}
	}
	else {
		if (!noteFinished(note, time) && releaseSamples > 0) {
			const double t = timeSinceTrigger / releaseSamples;
			return note.releaseLevel * (1 - t);
		}
		else {
			return 0.;
		}
	}
}

bool Envelope::noteFinished(const Note& note, bh_time time) const {
	const double releaseSamples = release;
	const bh_time timeSinceTrigger = time - note.triggerTime;
	return !note.isOn && timeSinceTrigger > releaseSamples;
}