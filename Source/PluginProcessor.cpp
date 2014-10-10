#include "PluginProcessor.h"
#include "PluginEditor.h"

#include <cmath>


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
	return 4;
}

float BlankenhainAudioProcessor::getParameter(int index)
{
	return defaultInstrument.getAdsr()[index];
}

void BlankenhainAudioProcessor::setParameter(int index, float newValue)
{
	const float* prev = defaultInstrument.getAdsr();
	float newAdsr[4];
	newAdsr[0] = prev[0];
	newAdsr[1] = prev[1];
	newAdsr[2] = prev[2];
	newAdsr[3] = prev[3];
	newAdsr[index] = newValue;
	defaultInstrument.setAdsr(newAdsr);
	requestUiUpdate();
}

const String BlankenhainAudioProcessor::getParameterName(int index)
{
	switch (index) {
	case 0:
		return "Attack";
	case 1:
		return "Decay";
	case 2:
		return "Sustain";
	case 3:
		return "Release";
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
void BlankenhainAudioProcessor::prepareToPlay(double sampleRate, int samplesPerBlock)
{
	defaultInstrument.setSampleRate(sampleRate);
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
void BlankenhainAudioProcessor::requestUiUpdate() {
	uiNeedsUpdate = true;
}

void BlankenhainAudioProcessor::clearUiUpdate() {
	uiNeedsUpdate = false;
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
	return new BlankenhainAudioProcessor();
}
