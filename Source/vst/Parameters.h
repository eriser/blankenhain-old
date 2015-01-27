#ifndef PARAMETERS_H_INCLUDED
#define PARAMETERS_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "../synth/Config.h"

enum class ParameterType {
	ATTACK, DECAY, SUSTAIN, RELEASE
};

const int N_PARAMETERS = 
	4 * blankenhain::ENVELOPES_PER_CHANNEL
;

class Parameters {
public:
	Parameters();

	int getNumParameters() const;
	float getParameter(int index) const;
	float getParameter(ParameterType type, int instance) const;
	void setParameter(int index, float newValue);
	const String getParameterName(int index) const;
	int getParameterIndex(ParameterType type, int instance) const;

private:
	float values[N_PARAMETERS];
	String names[N_PARAMETERS];
};

#endif  // PARAMETERS_H_INCLUDED
