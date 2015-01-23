#ifndef FILTER_H_INCLUDED
#define FILTER_H_INCLUDED

#include "FilterSettings.h"

namespace blankenhain {
	struct Filter {
		Filter() = default;
		Filter(const FilterSettings* settings);

		void process(float sample[2]);

		const FilterSettings* settings;
	};
}

#endif  // FILTER_H_INCLUDED
