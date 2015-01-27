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
#include "PluginProcessor.h"

using namespace blankenhain;
//[/Headers]

#include "FilterComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
FilterComponent::FilterComponent (BlankenhainAudioProcessor* processor_, int instance_)
    : processor(processor_), instance(instance_)
{
    addAndMakeVisible (slider = new Slider ("new slider"));
    slider->setRange (0, 1, 0.001);
    slider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    slider->setTextBoxStyle (Slider::TextBoxBelow, false, 60, 20);
    slider->addListener (this);

    addAndMakeVisible (slider2 = new Slider ("new slider"));
    slider2->setRange (0, 1, 0.001);
    slider2->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    slider2->setTextBoxStyle (Slider::TextBoxBelow, false, 60, 20);
    slider2->addListener (this);

    addAndMakeVisible (comboBox = new ComboBox ("new combo box"));
    comboBox->setEditableText (false);
    comboBox->setJustificationType (Justification::centredLeft);
    comboBox->setTextWhenNothingSelected (String::empty);
    comboBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    comboBox->addItem (TRANS("Lowpass"), 1);
    comboBox->addItem (TRANS("Highpass"), 2);
    comboBox->addItem (TRANS("Bandpass"), 3);
    comboBox->addItem (TRANS("Notch"), 4);
    comboBox->addListener (this);

    addAndMakeVisible (label = new Label ("new label",
                                          TRANS("Frequency")));
    label->setFont (Font (12.00f, Font::bold));
    label->setJustificationType (Justification::centred);
    label->setEditable (false, false, false);
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label2 = new Label ("new label",
                                           TRANS("Q")));
    label2->setFont (Font (12.00f, Font::bold));
    label2->setJustificationType (Justification::centred);
    label2->setEditable (false, false, false);
    label2->setColour (TextEditor::textColourId, Colours::black);
    label2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

FilterComponent::~FilterComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    slider = nullptr;
    slider2 = nullptr;
    comboBox = nullptr;
    label = nullptr;
    label2 = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void FilterComponent::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::white);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void FilterComponent::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    slider->setBounds (proportionOfWidth (0.0000f), proportionOfHeight (0.0000f), proportionOfWidth (0.5000f), getHeight() - 44);
    slider2->setBounds (proportionOfWidth (0.5000f), proportionOfHeight (0.0000f), proportionOfWidth (0.5000f), getHeight() - 44);
    comboBox->setBounds (0, getHeight() - 24, proportionOfWidth (1.0000f), 24);
    label->setBounds (proportionOfWidth (0.0000f), getHeight() - 24 - 20, proportionOfWidth (0.5000f), 20);
    label2->setBounds (proportionOfWidth (0.5000f), getHeight() - 24 - 20, proportionOfWidth (0.5000f), 20);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void FilterComponent::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
	auto& parameters = processor->getParameters();
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == slider)
    {
        //[UserSliderCode_slider] -- add your slider handling code here..
		processor->setParameterNotifyingHost(
			parameters.getParameterIndex(ParameterType::FREQUENCY, instance),
			float(slider->getValue())
			);
        //[/UserSliderCode_slider]
    }
    else if (sliderThatWasMoved == slider2)
    {
        //[UserSliderCode_slider2] -- add your slider handling code here..
		processor->setParameterNotifyingHost(
			parameters.getParameterIndex(ParameterType::Q, instance),
			float(slider2->getValue())
			);
        //[/UserSliderCode_slider2]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void FilterComponent::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
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
void FilterComponent::updateUi() {
	auto& parameters = processor->getParameters();
	slider->setValue(parameters.getParameter(ParameterType::FREQUENCY, instance));
	slider2->setValue(parameters.getParameter(ParameterType::Q, instance));
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="FilterComponent" componentName=""
                 parentClasses="public Component, public ParameterEditor" constructorParams="BlankenhainAudioProcessor* processor_, int instance_"
                 variableInitialisers="processor(processor_), instance(instance_)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ffffffff"/>
  <SLIDER name="new slider" id="bdf7649dc12a8036" memberName="slider" virtualName=""
          explicitFocusOrder="0" pos="0% 0% 50.055% 44M" min="0" max="1"
          int="0.001" style="RotaryHorizontalVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="60" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="new slider" id="909826510df720ec" memberName="slider2"
          virtualName="" explicitFocusOrder="0" pos="50.055% 0% 50.055% 44M"
          min="0" max="1" int="0.001" style="RotaryHorizontalVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="60"
          textBoxHeight="20" skewFactor="1"/>
  <COMBOBOX name="new combo box" id="770a46f46416bdaa" memberName="comboBox"
            virtualName="" explicitFocusOrder="0" pos="0 0Rr 100% 24" editable="0"
            layout="33" items="Lowpass&#10;Highpass&#10;Bandpass&#10;Notch"
            textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <LABEL name="new label" id="588176d33db6e210" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="0% 24Rr 50.055% 20" edTextCol="ff000000"
         edBkgCol="0" labelText="Frequency" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         bold="1" italic="0" justification="36"/>
  <LABEL name="new label" id="595b247720b88f8" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="50.055% 24Rr 50.055% 20" edTextCol="ff000000"
         edBkgCol="0" labelText="Q" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         bold="1" italic="0" justification="36"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
