#ifndef CHANNEL_H_INCLUDED
#define CHANNEL_H_INCLUDED

#include "OscillatorSettings.h"
#include "EnvelopeSettings.h"
#include "LFOSettings.h"
#include "FilterSettings.h"
#include "Voice.h"
#include "Config.h"
#include "Message.h"
#include "VoiceManager.h"
#include "ModulationMatrix.h"

namespace blankenhain {
	struct Channel {
		Channel() = default;
		Channel(unsigned int sampleRate, VoiceManager* voiceManager);

		void play(Time startTime, Time duration, float* output[2]);
		void noteOn(Time time, const NoteOnMessage& message);
		void noteOff(Time time, const NoteOffMessage& message);
		void parameterChange(const ParameterChangeMessage& message);

		OscillatorSettings oscillators[OSCILLATORS_PER_CHANNEL];
		EnvelopeSettings envelopes[ENVELOPES_PER_CHANNEL];
		LFOSettings lfos[LFOS_PER_CHANNEL];
		FilterSettings filters[FILTERS_PER_CHANNEL];
		ModulationMatrix modulationMatrix;

		unsigned int sampleRate;
		VoiceManager* voiceManager;
	};
}

#endif  // CHANNEL_H_INCLUDED
