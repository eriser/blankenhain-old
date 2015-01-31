/*
  ==============================================================================

  This is an automatically generated GUI class created by the Introjucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Introjucer version: 3.1.1

  ------------------------------------------------------------------------------

  The Introjucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-13 by Raw Material Software Ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "PluginEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
BlankenhainAudioProcessorEditor::BlankenhainAudioProcessorEditor (BlankenhainAudioProcessor* ownerFilter)
    : AudioProcessorEditor(ownerFilter)
{
    addAndMakeVisible (adsr1Wrapper = new GroupWrapComponent<ADSRComponent> (ownerFilter, 0));
    adsr1Wrapper->setName ("ADSR1");

    addAndMakeVisible (lfo1Wrapper = new GroupWrapComponent<LFOComponent> (ownerFilter, 0));
    lfo1Wrapper->setName ("LFO1");

    addAndMakeVisible (adsr2Wrapper = new GroupWrapComponent<ADSRComponent> (ownerFilter, 1));
    adsr2Wrapper->setName ("ADSR2");

    addAndMakeVisible (lfo2Wrapper = new GroupWrapComponent<LFOComponent> (ownerFilter, 1));
    lfo2Wrapper->setName ("LFO2");

    addAndMakeVisible (osc1Wrapper = new GroupWrapComponent<OscillatorComponent> (ownerFilter, 0));
    osc1Wrapper->setName ("OSC1");

    addAndMakeVisible (osc2Wrapper = new GroupWrapComponent<OscillatorComponent> (ownerFilter, 1));
    osc2Wrapper->setName ("OSC2");

    addAndMakeVisible (filter1Wrapper = new GroupWrapComponent<FilterComponent> (ownerFilter, 0));
    filter1Wrapper->setName ("Filter1");

    addAndMakeVisible (filter2Wrapper = new GroupWrapComponent<FilterComponent> (ownerFilter, 1));
    filter2Wrapper->setName ("Filter2");

    addAndMakeVisible (osc3Wrapper = new GroupWrapComponent<OscillatorComponent> (ownerFilter, 2));
    osc3Wrapper->setName ("OSC3");

    addAndMakeVisible (adsr3Wrapper = new GroupWrapComponent<ADSRComponent> (ownerFilter, 2));
    adsr3Wrapper->setName ("ADSR3");

    addAndMakeVisible (lfo3Wrapper = new GroupWrapComponent<LFOComponent> (ownerFilter, 2));
    lfo3Wrapper->setName ("LFO3");

    addAndMakeVisible (filter3Wrapper = new GroupWrapComponent<FilterComponent> (ownerFilter, 2));
    filter3Wrapper->setName ("Filter3");

    addAndMakeVisible (modMatrix = new GroupWrapComponent<ModulationMatrixComponent>());
    modMatrix->setName ("Modulation");


    //[UserPreSize]
    //[/UserPreSize]

    setSize (800, 600);


    //[Constructor] You can add your own custom stuff here..
	getProcessor()->requestUiUpdate();
    startTimer(200);
    setLookAndFeel(&lookAndFeel);
    //[/Constructor]
}

BlankenhainAudioProcessorEditor::~BlankenhainAudioProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    adsr1Wrapper = nullptr;
    lfo1Wrapper = nullptr;
    adsr2Wrapper = nullptr;
    lfo2Wrapper = nullptr;
    osc1Wrapper = nullptr;
    osc2Wrapper = nullptr;
    filter1Wrapper = nullptr;
    filter2Wrapper = nullptr;
    osc3Wrapper = nullptr;
    adsr3Wrapper = nullptr;
    lfo3Wrapper = nullptr;
    filter3Wrapper = nullptr;
    modMatrix = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void BlankenhainAudioProcessorEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::white);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void BlankenhainAudioProcessorEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    adsr1Wrapper->setBounds (proportionOfWidth (0.0000f), proportionOfHeight (0.2497f), proportionOfWidth (0.2498f), proportionOfHeight (0.2497f));
    lfo1Wrapper->setBounds (proportionOfWidth (0.0000f), proportionOfHeight (0.4994f), proportionOfWidth (0.2498f), proportionOfHeight (0.2497f));
    adsr2Wrapper->setBounds (proportionOfWidth (0.2498f), proportionOfHeight (0.2497f), proportionOfWidth (0.2498f), proportionOfHeight (0.2497f));
    lfo2Wrapper->setBounds (proportionOfWidth (0.2498f), proportionOfHeight (0.4994f), proportionOfWidth (0.2498f), proportionOfHeight (0.2497f));
    osc1Wrapper->setBounds (proportionOfWidth (0.0000f), proportionOfHeight (0.0000f), proportionOfWidth (0.2498f), proportionOfHeight (0.2497f));
    osc2Wrapper->setBounds (proportionOfWidth (0.2498f), proportionOfHeight (0.0000f), proportionOfWidth (0.2498f), proportionOfHeight (0.2497f));
    filter1Wrapper->setBounds (proportionOfWidth (0.0000f), proportionOfHeight (0.7503f), proportionOfWidth (0.2498f), proportionOfHeight (0.2497f));
    filter2Wrapper->setBounds (proportionOfWidth (0.2498f), proportionOfHeight (0.7503f), proportionOfWidth (0.2498f), proportionOfHeight (0.2497f));
    osc3Wrapper->setBounds (proportionOfWidth (0.4995f), proportionOfHeight (0.0000f), proportionOfWidth (0.2498f), proportionOfHeight (0.2497f));
    adsr3Wrapper->setBounds (proportionOfWidth (0.4995f), proportionOfHeight (0.2497f), proportionOfWidth (0.2498f), proportionOfHeight (0.2497f));
    lfo3Wrapper->setBounds (proportionOfWidth (0.4995f), proportionOfHeight (0.4994f), proportionOfWidth (0.2498f), proportionOfHeight (0.2497f));
    filter3Wrapper->setBounds (proportionOfWidth (0.4995f), proportionOfHeight (0.7503f), proportionOfWidth (0.2498f), proportionOfHeight (0.2497f));
    modMatrix->setBounds (proportionOfWidth (0.7503f), proportionOfHeight (0.0000f), proportionOfWidth (0.2498f), proportionOfHeight (1.0000f));
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void BlankenhainAudioProcessorEditor::timerCallback() {
    BlankenhainAudioProcessor* ourProcessor = getProcessor();

	if (ourProcessor->needsUiUpdate()) {
		adsr1Wrapper->getWrapped().updateUi();
		adsr2Wrapper->getWrapped().updateUi();
		lfo1Wrapper->getWrapped().updateUi();
		lfo2Wrapper->getWrapped().updateUi();
		ourProcessor->clearUiUpdate();
	}
	/*
	const float adsr[4] = {
		adsr1Component->getAttack(),
		adsr1Component->getDecay(),
		adsr1Component->getSustain(),
		adsr1Component->getRelease()
	};
	ourProcessor->setAdsr(adsr);
	*/
}

