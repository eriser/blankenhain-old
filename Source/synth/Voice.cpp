#include "Voice.h"
#include "Channel.h"

namespace blankenhain {
	Voice::Voice() :
		noteOn(false),
		active(false)
	{}

	Voice::Voice(
		Time start_,
		const Channel* channel_,
		unsigned int note_) :
		noteOn(true),
		active(true),
		start(start_),
		channel(channel_),
		note(note_)
	{
		for (unsigned int i = 0; i < OSCILLATORS_PER_CHANNEL; i++) {
			oscillators[i] = Oscillator(&channel->oscillators[i], note);
		}
		for (unsigned int i = 0; i < ENVELOPES_PER_CHANNEL; i++) {
			envelopes[i] = Envelope(&channel->envelopes[i], start);
		}
		for (unsigned int i = 0; i < LFOS_PER_CHANNEL; i++) {
			lfos[i] = LFO(&channel->lfos[i], start);
		}
		for (unsigned int i = 0; i < FILTERS_PER_CHANNEL; i++) {
			filters[i] = Filter(&channel->filters[i]);
		}
	}

	void Voice::play(Time startTime, Time duration, float* output[2]) {
		for (unsigned int i = 0; i < static_cast<unsigned int>(duration); i++) {
			float envelopeValues[ENVELOPES_PER_CHANNEL];
			for (unsigned int envelope = 0; envelope < ENVELOPES_PER_CHANNEL; envelope++) {
				// TODO mod missing
				envelopeValues[envelope] = envelopes[envelope].value(startTime + i, 0, 0, 0, 0);
			}
			float lfoValues[LFOS_PER_CHANNEL];
			for (unsigned int lfo = 0; lfo < LFOS_PER_CHANNEL; lfo++) {
				// TODO mod missing
				lfoValues[lfo] = lfos[lfo].value(startTime + i, 0, 0);
			}
			float sample[2] {};
			for (unsigned int oscillator = 0; oscillator < OSCILLATORS_PER_CHANNEL; oscillator++) {
				oscillators[oscillator].value(startTime + i, sample);
			}
			for (unsigned int filter = 0; filter < FILTERS_PER_CHANNEL; filter++) {
				filters[filter].process(sample);
			}
			output[0][i] = sample[0];
			output[1][i] = sample[1];
		}
	}

	void Voice::noteOff(Time time) {
		noteOn = false;
		for (unsigned int envelope = 0; envelope < ENVELOPES_PER_CHANNEL; envelope++) {
			envelopes[envelope].noteOff(time);
		}
	}
}