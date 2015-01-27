#include "Parameters.h"

Parameters::Parameters() :
values{}
{
	for (int instance = 0; instance < blankenhain::ENVELOPES_PER_CHANNEL; instance++) {
		names[getParameterIndex(ParameterType::ATTACK, instance)] = "Attack" + String(instance + 1);
		names[getParameterIndex(ParameterType::DECAY, instance)] = "Decay" + String(instance + 1);
		names[getParameterIndex(ParameterType::SUSTAIN, instance)] = "Sustain" + String(instance + 1);
		names[getParameterIndex(ParameterType::RELEASE, instance)] = "Release" + String(instance + 1);
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
	// TODO set parameter in synth somehow
}

const String Parameters::getParameterName(int index) const {
	return names[index];
}

int Parameters::getParameterIndex(ParameterType type, int instance) const {
	const unsigned int envelope_parameters_offset = 0;
	const unsigned int parameters_per_envelope = 4;
	const unsigned int envelope_offset = envelope_parameters_offset + parameters_per_envelope * instance;
	switch (type) {
	case ParameterType::ATTACK:
		return envelope_offset + 0;
	case ParameterType::DECAY:
		return envelope_offset + 1;
	case ParameterType::SUSTAIN:
		return envelope_offset + 2;
	case ParameterType::RELEASE:
		return envelope_offset + 3;

	}
}