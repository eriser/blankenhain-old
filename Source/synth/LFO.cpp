#include "LFO.h"

// TODO: remove dependency
#include <cmath>

double LFO::getValue(const Note& note, double time) const {
	const double TAU = 2. * std::acos(-1);
	return std::sin(double(time) * 2 * TAU) * .1;
}