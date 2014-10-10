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
    addAndMakeVisible (component = new GroupWrapComponent<ADSRComponent> (ownerFilter));
    component->setName ("new component");


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

    component = nullptr;


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
    component->setBounds (88, 112, 328, 256);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void BlankenhainAudioProcessorEditor::timerCallback() {
    BlankenhainAudioProcessor* ourProcessor = getProcessor();

	if (ourProcessor->needsUiUpdate()) {
		ADSRComponent& adsr1Component = component->getWrapped();
		adsr1Component.setAttack(ourProcessor->getParameter(0));
		adsr1Component.setDecay(ourProcessor->getParameter(1));
		adsr1Component.setSustain(ourProcessor->getParameter(2));
		adsr1Component.setRelease(ourProcessor->getParameter(3));
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
  <GENERICCOMPONENT name="new component" id="aa02ec06e0ef68d2" memberName="component"
                    virtualName="" explicitFocusOrder="0" pos="88 112 328 256" class="GroupWrapComponent&lt;ADSRComponent&gt;"
                    params="ownerFilter"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
