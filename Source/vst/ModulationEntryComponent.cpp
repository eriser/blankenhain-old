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

#include "ModulationEntryComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
ModulationEntryComponent::ModulationEntryComponent ()
{
    addAndMakeVisible (scaleSlider = new Slider ("new slider"));
    scaleSlider->setRange (0, 1, 0.001);
    scaleSlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    scaleSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 40, 20);
    scaleSlider->addListener (this);

    addAndMakeVisible (sourceSelect = new ComboBox ("new combo box"));
    sourceSelect->setEditableText (false);
    sourceSelect->setJustificationType (Justification::centredLeft);
    sourceSelect->setTextWhenNothingSelected (String::empty);
    sourceSelect->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    sourceSelect->addListener (this);

    addAndMakeVisible (targetSelect = new ComboBox ("new combo box"));
    targetSelect->setEditableText (false);
    targetSelect->setJustificationType (Justification::centredLeft);
    targetSelect->setTextWhenNothingSelected (String::empty);
    targetSelect->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    targetSelect->addListener (this);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

ModulationEntryComponent::~ModulationEntryComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    scaleSlider = nullptr;
    sourceSelect = nullptr;
    targetSelect = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void ModulationEntryComponent::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::white);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void ModulationEntryComponent::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    scaleSlider->setBounds (getWidth() - 64, proportionOfHeight (0.5000f) - (64 / 2), 64, 64);
    sourceSelect->setBounds (0, (getHeight() / 2) - 24, getWidth() - 64, 24);
    targetSelect->setBounds (0, (getHeight() / 2), getWidth() - 64, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void ModulationEntryComponent::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == scaleSlider)
    {
        //[UserSliderCode_scaleSlider] -- add your slider handling code here..
        //[/UserSliderCode_scaleSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void ModulationEntryComponent::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == sourceSelect)
    {
        //[UserComboBoxCode_sourceSelect] -- add your combo box handling code here..
        //[/UserComboBoxCode_sourceSelect]
    }
    else if (comboBoxThatHasChanged == targetSelect)
    {
        //[UserComboBoxCode_targetSelect] -- add your combo box handling code here..
        //[/UserComboBoxCode_targetSelect]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="ModulationEntryComponent"
                 componentName="" parentClasses="public Component" constructorParams=""
                 variableInitialisers="" snapPixels="8" snapActive="1" snapShown="1"
                 overlayOpacity="0.330" fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ffffffff"/>
  <SLIDER name="new slider" id="41e30a8dc022f0cb" memberName="scaleSlider"
          virtualName="" explicitFocusOrder="0" pos="0Rr 49.929%c 64 64"
          min="0" max="1" int="0.001" style="RotaryHorizontalVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="40"
          textBoxHeight="20" skewFactor="1"/>
  <COMBOBOX name="new combo box" id="ceeef11a3363adfb" memberName="sourceSelect"
            virtualName="" explicitFocusOrder="0" pos="0 0Cr 64M 24" editable="0"
            layout="33" items="" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <COMBOBOX name="new combo box" id="1694f45c9257dfce" memberName="targetSelect"
            virtualName="" explicitFocusOrder="0" pos="0 0C 64M 24" editable="0"
            layout="33" items="" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
