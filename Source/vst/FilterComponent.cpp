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
    addAndMakeVisible (frequencySlider = new Slider ("new slider"));
    frequencySlider->setRange (0, 1, 0.001);
    frequencySlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    frequencySlider->setTextBoxStyle (Slider::TextBoxBelow, false, 60, 20);
    frequencySlider->addListener (this);

    addAndMakeVisible (qSlider = new Slider ("new slider"));
    qSlider->setRange (0, 1, 0.001);
    qSlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    qSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 60, 20);
    qSlider->addListener (this);

    addAndMakeVisible (type = new ComboBox ("new combo box"));
    type->setEditableText (false);
    type->setJustificationType (Justification::centredLeft);
    type->setTextWhenNothingSelected (String::empty);
    type->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    type->addItem (TRANS("Off"), 1);
    type->addItem (TRANS("Lowpass"), 2);
    type->addItem (TRANS("Highpass"), 3);
    type->addItem (TRANS("Bandpass"), 4);
    type->addItem (TRANS("Notch"), 5);
    type->addListener (this);

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

    frequencySlider = nullptr;
    qSlider = nullptr;
    type = nullptr;
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

    frequencySlider->setBounds (proportionOfWidth (0.0000f), proportionOfHeight (0.0000f), proportionOfWidth (0.5006f), getHeight() - 44);
    qSlider->setBounds (proportionOfWidth (0.5006f), proportionOfHeight (0.0000f), proportionOfWidth (0.5006f), getHeight() - 44);
    type->setBounds (0, getHeight() - 24, proportionOfWidth (1.0000f), 24);
    label->setBounds (proportionOfWidth (0.0000f), getHeight() - 24 - 20, proportionOfWidth (0.5006f), 20);
    label2->setBounds (proportionOfWidth (0.5006f), getHeight() - 24 - 20, proportionOfWidth (0.5006f), 20);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void FilterComponent::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
	auto& parameters = processor->getParameters();
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == frequencySlider)
    {
        //[UserSliderCode_frequencySlider] -- add your slider handling code here..
		processor->setParameterNotifyingHost(
			parameters.getParameterIndex(ParameterType::FREQUENCY, instance),
			float(frequencySlider->getValue())
			);
        //[/UserSliderCode_frequencySlider]
    }
    else if (sliderThatWasMoved == qSlider)
    {
        //[UserSliderCode_qSlider] -- add your slider handling code here..
		processor->setParameterNotifyingHost(
			parameters.getParameterIndex(ParameterType::Q, instance),
			float(qSlider->getValue())
			);
        //[/UserSliderCode_qSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void FilterComponent::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == type)
    {
        //[UserComboBoxCode_type] -- add your combo box handling code here..
		FilterSettings& filter = processor->getSynth().channels[0].filters[instance];
		switch (type->getSelectedItemIndex()) {
		case -1:
		case 0:
			filter.active = false;
		case 1:
			filter.type = FilterType::LOWPASS;
			filter.active = true;
			break;
		case 2:
			filter.type = FilterType::HIGHPASS;
			filter.active = true;
			break;
		case 3:
			filter.type = FilterType::BANDPASS;
			filter.active = true;
			break;
		case 4:
			filter.type = FilterType::NOTCH;
			filter.active = true;
			break;
		}
        //[/UserComboBoxCode_type]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void FilterComponent::updateUi() {
	auto& parameters = processor->getParameters();
	frequencySlider->setValue(parameters.getParameter(ParameterType::FREQUENCY, instance));
	qSlider->setValue(parameters.getParameter(ParameterType::Q, instance));
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
  <SLIDER name="new slider" id="bdf7649dc12a8036" memberName="frequencySlider"
          virtualName="" explicitFocusOrder="0" pos="0% 0% 50.055% 44M"
          min="0" max="1" int="0.001" style="RotaryHorizontalVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="60"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="new slider" id="909826510df720ec" memberName="qSlider"
          virtualName="" explicitFocusOrder="0" pos="50.055% 0% 50.055% 44M"
          min="0" max="1" int="0.001" style="RotaryHorizontalVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="60"
          textBoxHeight="20" skewFactor="1"/>
  <COMBOBOX name="new combo box" id="770a46f46416bdaa" memberName="type"
            virtualName="" explicitFocusOrder="0" pos="0 0Rr 100% 24" editable="0"
            layout="33" items="Off&#10;Lowpass&#10;Highpass&#10;Bandpass&#10;Notch"
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
