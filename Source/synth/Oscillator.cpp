#include "Oscillator.h"
#include "Config.h"

// TODO remove dependency
#include <cmath>

namespace blankenhain {
	Oscillator::Oscillator(const OscillatorSettings* settings_, unsigned int note) :
		settings(settings_)
	{
		frequency = A_FREQUENCY * pow(2.0, (note - 69) / 12.0) / settings->sampleRate;
	}

	void Oscillator::value(Time time, float output[2]) {
		const float sample = osc.value(settings->type, frequency * time) * 0.5 + 0.5;
		output[0] = sample;
		output[1] = sample;
	}
}