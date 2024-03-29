#include "Parameters.h"

using namespace blankenhain;

Parameters::Parameters() :
values{}, synthValues{}
{
	for (int instance = 0; instance < ENVELOPES_PER_CHANNEL; instance++) {
		names[getParameterIndex(ParameterType::ATTACK, instance)] = "Attack" + String(instance + 1);
		names[getParameterIndex(ParameterType::DECAY, instance)] = "Decay" + String(instance + 1);
		names[getParameterIndex(ParameterType::SUSTAIN, instance)] = "Sustain" + String(instance + 1);
		names[getParameterIndex(ParameterType::RELEASE, instance)] = "Release" + String(instance + 1);
		types[getParameterIndex(ParameterType::ATTACK, instance)] = ParameterType::ATTACK;
		types[getParameterIndex(ParameterType::DECAY, instance)] = ParameterType::DECAY;
		types[getParameterIndex(ParameterType::SUSTAIN, instance)] = ParameterType::SUSTAIN;
		types[getParameterIndex(ParameterType::RELEASE, instance)] = ParameterType::RELEASE;
	}
	for (int instance = 0; instance < OSCILLATORS_PER_CHANNEL; instance++) {
		names[getParameterIndex(ParameterType::VOLUME, instance)] = "Volume" + String(instance + 1);
		names[getParameterIndex(ParameterType::DETUNE, instance)] = "Detune" + String(instance + 1);
		types[getParameterIndex(ParameterType::VOLUME, instance)] = ParameterType::VOLUME;
		types[getParameterIndex(ParameterType::DETUNE, instance)] = ParameterType::DETUNE;
	}
	for (int instance = 0; instance < FILTERS_PER_CHANNEL; instance++) {
		names[getParameterIndex(ParameterType::FREQUENCY, instance)] = "Frequency" + String(instance + 1);
		names[getParameterIndex(ParameterType::Q, instance)] = "Q" + String(instance + 1);
		types[getParameterIndex(ParameterType::FREQUENCY, instance)] = ParameterType::FREQUENCY;
		types[getParameterIndex(ParameterType::Q, instance)] = ParameterType::Q;
	}
	for (int instance = 0; instance < LFOS_PER_CHANNEL; instance++) {
		names[getParameterIndex(ParameterType::RATE, instance)] = "Rate" + String(instance + 1);
		names[getParameterIndex(ParameterType::DEPTH, instance)] = "Depth" + String(instance + 1);
		types[getParameterIndex(ParameterType::RATE, instance)] = ParameterType::RATE;
		types[getParameterIndex(ParameterType::DEPTH, instance)] = ParameterType::DEPTH;
	}
}

int Parameters::getNumParameters() const {
	return N_PARAMETERS;
}

float Parameters::getParameter(int index) const {
	return values[index];
}

float Parameters::getParameter(ParameterType type, int instance) const {
	return getParameter(getParameterIndex(type, instance));
}

void Parameters::setParameter(int index, float newValue) {
	values[index] = newValue;
	switch (types[index]) {
	case ParameterType::DETUNE:
		newValue -= 0.5;
		break;
	case ParameterType::FREQUENCY:
		newValue *= 1000;
	}
	*synthValues[index] = newValue;
}

const String Parameters::getParameterName(int index) const {
	return names[index];
}

int Parameters::getParameterIndex(ParameterType type, int instance) const {
	const unsigned int envelope_parameters_offset = 0;
	const unsigned int envelope_offset = envelope_parameters_offset + PARAMETERS_PER_ENVELOPE * instance;
	const unsigned int oscillator_parameters_offset = envelope_parameters_offset + PARAMETERS_PER_ENVELOPE * ENVELOPES_PER_CHANNEL;
	const unsigned int oscillator_offset = oscillator_parameters_offset + PARAMETERS_PER_OSCILLATOR * instance;
	const unsigned int filter_parameters_offset = oscillator_parameters_offset + PARAMETERS_PER_OSCILLATOR * OSCILLATORS_PER_CHANNEL;
	const unsigned int filter_offset = filter_parameters_offset + PARAMETERS_PER_FILTER * instance;
	const unsigned int lfo_parameters_offset = filter_parameters_offset + PARAMETERS_PER_FILTER * FILTERS_PER_CHANNEL;
	const unsigned int lfo_offset = lfo_parameters_offset + PARAMETERS_PER_LFO * instance;
	switch (type) {
	case ParameterType::ATTACK:
		return envelope_offset + 0;
	case ParameterType::DECAY:
		return envelope_offset + 1;
	case ParameterType::SUSTAIN:
		return envelope_offset + 2;
	case ParameterType::RELEASE:
		return envelope_offset + 3;
	case ParameterType::VOLUME:
		return oscillator_offset + 0;
	case ParameterType::DETUNE:
		return oscillator_offset + 1;
	case ParameterType::FREQUENCY:
		return filter_offset + 0;
	case ParameterType::Q:
		return filter_offset + 1;
	case ParameterType::RATE:
		return lfo_offset + 0;
	case ParameterType::DEPTH:
		return lfo_offset + 1;
	default:
		return -1;
	}
}

void Parameters::setSynth(Blankenhain& synth) {
	EnvelopeSettings* envelopeSettings = synth.channels[0].envelopes;
	for (int instance = 0; instance < ENVELOPES_PER_CHANNEL; instance++) {
		synthValues[getParameterIndex(ParameterType::ATTACK, instance)] = &envelopeSettings[instance].attackTime;
		synthValues[getParameterIndex(ParameterType::DECAY, instance)] = &envelopeSettings[instance].decayTime;
		synthValues[getParameterIndex(ParameterType::SUSTAIN, instance)] = &envelopeSettings[instance].sustainLevel;
		synthValues[getParameterIndex(ParameterType::RELEASE, instance)] = &envelopeSettings[instance].releaseTime;
	}
	OscillatorSettings* oscillatorSettings = synth.channels[0].oscillators;
	for (int instance = 0; instance < OSCILLATORS_PER_CHANNEL; instance++) {
		synthValues[getParameterIndex(ParameterType::VOLUME, instance)] = &oscillatorSettings[instance].volume;
		synthValues[getParameterIndex(ParameterType::DETUNE, instance)] = &oscillatorSettings[instance].detune;
	}
	FilterSettings* filterSettings = synth.channels[0].filters;
	for (int instance = 0; instance < FILTERS_PER_CHANNEL; instance++) {
		synthValues[getParameterIndex(ParameterType::FREQUENCY, instance)] = &filterSettings[instance].frequency;
		synthValues[getParameterIndex(ParameterType::Q, instance)] = &filterSettings[instance].Q;
	}
	LFOSettings* lfoSettings = synth.channels[0].lfos;
	for (int instance = 0; instance < LFOS_PER_CHANNEL; instance++) {
		synthValues[getParameterIndex(ParameterType::RATE, instance)] = &lfoSettings[instance].rate;
		synthValues[getParameterIndex(ParameterType::DEPTH, instance)] = &lfoSettings[instance].depth;
	}
}