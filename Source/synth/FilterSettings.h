#ifndef FILTERSETTINGS_H_INCLUDED
#define FILTERSETTINGS_H_INCLUDED

namespace blankenhain {
	enum class FilterType {
		LOWPASS, HIGHPASS, BANDPASS, NOTCH
	};

	struct FilterSettings {
		FilterSettings() = default;
		FilterSettings(unsigned int sampleRate_, FilterType type_, float frequency_, float Q_, bool active_) :
			sampleRate(sampleRate_),
			type(type_),
			frequency(frequency_),
			Q(Q_),
			active(active_)
		{}

		unsigned int sampleRate;
		FilterType type;
		float frequency;
		float Q;
		bool active = false;
	};
}

#endif  // FILTERSETTINGS_H_INCLUDED
