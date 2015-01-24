#ifndef OSCILLATORSETTINGS_H_INCLUDED
#define OSCILLATORSETTINGS_H_INCLUDED

namespace blankenhain {
	enum class OscillatorType {
		SINE, SQUARE, SAW, NOISE
	};

	struct OscillatorSettings {
		OscillatorSettings() = default;
		OscillatorSettings(OscillatorType type_, unsigned int sampleRate_) :
			type(type_),
			sampleRate(sampleRate_)
		{}

		OscillatorType type;
		unsigned int sampleRate;
	};
}

#endif  // OSCILLATORSETTINGS_H_INCLUDED
