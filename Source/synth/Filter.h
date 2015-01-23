#ifndef FILTER_H_INCLUDED
#define FILTER_H_INCLUDED

#include "FilterSettings.h"

namespace blankenhain {
	struct Filter {
		Filter(const FilterSettings& settings);

		const FilterSettings& settings;
	};
}

#endif  // FILTER_H_INCLUDED
