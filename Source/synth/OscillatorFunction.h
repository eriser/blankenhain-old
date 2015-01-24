#ifndef OSCILLATORFUNCTION_H_INCLUDED
#define OSCILLATORFUNCTION_H_INCLUDED

#include "OscillatorType.h"

namespace blankenhain {
	struct OscillatorFunction {
		float value(OscillatorType type, float x);
		float rand();

		unsigned int randomValue = 0;
	};
}

#endif  // OSCILLATORFUNCTION_H_INCLUDED
