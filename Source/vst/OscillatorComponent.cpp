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

#include "OscillatorComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
OscillatorComponent::OscillatorComponent (BlankenhainAudioProcessor* processor_, int instance_)
    : processor(processor_), instance(instance_)
{
    addAndMakeVisible (volumeSlider = new Slider ("new slider"));
    volumeSlider->setRange (0, 1, 0.001);
    volumeSlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    volumeSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    volumeSlider->addListener (this);

    addAndMakeVisible (detuneSlider = new Slider ("new slider"));
    detuneSlider->setRange (-0.5, 0.5, 0.001);
    detuneSlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    detuneSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    detuneSlider->addListener (this);

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

    addAndMakeVisible (waveform = new ComboBox ("new combo box"));
    waveform->setEditableText (false);
    waveform->setJustificationType (Justification::centredLeft);
    waveform->setTextWhenNothingSelected (String::empty);
    waveform->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    waveform->addItem (TRANS("Sine"), 1);
    waveform->addItem (TRANS("Saw"), 2);
    waveform->addItem (TRANS("Square"), 3);
    waveform->addItem (TRANS("Noise"), 4);
    waveform->addListener (this);

    addAndMakeVisible (pitchSlider = new Slider ("new slider"));
    pitchSlider->setRange (-24, 24, 1);
    pitchSlider->setSliderStyle (Slider::IncDecButtons);
    pitchSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    pitchSlider->addListener (this);

    addAndMakeVisible (label3 = new Label ("new label",
                                           TRANS("Pitch")));
    label3->setFont (Font (12.00f, Font::bold));
    label3->setJustificationType (Justification::centred);
    label3->setEditable (false, false, false);
    label3->setColour (TextEditor::textColourId, Colours::black);
    label3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));


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

    volumeSlider = nullptr;
    detuneSlider = nullptr;
    label = nullptr;
    label2 = nullptr;
    waveform = nullptr;
    pitchSlider = nullptr;
    label3 = nullptr;


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

    volumeSlider->setBounds (proportionOfWidth (0.0000f), proportionOfHeight (0.0000f), proportionOfWidth (0.3333f), getHeight() - 44);
    detuneSlider->setBounds (proportionOfWidth (0.3333f), proportionOfHeight (0.0000f), proportionOfWidth (0.3333f), getHeight() - 44);
    label->setBounds (proportionOfWidth (0.0000f), getHeight() - 24 - 20, proportionOfWidth (0.3333f), 20);
    label2->setBounds (proportionOfWidth (0.3333f), getHeight() - 24 - 20, proportionOfWidth (0.3333f), 20);
    waveform->setBounds (0, getHeight() - 24, proportionOfWidth (1.0000f), 24);
    pitchSlider->setBounds (proportionOfWidth (0.6667f), 0, proportionOfWidth (0.3333f), getHeight() - 44);
    label3->setBounds (proportionOfWidth (0.6667f), getHeight() - 24 - 20, proportionOfWidth (0.3333f), 20);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void OscillatorComponent::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
	auto& parameters = processor->getParameters();
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == volumeSlider)
    {
        //[UserSliderCode_volumeSlider] -- add your slider handling code here..
		processor->setParameterNotifyingHost(
			parameters.getParameterIndex(ParameterType::VOLUME, instance),
			float(volumeSlider->getValue())
			);
        //[/UserSliderCode_volumeSlider]
    }
    else if (sliderThatWasMoved == detuneSlider)
    {
        //[UserSliderCode_detuneSlider] -- add your slider handling code here..
		processor->setParameterNotifyingHost(
			parameters.getParameterIndex(ParameterType::DETUNE, instance),
			float(detuneSlider->getValue() + 0.5)
			);
        //[/UserSliderCode_detuneSlider]
    }
    else if (sliderThatWasMoved == pitchSlider)
    {
        //[UserSliderCode_pitchSlider] -- add your slider handling code here..
		OscillatorSettings& osc = processor->getSynth().channels[0].oscillators[instance];
		osc.pitch = pitchSlider->getValue();
        //[/UserSliderCode_pitchSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void OscillatorComponent::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == waveform)
    {
        //[UserComboBoxCode_waveform] -- add your combo box handling code here..
		OscillatorSettings& osc = processor->getSynth().channels[0].oscillators[instance];
		switch (waveform->getSelectedItemIndex()) {
		case -1:
		case 0:
			osc.type = OscillatorType::SINE;
			break;
		case 1:
			osc.type = OscillatorType::SAW;
			break;
		case 2:
			osc.type = OscillatorType::SQUARE;
			break;
		case 3:
			osc.type = OscillatorType::NOISE;
			break;
		}
        //[/UserComboBoxCode_waveform]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void OscillatorComponent::updateUi() {
	auto& parameters = processor->getParameters();
	volumeSlider->setValue(parameters.getParameter(ParameterType::VOLUME, instance));
	detuneSlider->setValue(parameters.getParameter(ParameterType::DETUNE, instance) - 0.5);
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="OscillatorComponent" componentName=""
                 parentClasses="public Component, public ParameterEditor" constructorParams="BlankenhainAudioProcessor* processor_, int instance_"
                 variableInitialisers="processor(processor_), instance(instance_)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ffffffff"/>
  <SLIDER name="new slider" id="4cab75d38a92f601" memberName="volumeSlider"
          virtualName="" explicitFocusOrder="0" pos="0% 0% 33.333% 44M"
          min="0" max="1" int="0.001" style="RotaryHorizontalVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="new slider" id="ee71613e67685acd" memberName="detuneSlider"
          virtualName="" explicitFocusOrder="0" pos="33.333% 0% 33.333% 44M"
          min="-0.5" max="0.5" int="0.001" style="RotaryHorizontalVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="a77810f2419b4201" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="0% 24Rr 33.333% 20" edTextCol="ff000000"
         edBkgCol="0" labelText="Volume" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         bold="1" italic="0" justification="36"/>
  <LABEL name="new label" id="b86b55cdd1b4a36b" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="33.333% 24Rr 33.333% 20" edTextCol="ff000000"
         edBkgCol="0" labelText="Detune" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         bold="1" italic="0" justification="36"/>
  <COMBOBOX name="new combo box" id="c053bb5657af7345" memberName="waveform"
            virtualName="" explicitFocusOrder="0" pos="0 0Rr 100% 24" editable="0"
            layout="33" items="Sine&#10;Saw&#10;Square&#10;Noise" textWhenNonSelected=""
            textWhenNoItems="(no choices)"/>
  <SLIDER name="new slider" id="21563aac9563ca7" memberName="pitchSlider"
          virtualName="" explicitFocusOrder="0" pos="66.667% 0 33.333% 44M"
          min="-24" max="24" int="1" style="IncDecButtons" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="4a6d1b95ff8c9732" memberName="label3" virtualName=""
         explicitFocusOrder="0" pos="66.667% 24Rr 33.333% 20" edTextCol="ff000000"
         edBkgCol="0" labelText="Pitch" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         bold="1" italic="0" justification="36"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
