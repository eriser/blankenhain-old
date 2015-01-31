#include "Voice.h"
#include "Channel.h"
#include "Functions.h"

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
			float modulationSources[ENVELOPES_PER_CHANNEL + LFOS_PER_CHANNEL];
			float* const envelopeValues = modulationSources;
			for (unsigned int envelope = 0; envelope < ENVELOPES_PER_CHANNEL; envelope++) {
				// TODO mod missing
				envelopeValues[envelope] = envelopes[envelope].value(startTime + i, 0, 0, 0, 0);
			}
			// first envelope is hard-wired to volume
			// switch off voice when envelope reaches (near) zero
			if (envelopes[0].finished) {
				active = false;
			}

			float* const lfoValues = modulationSources + ENVELOPES_PER_CHANNEL;
			for (unsigned int lfo = 0; lfo < LFOS_PER_CHANNEL; lfo++) {
				// TODO mod missing
				lfoValues[lfo] = lfos[lfo].value(startTime + i, 0, 0);
			}

			float modulationTargets[OSCILLATORS_PER_CHANNEL * 2 + FILTERS_PER_CHANNEL * 2]{};
			applyModulation(modulationSources, modulationTargets);

			float sample[2] {};
			for (unsigned int oscillator = 0; oscillator < OSCILLATORS_PER_CHANNEL; oscillator++) {
				const float volumeMod = modulationTargets[oscillator];
				const float detuneMod = modulationTargets[OSCILLATORS_PER_CHANNEL + oscillator];
				oscillators[oscillator].value(startTime + i, sample, volumeMod, detuneMod);
			}
			sample[0] = clamp(sample[0], 0.f, 1.f);
			sample[1] = clamp(sample[1], 0.f, 1.f);
			for (unsigned int filter = 0; filter < FILTERS_PER_CHANNEL; filter++) {
				const float frequencyMod = modulationTargets[OSCILLATORS_PER_CHANNEL * 2 + filter];
				const float qMod = modulationTargets[OSCILLATORS_PER_CHANNEL * 2 + FILTERS_PER_CHANNEL + filter];
				filters[filter].process(sample, frequencyMod, qMod);
			}
			output[0][i] += sample[0] * envelopeValues[0];
			output[1][i] += sample[1] * envelopeValues[0];
		}
	}

	void Voice::noteOff(Time time) {
		noteOn = false;
		for (unsigned int envelope = 0; envelope < ENVELOPES_PER_CHANNEL; envelope++) {
			envelopes[envelope].noteOff(time);
		}
	}

	void Voice::applyModulation(const float* sources, float* targets) {
		const ModulationMatrix& matrix = channel->modulationMatrix;
		for (unsigned int i = 0; i < MODULATION_MATRIX_ENTRIES; i++) {
			const Modulation& mod = matrix.entries[i];
			if (!mod.active) {
				continue;
			}

			float sourceValue = 0.0;
			switch (mod.source) {
			case ModulationSource::ENVELOPE:
				sourceValue = sources[mod.sourceIndex];
				break;
			case ModulationSource::LFO:
				sourceValue = sources[ENVELOPES_PER_CHANNEL + mod.sourceIndex];
				break;
			}

			float* target = targets;
			switch (mod.target) {
			case ModulationTarget::VOLUME:
				target = &targets[mod.targetIndex];
				break;
			case ModulationTarget::DETUNE:
				target = &targets[OSCILLATORS_PER_CHANNEL + mod.targetIndex];
				break;
			case ModulationTarget::FILTER_CUTOFF:
				target = &targets[OSCILLATORS_PER_CHANNEL * 2 + mod.targetIndex];
				break;
			case ModulationTarget::FILTER_Q:
				target = &targets[OSCILLATORS_PER_CHANNEL * 2 + FILTERS_PER_CHANNEL + mod.targetIndex];
				break;
			}
			// TODO apply meta-mod
			const float scale = mod.scale;
			*target += sourceValue * scale;
		}
	}
}