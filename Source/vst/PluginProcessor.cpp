#include "PluginProcessor.h"
#include "PluginEditor.h"

#include <cmath>

using namespace blankenhain;

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
	return new BlankenhainAudioProcessor();
}


//==============================================================================
BlankenhainAudioProcessor::BlankenhainAudioProcessor()
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
	return parameters.getNumParameters();
}

float BlankenhainAudioProcessor::getParameter(int index)
{
	return parameters.getParameter(index);
}

void BlankenhainAudioProcessor::setParameter(int index, float newValue)
{
	parameters.setParameter(index, newValue);
	requestUiUpdate();
}

const String BlankenhainAudioProcessor::getParameterName(int index)
{
	return parameters.getParameterName(index);
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
	synth = std::make_unique<Blankenhain>(static_cast<unsigned int>(sampleRate));
	parameters.setSynth(*synth);
	synth->channels[0].envelopes[0] = EnvelopeSettings(static_cast<unsigned int>(sampleRate), .0, .0, .0, .0);
	synth->channels[0].envelopes[1] = EnvelopeSettings(static_cast<unsigned int>(sampleRate), .0, .0, .0, .0);
	synth->channels[0].envelopes[2] = EnvelopeSettings(static_cast<unsigned int>(sampleRate), .0, .0, .0, .0);
	OscillatorSettings& osc = synth->channels[0].oscillators[0];
	osc = OscillatorSettings(static_cast<unsigned int>(sampleRate), OscillatorType::SAW, .0, 0., 0);
	synth->channels[0].oscillators[1] = OscillatorSettings(static_cast<unsigned int>(sampleRate), OscillatorType::SINE, .0, 0., 0);
	synth->channels[0].oscillators[2] = OscillatorSettings(static_cast<unsigned int>(sampleRate), OscillatorType::SINE, .0, 0., 0);
	synth->channels[0].filters[0] = FilterSettings(static_cast<unsigned int>(sampleRate), FilterType::LOWPASS, 700., 0.5, false);
	synth->channels[0].filters[1] = FilterSettings(static_cast<unsigned int>(sampleRate), FilterType::HIGHPASS, 0., 0., false);
	synth->channels[0].filters[2] = FilterSettings(static_cast<unsigned int>(sampleRate), FilterType::HIGHPASS, 0., 0., false);
	synth->channels[0].lfos[0] = LFOSettings(static_cast<unsigned int>(sampleRate), OscillatorType::SINE, 0.f, 0.f, true);
	synth->channels[0].lfos[1] = LFOSettings(static_cast<unsigned int>(sampleRate), OscillatorType::SINE, 0.f, 0.f, true);
	synth->channels[0].lfos[2] = LFOSettings(static_cast<unsigned int>(sampleRate), OscillatorType::SINE, 0.f, 0.f, true);
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

	std::vector<blankenhain::Message> messageBuffer;
	messageBuffer.reserve(midiMessages.getNumEvents());

	while (iterator.getNextEvent(message, samplePosition)) {
		if (message.isNoteOnOrOff()) {
			const int channel = message.getChannel() - 1;
			if (message.isNoteOn()) {
				messageBuffer.push_back(blankenhain::Message::createNoteOn(samplePosition, message.getNoteNumber(), channel));
			}
			else {
				messageBuffer.push_back(blankenhain::Message::createNoteOff(samplePosition, message.getNoteNumber(), channel));
			}
		}
	}

	blankenhain::Message* messages = nullptr;
	if (!messageBuffer.empty()) {
		messages = &messageBuffer[0];
	}
	synth->processBlock(buffer.getArrayOfWritePointers(), buffer.getNumSamples(), messages, messageBuffer.size());
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

const Parameters& BlankenhainAudioProcessor::getParameters() const {
	return parameters;
}

Blankenhain& BlankenhainAudioProcessor::getSynth() {
	return *synth;
}