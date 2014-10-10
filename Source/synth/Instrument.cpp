#include "Instrument.h"

// TODO: remove dependency
#include <cmath>

Instrument::Instrument(VoiceAllocator& _voices) :
voices(_voices)
{
	for (int i = 0; i < MIDI_MAX_NOTE; i++) {
		notes[i] = nullptr;
	}
}

Envelope& Instrument::getEnvelope1() {
	return envelope1;
}

Envelope& Instrument::getEnvelope2() {
	return envelope2;
}

void Instrument::setSampleRate(double _sampleRate) {
	sampleRate = _sampleRate;
}

void Instrument::noteOn(bh_time time, int number) {
	notes[number] = &voices.addVoice({ this, number, time, true, 0. });
}

void Instrument::noteOff(bh_time time, int number) {
	notes[number]->releaseLevel = envelope1.getValue(*notes[number], time);
	notes[number]->triggerTime = time;
	notes[number]->isOn = false;
	notes[number] = nullptr;
}

bool Instrument::play(const Note& note, bh_time time, int start, int samples, int channels, float* const * const buffer) const {
	const double frequency = 440. * pow(2.0, (note.number - 69) / 12.0);
	for (int i = 0; i < samples; i++) {
		const double TAU = 2. * std::acos(-1);
		const bh_time currentTime = time + i;
		const float value = float(std::sin(double(currentTime) / sampleRate * frequency * TAU) * envelope1.getValue(note, currentTime));
		for (int channel = 0; channel < channels; channel++) {
			buffer[channel][start + i] += value;
		}
	}

	return envelope1.noteFinished(note, time + samples);
}