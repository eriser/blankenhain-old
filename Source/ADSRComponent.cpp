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
#include "PluginProcessor.h"
//[/Headers]

#include "ADSRComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
ADSRComponent::ADSRComponent (BlankenhainAudioProcessor* _processor, int _n)
    : processor(_processor), n(_n)
{
    addAndMakeVisible (attackSlider = new Slider ("Attack"));
    attackSlider->setRange (0, 1, 0);
    attackSlider->setSliderStyle (Slider::LinearVertical);
    attackSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    attackSlider->addListener (this);

    addAndMakeVisible (decaySlider = new Slider ("Decay"));
    decaySlider->setRange (0, 1, 0);
    decaySlider->setSliderStyle (Slider::LinearVertical);
    decaySlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    decaySlider->addListener (this);

    addAndMakeVisible (sustainSlider = new Slider ("Sustain"));
    sustainSlider->setRange (0, 1, 0);
    sustainSlider->setSliderStyle (Slider::LinearVertical);
    sustainSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    sustainSlider->addListener (this);

    addAndMakeVisible (releaseSlider = new Slider ("Release"));
    releaseSlider->setRange (0, 1, 0);
    releaseSlider->setSliderStyle (Slider::LinearVertical);
    releaseSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    releaseSlider->addListener (this);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
	parameterOffset = processor->getParameterIndex(static_cast<ParameterEditorId>(ADSR1_ID + n));
    //[/Constructor]
}

ADSRComponent::~ADSRComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    attackSlider = nullptr;
    decaySlider = nullptr;
    sustainSlider = nullptr;
    releaseSlider = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void ADSRComponent::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::white);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void ADSRComponent::resized()
{
    attackSlider->setBounds (proportionOfWidth (0.0000f), proportionOfHeight (0.0000f), proportionOfWidth (0.2510f), proportionOfHeight (1.0000f));
    decaySlider->setBounds (proportionOfWidth (0.2510f), proportionOfHeight (0.0000f), proportionOfWidth (0.2510f), proportionOfHeight (1.0000f));
    sustainSlider->setBounds (proportionOfWidth (0.5005f), proportionOfHeight (0.0000f), proportionOfWidth (0.2510f), proportionOfHeight (1.0000f));
    releaseSlider->setBounds (proportionOfWidth (0.7490f), proportionOfHeight (0.0000f), proportionOfWidth (0.2510f), proportionOfHeight (1.0000f));
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void ADSRComponent::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == attackSlider)
    {
        //[UserSliderCode_attackSlider] -- add your slider handling code here..
		processor->setParameterNotifyingHost(parameterOffset + 0, float(attackSlider->getValue()));
        //[/UserSliderCode_attackSlider]
    }
    else if (sliderThatWasMoved == decaySlider)
    {
        //[UserSliderCode_decaySlider] -- add your slider handling code here..
		processor->setParameterNotifyingHost(parameterOffset + 1, float(decaySlider->getValue()));
        //[/UserSliderCode_decaySlider]
    }
    else if (sliderThatWasMoved == sustainSlider)
    {
        //[UserSliderCode_sustainSlider] -- add your slider handling code here..
		processor->setParameterNotifyingHost(parameterOffset + 2, float(sustainSlider->getValue()));
        //[/UserSliderCode_sustainSlider]
    }
    else if (sliderThatWasMoved == releaseSlider)
    {
        //[UserSliderCode_releaseSlider] -- add your slider handling code here..
		processor->setParameterNotifyingHost(parameterOffset + 3, float(releaseSlider->getValue()));
        //[/UserSliderCode_releaseSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void ADSRComponent::updateUi() {
	attackSlider->setValue(processor->getParameter(parameterOffset + 0));
	decaySlider->setValue(processor->getParameter(parameterOffset + 1));
	sustainSlider->setValue(processor->getParameter(parameterOffset + 2));
	releaseSlider->setValue(processor->getParameter(parameterOffset + 3));
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="ADSRComponent" componentName=""
                 parentClasses="public Component, public ParameterEditor" constructorParams="BlankenhainAudioProcessor* _processor, int _n"
                 variableInitialisers="processor(_processor), n(_n)" snapPixels="8"
                 snapActive="1" snapShown="1" overlayOpacity="0.330" fixedSize="0"
                 initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ffffffff"/>
  <SLIDER name="Attack" id="7f931157cf71799a" memberName="attackSlider"
          virtualName="" explicitFocusOrder="0" pos="0% 0% 25.107% 100%"
          min="0" max="1" int="0" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="Decay" id="92e1ce8d74c36976" memberName="decaySlider" virtualName=""
          explicitFocusOrder="0" pos="25.107% 0% 25.107% 100%" min="0"
          max="1" int="0" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="Sustain" id="877f1e939dfb38df" memberName="sustainSlider"
          virtualName="" explicitFocusOrder="0" pos="50.071% 0% 25.107% 100%"
          min="0" max="1" int="0" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="Release" id="6a7f7fe4b6255174" memberName="releaseSlider"
          virtualName="" explicitFocusOrder="0" pos="74.893% 0% 25.107% 100%"
          min="0" max="1" int="0" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
