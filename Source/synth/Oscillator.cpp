#include "Oscillator.h"
#include "Config.h"

// TODO remove dependency
#include <cmath>

namespace blankenhain {
	Oscillator::Oscillator(const OscillatorSettings* settings_, unsigned int note_) :
		settings(settings_),
		note(static_cast<int>(note_))
	{}

	void Oscillator::value(Time time, float output[2]) {
		const float frequency = A_FREQUENCY * exp2((static_cast<int>(note)-69 + (settings->detune * 12)) / 12.0f) / settings->sampleRate;
		const float sample = osc.value(settings->type, frequency * time) * 0.5f + 0.5f;
		output[0] = sample;
		output[1] = sample;
	}
}