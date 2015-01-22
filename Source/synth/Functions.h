#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

namespace blankenhain {

	template<typename T>
	T min(T a, T b) {
		return (a < b) ? a : b;
	}

	template<typename T>
	T max(T a, T b) {
		return (a < b) ? b : a;
	}

	template<typename T>
	T clamp(T value, T minVal, T maxVal) {
		return min(max(x, minVal), maxVal);
	}

	template<typename T>
	T modulate(T value, T with) {
		return clamp(value + value * with, 0.0, 1.0);
	}

}

#endif  // FUNCTIONS_H_INCLUDED
