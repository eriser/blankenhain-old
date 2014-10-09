#include "Instrument.h"

// TODO: remove dependency
#include <cmath>

Instrument::Instrument() {
	const double _adsr[4] = { 0, 0, 0, 0 };
	setAdsr(_adsr);
}

void Instrument::setAdsr(const double _adsr[4]) {
	adsr[0] = _adsr[0];
	adsr[1] = _adsr[1];
	adsr[2] = _adsr[2];
	adsr[3] = _adsr[3];
}

void Instrument::setSampleRate(double _sampleRate) {
	sampleRate = _sampleRate;
}

void Instrument::noteOn(bh_time time, int number) {
	triggerTime = time;
	isNoteOn = true;
	frequency = 440. * pow(2.0, (number - 69) / 12.0);
}

void Instrument::noteOff(bh_time time, int number) {
	releaseLevel = getEnvelope(time);
	triggerTime = time;
	isNoteOn = false;
}

double Instrument::getEnvelope(bh_time time) const {
	const double attack = adsr[0];
	const double decay = adsr[1];
	const double sustain = adsr[2];
	const double release = adsr[3];

	const double attackSamples = attack / 1000 * sampleRate;
	const double decaySamples = decay / 1000 * sampleRate;
	const double releaseSamples = release / 1000 * sampleRate;

	const bh_time timeSinceTrigger = time - triggerTime;

	float factor;
	if (isNoteOn) {
		if (timeSinceTrigger < attackSamples) {
			factor = timeSinceTrigger / attackSamples;
		}
		else if (timeSinceTrigger - attackSamples < decaySamples) {
			const double t = (timeSinceTrigger - attackSamples) / decaySamples;
			factor = (1 - t) + sustain * t;
		}
		else {
			factor = sustain;
		}
	}
	else {
		if (timeSinceTrigger < releaseSamples) {
			const double t = timeSinceTrigger / releaseSamples;
			factor = releaseLevel * (1 - t);
		}
		else {
			factor = 0.;
		}
	}

	return factor;
}

void Instrument::play(bh_time time, int start, int samples, int channels, float* const * const buffer) const {
	for (int i = start; i < start + samples; i++) {
		const double TAU = 2. * std::acos(-1);
		const bh_time currentTime = time + i;
		const float value = std::sin(double(currentTime) / sampleRate * frequency * TAU) * getEnvelope(currentTime);
		for (int channel = 0; channel < channels; channel++) {
			buffer[channel][i] = value;
		}
	}
}