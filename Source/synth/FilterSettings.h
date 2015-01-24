#ifndef FILTERSETTINGS_H_INCLUDED
#define FILTERSETTINGS_H_INCLUDED

namespace blankenhain {
	enum class FilterType {
		LOWPASS, HIGHPASS, BANDPASS, NOTCH
	};

	struct FilterSettings {
		FilterSettings() = default;
		FilterSettings(unsigned int sampleRate_, FilterType type_, float frequency_, float Q_) :
			sampleRate(sampleRate_),
			type(type_),
			frequency(frequency_),
			Q(Q_)
		{}

		unsigned int sampleRate;
		FilterType type;
		float frequency;
		float Q;

	};
}

#endif  // FILTERSETTINGS_H_INCLUDED
