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

#include "LFOComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
LFOComponent::LFOComponent (BlankenhainAudioProcessor* processor_, int instance_)
    : processor(processor_), instance(instance_)
{
    addAndMakeVisible (rateSlider = new Slider ("new slider"));
    rateSlider->setRange (0, 1, 0.001);
    rateSlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    rateSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 60, 20);
    rateSlider->addListener (this);

    addAndMakeVisible (waveform = new ComboBox ("new combo box"));
    waveform->setEditableText (false);
    waveform->setJustificationType (Justification::centredLeft);
    waveform->setTextWhenNothingSelected (String::empty);
    waveform->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    waveform->addItem (TRANS("Sine"), 1);
    waveform->addItem (TRANS("Triangle"), 2);
    waveform->addItem (TRANS("Square"), 3);
    waveform->addItem (TRANS("Noise"), 4);
    waveform->addListener (this);

    addAndMakeVisible (depthSlider = new Slider ("new slider"));
    depthSlider->setRange (0, 1, 0.001);
    depthSlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    depthSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 60, 20);
    depthSlider->addListener (this);

    addAndMakeVisible (label = new Label ("new label",
                                          TRANS("Rate")));
    label->setFont (Font (12.00f, Font::bold));
    label->setJustificationType (Justification::centred);
    label->setEditable (false, false, false);
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label2 = new Label ("new label",
                                           TRANS("Depth")));
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

LFOComponent::~LFOComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    rateSlider = nullptr;
    waveform = nullptr;
    depthSlider = nullptr;
    label = nullptr;
    label2 = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void LFOComponent::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::white);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void LFOComponent::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    rateSlider->setBounds (0, 0, proportionOfWidth (0.5005f), getHeight() - 44);
    waveform->setBounds (proportionOfWidth (0.0000f), getHeight() - 24, proportionOfWidth (1.0000f), 24);
    depthSlider->setBounds (proportionOfWidth (0.5005f), 0, proportionOfWidth (0.5005f), getHeight() - 44);
    label->setBounds (0, getHeight() - 24 - 20, proportionOfWidth (0.5005f), 20);
    label2->setBounds (proportionOfWidth (0.5005f), getHeight() - 24 - 20, proportionOfWidth (0.5005f), 20);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void LFOComponent::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
	auto& parameters = processor->getParameters();
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == rateSlider)
    {
        //[UserSliderCode_rateSlider] -- add your slider handling code here..
		processor->setParameterNotifyingHost(
			parameters.getParameterIndex(ParameterType::RATE, instance),
			float(rateSlider->getValue())
			);
        //[/UserSliderCode_rateSlider]
    }
    else if (sliderThatWasMoved == depthSlider)
    {
        //[UserSliderCode_depthSlider] -- add your slider handling code here..
		processor->setParameterNotifyingHost(
			parameters.getParameterIndex(ParameterType::DEPTH, instance),
			float(depthSlider->getValue())
			);
        //[/UserSliderCode_depthSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void LFOComponent::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == waveform)
    {
        //[UserComboBoxCode_waveform] -- add your combo box handling code here..
		LFOSettings& lfo = processor->getSynth().channels[0].lfos[instance];
		switch (waveform->getSelectedItemIndex()) {
		case -1:
		case 0:
			lfo.type = OscillatorType::SINE;
			break;
		case 1:
			lfo.type = OscillatorType::SAW;
			break;
		case 2:
			lfo.type = OscillatorType::SQUARE;
			break;
		case 3:
			lfo.type = OscillatorType::NOISE;
			break;
		}
        //[/UserComboBoxCode_waveform]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void LFOComponent::updateUi() {
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="LFOComponent" componentName=""
                 parentClasses="public Component, public ParameterEditor" constructorParams="BlankenhainAudioProcessor* processor_, int instance_"
                 variableInitialisers="processor(processor_), instance(instance_)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ffffffff"/>
  <SLIDER name="new slider" id="25adebd8cb2e4432" memberName="rateSlider"
          virtualName="" explicitFocusOrder="0" pos="0 0 50.049% 44M" min="0"
          max="1" int="0.001" style="RotaryHorizontalVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="60" textBoxHeight="20" skewFactor="1"/>
  <COMBOBOX name="new combo box" id="72f6ebc4b6994175" memberName="waveform"
            virtualName="" explicitFocusOrder="0" pos="0% 0Rr 100% 24" editable="0"
            layout="33" items="Sine&#10;Triangle&#10;Square&#10;Noise" textWhenNonSelected=""
            textWhenNoItems="(no choices)"/>
  <SLIDER name="new slider" id="2d5bc2faa83f1489" memberName="depthSlider"
          virtualName="" explicitFocusOrder="0" pos="50.049% 0 50.049% 44M"
          min="0" max="1" int="0.001" style="RotaryHorizontalVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="60"
          textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="67ad6162f890660c" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="0 24Rr 50.049% 20" edTextCol="ff000000"
         edBkgCol="0" labelText="Rate" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         bold="1" italic="0" justification="36"/>
  <LABEL name="new label" id="cffa3af2cdf400f2" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="50.049% 24Rr 50.049% 20" edTextCol="ff000000"
         edBkgCol="0" labelText="Depth" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         bold="1" italic="0" justification="36"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
