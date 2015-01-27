#ifndef PARAMETERS_H_INCLUDED
#define PARAMETERS_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "../synth/Config.h"

enum class ParameterType {
	ATTACK, DECAY, SUSTAIN, RELEASE,
	VOLUME, DETUNE
};

const unsigned int PARAMETERS_PER_ENVELOPE = 4;
const unsigned int PARAMETERS_PER_OSCILLATOR = 2;
const int N_PARAMETERS = 
	PARAMETERS_PER_ENVELOPE * blankenhain::ENVELOPES_PER_CHANNEL
	+ PARAMETERS_PER_OSCILLATOR * blankenhain::OSCILLATORS_PER_CHANNEL
;

#include "../synth/Blankenhain.h"

class Parameters {
public:
	Parameters();

	int getNumParameters() const;
	float getParameter(int index) const;
	float getParameter(ParameterType type, int instance) const;
	void setParameter(int index, float newValue);
	const String getParameterName(int index) const;
	int getParameterIndex(ParameterType type, int instance) const;
	void setSynth(blankenhain::Blankenhain& synth);

private:
	float values[N_PARAMETERS];
	String names[N_PARAMETERS];
	float* synthValues[N_PARAMETERS];
	ParameterType types[N_PARAMETERS];
};

#endif  // PARAMETERS_H_INCLUDED
