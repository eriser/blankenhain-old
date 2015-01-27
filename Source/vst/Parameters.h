#ifndef PARAMETERS_H_INCLUDED
#define PARAMETERS_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

class Parameters {
public:
	int getNumParameters();
	float getParameter(int index);
	void setParameter(int index, float newValue);
	const String getParameterName(int index);
};

#endif  // PARAMETERS_H_INCLUDED
