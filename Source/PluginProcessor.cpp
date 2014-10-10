#include "PluginProcessor.h"
#include "PluginEditor.h"

#include <cmath>


//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
	return new BlankenhainAudioProcessor();
}


//==============================================================================
BlankenhainAudioProcessor::BlankenhainAudioProcessor() :
defaultInstrument(voices)
{
	requestUiUpdate();
}

BlankenhainAudioProcessor::~BlankenhainAudioProcessor()
{
}

//==============================================================================
const String BlankenhainAudioProcessor::getName() const
{
	return JucePlugin_Name;
}

int BlankenhainAudioProcessor::getNumParameters()
{
	return getParameterIndex(END);
}

float BlankenhainAudioProcessor::getParameter(int index)
{
	const ParameterEditorId id = getParameterEditorId(index);
	const int relativeIndex = index - getParameterIndex(id);
	switch (id) {
	case ADSR1_ID:
		return getEnvelopeParameter(defaultInstrument.getEnvelope1(), relativeIndex);
	case ADSR2_ID:
		return getEnvelopeParameter(defaultInstrument.getEnvelope2(), relativeIndex);
	default:
		return 0.;
	}
}

void BlankenhainAudioProcessor::setParameter(int index, float newValue)
{
	const ParameterEditorId id = getParameterEditorId(index);
	const int relativeIndex = index - getParameterIndex(id);
	switch (id) {
	case ADSR1_ID:
		setEnvelopeParameter(defaultInstrument.getEnvelope1(), relativeIndex, newValue);
		requestUiUpdate();
		break;
	case ADSR2_ID:
		setEnvelopeParameter(defaultInstrument.getEnvelope2(), relativeIndex, newValue);
		requestUiUpdate();
		break;
	default:
		break;
	}
}

const String BlankenhainAudioProcessor::getParameterName(int index)
{
	const ParameterEditorId id = getParameterEditorId(index);
	const int relativeIndex = index - getParameterIndex(id);
	String idPostfix = "2";
	switch (id) {
	case ADSR1_ID:
		idPostfix = "1";
	case ADSR2_ID:
		switch (relativeIndex) {
		case 0:
			return "Attack" + idPostfix;
		case 1:
			return "Decay" + idPostfix;
		case 2:
			return "Sustain" + idPostfix;
		case 3:
			return "Release" + idPostfix;
		default:
			return "";
		}
	default:
		return "";
	}
}

const String BlankenhainAudioProcessor::getParameterText(int index)
{
	return String(getParameter(index));
}

const String BlankenhainAudioProcessor::getInputChannelName(int channelIndex) const
{
	return String(channelIndex + 1);
}

const String BlankenhainAudioProcessor::getOutputChannelName(int channelIndex) const
{
	return String(channelIndex + 1);
}

bool BlankenhainAudioProcessor::isInputChannelStereoPair(int index) const
{
	return true;
}

bool BlankenhainAudioProcessor::isOutputChannelStereoPair(int index) const
{
	return true;
}

bool BlankenhainAudioProcessor::acceptsMidi() const
{
#if JucePlugin_WantsMidiInput
	return true;
#else
	return false;
#endif
}

bool BlankenhainAudioProcessor::producesMidi() const
{
#if JucePlugin_ProducesMidiOutput
	return true;
#else
	return false;
#endif
}

bool BlankenhainAudioProcessor::silenceInProducesSilenceOut() const
{
	return false;
}

double BlankenhainAudioProcessor::getTailLengthSeconds() const
{
	return 0.0;
}

int BlankenhainAudioProcessor::getNumPrograms()
{
	return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
	// so this should be at least 1, even if you're not really implementing programs.
}

int BlankenhainAudioProcessor::getCurrentProgram()
{
	return 0;
}

void BlankenhainAudioProcessor::setCurrentProgram(int index)
{
}

const String BlankenhainAudioProcessor::getProgramName(int index)
{
	return String();
}

void BlankenhainAudioProcessor::changeProgramName(int index, const String& newName)
{
}

//==============================================================================
void BlankenhainAudioProcessor::prepareToPlay(double _sampleRate, int samplesPerBlock)
{
	defaultInstrument.setSampleRate(_sampleRate);
	sampleRate = _sampleRate;
}

void BlankenhainAudioProcessor::releaseResources()
{
	// When playback stops, you can use this as an opportunity to free up any
	// spare memory, etc.
}

