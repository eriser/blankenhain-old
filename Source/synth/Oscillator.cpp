#include "Oscillator.h"
#include "Config.h"

// TODO remove dependency
#include <cmath>

#include "Functions.h"

namespace blankenhain {
	Oscillator::Oscillator(const OscillatorSettings* settings_, unsigned int note_) :
		settings(settings_),
		note(static_cast<int>(note_))
	{}

	void Oscillator::value(Time time, float output[2], float volumeMod, float detuneMod) {
		const float detune = clamp(settings->detune + detuneMod, -.5f, .5f);
		const float volume = clamp(settings->volume + volumeMod, 0.f, 1.f);
		const float frequency = A_FREQUENCY * exp2((static_cast<int>(note)-69 + (detune * 12) + settings->pitch) / 12.0f) / settings->sampleRate;
		const float sample = osc.value(settings->type, frequency * time) * 0.5f + 0.5f;
		output[0] += sample * volume;
		output[1] += sample * volume;
	}
}