#include "Instrument.h"

// TODO: remove dependency
#include <cmath>

Instrument::Instrument(VoiceAllocator& _voices) :
voices(_voices)
{
	const float _adsr[4] = { 0, 0, 0, 0 };
	setAdsr(_adsr);
	for (int i = 0; i < MIDI_MAX_NOTE; i++) {
		notes[i] = nullptr;
	}
}

const float* Instrument::getAdsr() const {
	return adsr;
}

void Instrument::setAdsr(const float _adsr[4]) {
	adsr[0] = _adsr[0];
	adsr[1] = _adsr[1];
	adsr[2] = _adsr[2];
	adsr[3] = _adsr[3];
}

void Instrument::setSampleRate(double _sampleRate) {
	sampleRate = _sampleRate;
}

void Instrument::noteOn(bh_time time, int number) {
	notes[number] = &voices.addVoice({ this, number, time, true, 0. });
}

void Instrument::noteOff(bh_time time, int number) {
	notes[number]->releaseLevel = getEnvelope(*notes[number], time);
	notes[number]->triggerTime = time;
	notes[number]->isOn = false;
	notes[number] = nullptr;
}

bool Instrument::play(const Note& note, bh_time time, int start, int samples, int channels, float* const * const buffer) const {
	const double frequency = 440. * pow(2.0, (note.number - 69) / 12.0);
	for (int i = 0; i < samples; i++) {
		const double TAU = 2. * std::acos(-1);
		const bh_time currentTime = time + i;
		const float value = float(std::sin(double(currentTime) / sampleRate * frequency * TAU) * getEnvelope(note, currentTime));
		for (int channel = 0; channel < channels; channel++) {
			buffer[channel][start + i] += value;
		}
	}

	return noteFinished(note, time + samples);
}

double Instrument::getEnvelope(const Note& note, bh_time time) const {
	const double attack = adsr[0];
	const double decay = adsr[1];
	const double sustain = adsr[2];
	const double release = adsr[3];

	const double attackSamples = attack * sampleRate;
	const double decaySamples = decay * sampleRate;
	const double releaseSamples = release * sampleRate;

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

bool Instrument::noteFinished(const Note& note, bh_time time) const {
	const double release = adsr[3];
	const double releaseSamples = release * sampleRate;
	const bh_time timeSinceTrigger = time - note.triggerTime;
	return !note.isOn && timeSinceTrigger > releaseSamples;
}