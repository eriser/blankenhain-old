#ifndef VOICE_H_INCLUDED
#define VOICE_H_INCLUDED

#include "Time.h"
#include "Config.h"
#include "Oscillator.h"
#include "LFO.h"
#include "Envelope.h"
#include "Filter.h"


namespace blankenhain {
	struct Channel;

	struct Voice {
		Voice();
		Voice(
			Time start,
			const Channel* channel,
			unsigned int note
			);

		void play(Time startTime, Time duration, float* output[2]);
		void noteOff(Time time);
		void applyModulation(float* sources, float* targets);

		Time start;
		bool noteOn;
		bool active;
		unsigned int note;
		const Channel* channel;
		Oscillator oscillators[OSCILLATORS_PER_CHANNEL];
		Envelope envelopes[ENVELOPES_PER_CHANNEL];
		LFO lfos[LFOS_PER_CHANNEL];
		Filter filters[FILTERS_PER_CHANNEL];
	};
}

#endif  // VOICE_H_INCLUDED
