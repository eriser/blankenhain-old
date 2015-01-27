#ifndef CONFIG_H_INCLUDED
#define CONFIG_H_INCLUDED

namespace blankenhain {
	const unsigned int CHANNELS = 1;
	const unsigned int OSCILLATORS_PER_CHANNEL = 1;
	const unsigned int ENVELOPES_PER_CHANNEL = 2;
	const unsigned int LFOS_PER_CHANNEL = 3;
	const unsigned int FILTERS_PER_CHANNEL = 3;
	const unsigned int POLYPHONY = 16;
	const float A_FREQUENCY = 440;
	const unsigned int MODULATION_MATRIX_ENTRIES = 8;
}
#endif  // CONFIG_H_INCLUDED
