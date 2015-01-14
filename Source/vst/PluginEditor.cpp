/*
  ==============================================================================

  This is an automatically generated GUI class created by the Introjucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Introjucer version: 3.1.0

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
    adsr1Wrapper->setBounds (0, 0, proportionOfWidth (0.4993f), proportionOfHeight (0.6667f));
    lfo1Wrapper->setBounds (0, getHeight() - proportionOfHeight (0.3333f), proportionOfWidth (0.4993f), proportionOfHeight (0.3333f));
    adsr2Wrapper->setBounds (proportionOfWidth (0.4993f), 0, proportionOfWidth (0.4993f), proportionOfHeight (0.6667f));
    lfo2Wrapper->setBounds (proportionOfWidth (0.4993f), getHeight() - proportionOfHeight (0.3333f), proportionOfWidth (0.4993f), proportionOfHeight (0.3333f));
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
                    virtualName="" explicitFocusOrder="0" pos="0 0 49.929% 66.667%"
                    class="GroupWrapComponent&lt;ADSRComponent&gt;" params="ownerFilter, 0"/>
  <GENERICCOMPONENT name="LFO1" id="9521c8513f7d0e00" memberName="lfo1Wrapper" virtualName=""
                    explicitFocusOrder="0" pos="0 0Rr 49.929% 33.333%" class="GroupWrapComponent&lt;LFOComponent&gt;"
                    params=""/>
  <GENERICCOMPONENT name="ADSR2" id="e97ce6f55a156364" memberName="adsr2Wrapper"
                    virtualName="" explicitFocusOrder="0" pos="49.929% 0 49.929% 66.667%"
                    class="GroupWrapComponent&lt;ADSRComponent&gt;" params="ownerFilter, 1"/>
  <GENERICCOMPONENT name="LFO2" id="f836b115579cdc4f" memberName="lfo2Wrapper" virtualName=""
                    explicitFocusOrder="0" pos="49.929% 0Rr 49.929% 33.333%" class="GroupWrapComponent&lt;LFOComponent&gt;"
                    params=""/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]