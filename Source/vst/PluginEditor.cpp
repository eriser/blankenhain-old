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

    addAndMakeVisible (lfo1Wrapper = new GroupWrapComponent<LFOComponent>());
    lfo1Wrapper->setName ("LFO1");

    addAndMakeVisible (adsr2Wrapper = new GroupWrapComponent<ADSRComponent> (ownerFilter, 1));
    adsr2Wrapper->setName ("ADSR2");

    addAndMakeVisible (lfo2Wrapper = new GroupWrapComponent<LFOComponent>());
    lfo2Wrapper->setName ("LFO2");

    addAndMakeVisible (lfo3Wrapper = new GroupWrapComponent<LFOComponent>());
    lfo3Wrapper->setName ("LFO3");

    addAndMakeVisible (osc1Wrapper = new GroupWrapComponent<OscillatorComponent>());
    osc1Wrapper->setName ("OSC1");

    addAndMakeVisible (osc2Wrapper = new GroupWrapComponent<OscillatorComponent>());
    osc2Wrapper->setName ("OSC2");


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


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
    lfo3Wrapper = nullptr;
    osc1Wrapper = nullptr;
    osc2Wrapper = nullptr;


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

    adsr1Wrapper->setBounds (proportionOfWidth (0.5000f), 0, proportionOfWidth (0.5000f), proportionOfHeight (0.3333f));
    lfo1Wrapper->setBounds (0, getHeight() - proportionOfHeight (0.3333f), proportionOfWidth (0.3329f), proportionOfHeight (0.3333f));
    adsr2Wrapper->setBounds (proportionOfWidth (0.5000f), proportionOfHeight (0.3333f), proportionOfWidth (0.5000f), proportionOfHeight (0.3333f));
    lfo2Wrapper->setBounds (proportionOfWidth (0.3329f), getHeight() - proportionOfHeight (0.3333f), proportionOfWidth (0.3329f), proportionOfHeight (0.3333f));
    lfo3Wrapper->setBounds (proportionOfWidth (0.6671f), proportionOfHeight (0.6667f), proportionOfWidth (0.3329f), proportionOfHeight (0.3333f));
    osc1Wrapper->setBounds (proportionOfWidth (0.0000f), proportionOfHeight (0.0000f), proportionOfWidth (0.5000f), proportionOfHeight (0.3333f));
    osc2Wrapper->setBounds (proportionOfWidth (0.0000f), proportionOfHeight (0.3333f), proportionOfWidth (0.5000f), proportionOfHeight (0.3333f));
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
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ffffffff"/>
  <GENERICCOMPONENT name="ADSR1" id="aa02ec06e0ef68d2" memberName="adsr1Wrapper"
                    virtualName="" explicitFocusOrder="0" pos="50% 0 50% 33.333%"
                    class="GroupWrapComponent&lt;ADSRComponent&gt;" params="ownerFilter, 0"/>
  <GENERICCOMPONENT name="LFO1" id="9521c8513f7d0e00" memberName="lfo1Wrapper" virtualName=""
                    explicitFocusOrder="0" pos="0 0Rr 33.286% 33.333%" class="GroupWrapComponent&lt;LFOComponent&gt;"
                    params=""/>
  <GENERICCOMPONENT name="ADSR2" id="e97ce6f55a156364" memberName="adsr2Wrapper"
                    virtualName="" explicitFocusOrder="0" pos="50% 33.333% 50% 33.333%"
                    class="GroupWrapComponent&lt;ADSRComponent&gt;" params="ownerFilter, 1"/>
  <GENERICCOMPONENT name="LFO2" id="f836b115579cdc4f" memberName="lfo2Wrapper" virtualName=""
                    explicitFocusOrder="0" pos="33.286% 0Rr 33.286% 33.333%" class="GroupWrapComponent&lt;LFOComponent&gt;"
                    params=""/>
  <GENERICCOMPONENT name="LFO3" id="7abe9eb613638bcb" memberName="lfo3Wrapper" virtualName=""
                    explicitFocusOrder="0" pos="66.714% 66.667% 33.286% 33.333%"
                    class="GroupWrapComponent&lt;LFOComponent&gt;" params=""/>
  <GENERICCOMPONENT name="OSC1" id="301482411b8be9b8" memberName="osc1Wrapper" virtualName=""
                    explicitFocusOrder="0" pos="0% 0% 50% 33.333%" class="GroupWrapComponent&lt;OscillatorComponent&gt;"
                    params=""/>
  <GENERICCOMPONENT name="OSC2" id="da7522de7cbdc9a7" memberName="osc2Wrapper" virtualName=""
                    explicitFocusOrder="0" pos="0% 33.333% 50% 33.333%" class="GroupWrapComponent&lt;OscillatorComponent&gt;"
                    params=""/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
