#ifndef MODULATIONMATRIX_H_INCLUDED
#define MODULATIONMATRIX_H_INCLUDED

#include "Config.h"

namespace blankenhain {
	enum class ModulationSource {
		ENVELOPE, LFO, VELOCITY
	};

	enum class ModulationTarget {
		VOLUME, DETUNE, FILTER_CUTOFF, FILTER_Q, MODULATION_SCALE
	};

	struct Modulation {
		ModulationSource source;
		ModulationTarget target;
		float scale;
		unsigned int sourceIndex;
		unsigned int targetIndex;
		bool active = false;
	};

	struct ModulationMatrix {
		ModulationMatrix() {}
		Modulation entries[MODULATION_MATRIX_ENTRIES];
	};
}

#endif  // MODULATIONMATRIX_H_INCLUDED
