#ifndef FILTER_H_INCLUDED
#define FILTER_H_INCLUDED

#include "FilterSettings.h"

namespace blankenhain {
	struct Filter {
		Filter() = default;
		Filter(const FilterSettings* settings);

		void process(float sample[2], float frequencyMod, float qMod);

		const FilterSettings* settings;

		float x_1[2];
		float y_1[2], y_2[2];
	};
}

#endif  // FILTER_H_INCLUDED