BlankenhainAudioProcessor* BlankenhainAudioProcessorEditor::getProcessor() const {
    return static_cast<BlankenhainAudioProcessor*>(getAudioProcessor());
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="BlankenhainAudioProcessorEditor"
                 componentName="" parentClasses="public AudioProcessorEditor, public Timer"
                 constructorParams="BlankenhainAudioProcessor* ownerFilter" variableInitialisers="AudioProcessorEditor(ownerFilter)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="800" initialHeight="600">
  <BACKGROUND backgroundColour="ffffffff"/>
  <GENERICCOMPONENT name="ADSR1" id="aa02ec06e0ef68d2" memberName="adsr1Wrapper"
                    virtualName="" explicitFocusOrder="0" pos="0% 24.968% 24.975% 24.968%"
                    class="GroupWrapComponent&lt;ADSRComponent&gt;" params="ownerFilter, 0"/>
  <GENERICCOMPONENT name="LFO1" id="9521c8513f7d0e00" memberName="lfo1Wrapper" virtualName=""
                    explicitFocusOrder="0" pos="0% 49.937% 24.975% 24.968%" class="GroupWrapComponent&lt;LFOComponent&gt;"
                    params="ownerFilter, 0"/>
  <GENERICCOMPONENT name="ADSR2" id="e97ce6f55a156364" memberName="adsr2Wrapper"
                    virtualName="" explicitFocusOrder="0" pos="24.975% 24.968% 24.975% 24.968%"
                    class="GroupWrapComponent&lt;ADSRComponent&gt;" params="ownerFilter, 1"/>
  <GENERICCOMPONENT name="LFO2" id="f836b115579cdc4f" memberName="lfo2Wrapper" virtualName=""
                    explicitFocusOrder="0" pos="24.975% 49.937% 24.975% 24.968%"
                    class="GroupWrapComponent&lt;LFOComponent&gt;" params="ownerFilter, 1"/>
  <GENERICCOMPONENT name="OSC1" id="301482411b8be9b8" memberName="osc1Wrapper" virtualName=""
                    explicitFocusOrder="0" pos="0% 0% 24.975% 24.968%" class="GroupWrapComponent&lt;OscillatorComponent&gt;"
                    params="ownerFilter, 0"/>
  <GENERICCOMPONENT name="OSC2" id="da7522de7cbdc9a7" memberName="osc2Wrapper" virtualName=""
                    explicitFocusOrder="0" pos="24.975% 0% 24.975% 24.968%" class="GroupWrapComponent&lt;OscillatorComponent&gt;"
                    params="ownerFilter, 1"/>
  <GENERICCOMPONENT name="Filter1" id="61ac5656499830de" memberName="filter1Wrapper"
                    virtualName="" explicitFocusOrder="0" pos="0% 75.032% 24.975% 24.968%"
                    class="GroupWrapComponent&lt;FilterComponent&gt;" params="ownerFilter, 0"/>
  <GENERICCOMPONENT name="Filter2" id="479d0707b283ea86" memberName="filter2Wrapper"
                    virtualName="" explicitFocusOrder="0" pos="24.975% 75.032% 24.975% 24.968%"
                    class="GroupWrapComponent&lt;FilterComponent&gt;" params="ownerFilter, 1"/>
  <GENERICCOMPONENT name="OSC3" id="66f95d2cadc0337c" memberName="osc3Wrapper" virtualName=""
                    explicitFocusOrder="0" pos="49.951% 0% 24.975% 24.968%" class="GroupWrapComponent&lt;OscillatorComponent&gt;"
                    params="ownerFilter, 2"/>
  <GENERICCOMPONENT name="ADSR3" id="ab5df36835b95708" memberName="adsr3Wrapper"
                    virtualName="" explicitFocusOrder="0" pos="49.951% 24.968% 24.975% 24.968%"
                    class="GroupWrapComponent&lt;ADSRComponent&gt;" params="ownerFilter, 2"/>
  <GENERICCOMPONENT name="LFO3" id="713f3cb87a927d08" memberName="lfo3Wrapper" virtualName=""
                    explicitFocusOrder="0" pos="49.951% 49.937% 24.975% 24.968%"
                    class="GroupWrapComponent&lt;LFOComponent&gt;" params="ownerFilter, 2"/>
  <GENERICCOMPONENT name="Filter3" id="6f75bffddb0b4812" memberName="filter3Wrapper"
                    virtualName="" explicitFocusOrder="0" pos="49.951% 75.032% 24.975% 24.968%"
                    class="GroupWrapComponent&lt;FilterComponent&gt;" params="ownerFilter, 2"/>
  <GENERICCOMPONENT name="Modulation" id="409331363e1ab1af" memberName="modMatrix"
                    virtualName="" explicitFocusOrder="0" pos="75.025% 0% 24.975% 100%"
                    class="GroupWrapComponent&lt;ModulationMatrixComponent&gt;" params=""/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