void BlankenhainAudioProcessor::processBlock(AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
	for (int i = 0; i < getNumOutputChannels(); i++) {
		buffer.clear(i, 0, buffer.getNumSamples());
	}

	MidiBuffer::Iterator iterator(midiMessages);
	MidiMessage message;
	int samplePosition;
	int bufferPosition = 0;
	if (!midiMessages.isEmpty()) {
		Logger::outputDebugString("List midi events");
	}
	while (iterator.getNextEvent(message, samplePosition)) {
		if (message.isNoteOnOrOff()) {
			String onOff = message.isNoteOn() ? "On" : "Off";
			Logger::outputDebugString(onOff + " " + String(message.getNoteNumber()) + " " + String(samplePosition));
			const int numPlaySamples = samplePosition - bufferPosition;
			voices.play(globalTime, bufferPosition, numPlaySamples, getNumOutputChannels(), buffer.getArrayOfWritePointers());
			globalTime += numPlaySamples;
			bufferPosition = samplePosition;
			if (message.isNoteOn()) {
				defaultInstrument.noteOn(globalTime, message.getNoteNumber());
			}
			else {
				defaultInstrument.noteOff(globalTime, message.getNoteNumber());
			}
		}
		else {
			Logger::outputDebugString("Other event");
		}
	}
	const int remainingSamples = buffer.getNumSamples() - bufferPosition;
	if (remainingSamples > 0) {
		voices.play(globalTime, bufferPosition, remainingSamples, getNumOutputChannels(), buffer.getArrayOfWritePointers());
		globalTime += remainingSamples;
	}
}

//==============================================================================
bool BlankenhainAudioProcessor::hasEditor() const
{
	return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* BlankenhainAudioProcessor::createEditor()
{
	return new BlankenhainAudioProcessorEditor(this);
}

//==============================================================================
void BlankenhainAudioProcessor::getStateInformation(MemoryBlock& destData)
{
	// You should use this method to store your parameters in the memory block.
	// You could do that either as raw data, or use the XML or ValueTree classes
	// as intermediaries to make it easy to save and load complex data.
}

void BlankenhainAudioProcessor::setStateInformation(const void* data, int sizeInBytes)
{
	// You should use this method to restore your parameters from this memory block,
	// whose contents will have been created by the getStateInformation() call.
}

bool BlankenhainAudioProcessor::needsUiUpdate() const {
	return uiNeedsUpdate;
}

int BlankenhainAudioProcessor::getParameterIndex(enum ParameterEditorId id) const {
	const int parameterIndex[] = {
		0, // ADSR1
		4, // ADSR2
		8, // LFO1
		8, // LFO2
		8, // END
	};
	return parameterIndex[id];
}

ParameterEditorId BlankenhainAudioProcessor::getParameterEditorId(int index) const {
	if (index < getParameterIndex(ADSR1_ID)) {
		return END;
	}
	else if (index < getParameterIndex(ADSR2_ID)) {
		return ADSR1_ID;
	}
	else if (index < getParameterIndex(LFO1_ID)) {
		return ADSR2_ID;
	}
	else if (index < getParameterIndex(LFO2_ID)) {
		return LFO1_ID;
	}
	else if (index < getParameterIndex(END)) {
		return LFO2_ID;
	}
	else {
		return END;
	}
}

void BlankenhainAudioProcessor::requestUiUpdate() {
	uiNeedsUpdate = true;
}

void BlankenhainAudioProcessor::clearUiUpdate() {
	uiNeedsUpdate = false;
}


float BlankenhainAudioProcessor::getEnvelopeParameter(Envelope& envelope, int index) const {
	switch (index) {
	case 0:
		return float(envelope.getAttack() / sampleRate);
	case 1:
		return float(envelope.getDecay() / sampleRate);
	case 2:
		return float(envelope.getSustain());
	case 3:
		return float(envelope.getRelease() / sampleRate);
	default:
		return 0;
	}
}

void BlankenhainAudioProcessor::setEnvelopeParameter(Envelope& envelope, int index, float newValue) {
	switch (index) {
	case 0:
		envelope.setAttack(newValue * sampleRate);
		break;
	case 1:
		envelope.setDecay(newValue * sampleRate);
		break;
	case 2:
		envelope.setSustain(newValue);
		break;
	case 3:
		envelope.setRelease(newValue * sampleRate);
		break;
	}
}