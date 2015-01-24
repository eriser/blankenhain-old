#ifndef OSCILLATORSETTINGS_H_INCLUDED
#define OSCILLATORSETTINGS_H_INCLUDED

namespace blankenhain {
	enum class OscillatorType {
		SINE, SQUARE, SAW, NOISE
	};

	struct OscillatorSettings {
		OscillatorSettings() = default;
		OscillatorSettings(unsigned int sampleRate_, OscillatorType type_) :
			sampleRate(sampleRate_),
			type(type_)
		{}

		unsigned int sampleRate;
		OscillatorType type;
	};
}

#endif  // OSCILLATORSETTINGS_H_INCLUDED
