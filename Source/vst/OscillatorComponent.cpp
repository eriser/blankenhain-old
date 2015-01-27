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

#include "OscillatorComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
OscillatorComponent::OscillatorComponent ()
{
    addAndMakeVisible (slider = new Slider ("new slider"));
    slider->setRange (0, 1, 0.001);
    slider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    slider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    slider->addListener (this);

    addAndMakeVisible (slider2 = new Slider ("new slider"));
    slider2->setRange (-0.5, 0.5, 0.001);
    slider2->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    slider2->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    slider2->addListener (this);

    addAndMakeVisible (label = new Label ("new label",
                                          TRANS("Volume")));
    label->setFont (Font (12.00f, Font::bold));
    label->setJustificationType (Justification::centred);
    label->setEditable (false, false, false);
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label2 = new Label ("new label",
                                           TRANS("Detune")));
    label2->setFont (Font (12.00f, Font::bold));
    label2->setJustificationType (Justification::centred);
    label2->setEditable (false, false, false);
    label2->setColour (TextEditor::textColourId, Colours::black);
    label2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (comboBox = new ComboBox ("new combo box"));
    comboBox->setEditableText (false);
    comboBox->setJustificationType (Justification::centredLeft);
    comboBox->setTextWhenNothingSelected (String::empty);
    comboBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    comboBox->addItem (TRANS("Sine"), 1);
    comboBox->addItem (TRANS("Saw"), 2);
    comboBox->addItem (TRANS("Square"), 3);
    comboBox->addItem (TRANS("Noise"), 4);
    comboBox->addListener (this);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

OscillatorComponent::~OscillatorComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    slider = nullptr;
    slider2 = nullptr;
    label = nullptr;
    label2 = nullptr;
    comboBox = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void OscillatorComponent::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::white);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void OscillatorComponent::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    slider->setBounds (proportionOfWidth (0.0000f), proportionOfHeight (0.0000f), proportionOfWidth (0.5000f), getHeight() - 44);
    slider2->setBounds (proportionOfWidth (0.5000f), proportionOfHeight (0.0000f), proportionOfWidth (0.5000f), getHeight() - 44);
    label->setBounds (proportionOfWidth (0.0000f), getHeight() - 24 - 20, proportionOfWidth (0.5000f), 20);
    label2->setBounds (proportionOfWidth (0.5000f), getHeight() - 24 - 20, proportionOfWidth (0.5000f), 20);
    comboBox->setBounds (0, getHeight() - 24, proportionOfWidth (1.0000f), 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void OscillatorComponent::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == slider)
    {
        //[UserSliderCode_slider] -- add your slider handling code here..
        //[/UserSliderCode_slider]
    }
    else if (sliderThatWasMoved == slider2)
    {
        //[UserSliderCode_slider2] -- add your slider handling code here..
        //[/UserSliderCode_slider2]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void OscillatorComponent::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == comboBox)
    {
        //[UserComboBoxCode_comboBox] -- add your combo box handling code here..
        //[/UserComboBoxCode_comboBox]
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

<JUCER_COMPONENT documentType="Component" className="OscillatorComponent" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ffffffff"/>
  <SLIDER name="new slider" id="4cab75d38a92f601" memberName="slider" virtualName=""
          explicitFocusOrder="0" pos="0% 0% 50% 44M" min="0" max="1" int="0.001"
          style="RotaryHorizontalVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="new slider" id="ee71613e67685acd" memberName="slider2"
          virtualName="" explicitFocusOrder="0" pos="50% 0% 50% 44M" min="-0.5"
          max="0.5" int="0.001" style="RotaryHorizontalVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="a77810f2419b4201" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="0% 24Rr 50% 20" edTextCol="ff000000"
         edBkgCol="0" labelText="Volume" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         bold="1" italic="0" justification="36"/>
  <LABEL name="new label" id="b86b55cdd1b4a36b" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="50% 24Rr 50% 20" edTextCol="ff000000"
         edBkgCol="0" labelText="Detune" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         bold="1" italic="0" justification="36"/>
  <COMBOBOX name="new combo box" id="c053bb5657af7345" memberName="comboBox"
            virtualName="" explicitFocusOrder="0" pos="0 0Rr 100% 24" editable="0"
            layout="33" items="Sine&#10;Saw&#10;Square&#10;Noise" textWhenNonSelected=""
            textWhenNoItems="(no choices)"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
