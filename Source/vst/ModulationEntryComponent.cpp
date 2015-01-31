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

#include "ModulationEntryComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
ModulationEntryComponent::ModulationEntryComponent (BlankenhainAudioProcessor* processor_, int instance_)
    : processor(processor_), instance(instance_)
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
    sourceSelect->addItem (TRANS("Envelope1"), 1);
    sourceSelect->addItem (TRANS("Envelope2"), 2);
    sourceSelect->addItem (TRANS("Envelope3"), 3);
    sourceSelect->addItem (TRANS("LFO1"), 4);
    sourceSelect->addItem (TRANS("LFO2"), 5);
    sourceSelect->addItem (TRANS("LFO3"), 6);
    sourceSelect->addListener (this);

    addAndMakeVisible (targetSelect = new ComboBox ("new combo box"));
    targetSelect->setEditableText (false);
    targetSelect->setJustificationType (Justification::centredLeft);
    targetSelect->setTextWhenNothingSelected (String::empty);
    targetSelect->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    targetSelect->addItem (TRANS("Volume1"), 1);
    targetSelect->addItem (TRANS("Volume2"), 2);
    targetSelect->addItem (TRANS("Volume3"), 3);
    targetSelect->addItem (TRANS("Detune1"), 4);
    targetSelect->addItem (TRANS("Detune2"), 5);
    targetSelect->addItem (TRANS("Detune3"), 6);
    targetSelect->addItem (TRANS("Frequency1"), 7);
    targetSelect->addItem (TRANS("Frequency2"), 8);
    targetSelect->addItem (TRANS("Frequency3"), 9);
    targetSelect->addItem (TRANS("Q1"), 10);
    targetSelect->addItem (TRANS("Q2"), 11);
    targetSelect->addItem (TRANS("Q3"), 12);
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

    scaleSlider->setBounds (getWidth() - 64, proportionOfHeight (0.4994f) - (64 / 2), 64, 64);
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
		Modulation& mod = processor->getSynth().channels[0].modulationMatrix.entries[instance];
		const float value(scaleSlider->getValue());
		mod.scale = value;
		mod.active = isActive();
        //[/UserSliderCode_scaleSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void ModulationEntryComponent::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
	Modulation& mod = processor->getSynth().channels[0].modulationMatrix.entries[instance];
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == sourceSelect)
    {
        //[UserComboBoxCode_sourceSelect] -- add your combo box handling code here..
		const int index = sourceSelect->getSelectedItemIndex();
		switch (index) {
		case 0:
		case 1:
		case 2:
			mod.source = ModulationSource::ENVELOPE;
			mod.sourceIndex = index;
			break;
		case 3:
		case 4:
		case 5:
			mod.source = ModulationSource::LFO;
			mod.sourceIndex = index - 3;
			break;
		}
		mod.active = isActive();
        //[/UserComboBoxCode_sourceSelect]
    }
    else if (comboBoxThatHasChanged == targetSelect)
    {
        //[UserComboBoxCode_targetSelect] -- add your combo box handling code here..
		const int index = targetSelect->getSelectedItemIndex();
		switch (index) {
		case 0:
		case 1:
		case 2:
			mod.target = ModulationTarget::VOLUME;
			mod.targetIndex = index;
			break;
		case 3:
		case 4:
		case 5:
			mod.target = ModulationTarget::DETUNE;
			mod.targetIndex = index - 3;
			break;
		case 6:
		case 7:
		case 8:
			mod.target = ModulationTarget::FILTER_CUTOFF;
			mod.targetIndex = index - 6;
			break;
		case 9:
		case 10:
		case 11:
			mod.target = ModulationTarget::FILTER_Q;
			mod.targetIndex = index - 9;
			break;
		}
		mod.active = isActive();
        //[/UserComboBoxCode_targetSelect]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
bool ModulationEntryComponent::isActive() const {
	return scaleSlider->getValue() > 0.f && sourceSelect->getSelectedItemIndex() != -1 && targetSelect->getSelectedItemIndex() != -1;
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="ModulationEntryComponent"
                 componentName="" parentClasses="public Component" constructorParams="BlankenhainAudioProcessor* processor_, int instance_"
                 variableInitialisers="processor(processor_), instance(instance_)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ffffffff"/>
  <SLIDER name="new slider" id="41e30a8dc022f0cb" memberName="scaleSlider"
          virtualName="" explicitFocusOrder="0" pos="0Rr 49.937%c 64 64"
          min="0" max="1" int="0.001" style="RotaryHorizontalVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="40"
          textBoxHeight="20" skewFactor="1"/>
  <COMBOBOX name="new combo box" id="ceeef11a3363adfb" memberName="sourceSelect"
            virtualName="" explicitFocusOrder="0" pos="0 0Cr 64M 24" editable="0"
            layout="33" items="Envelope1&#10;Envelope2&#10;Envelope3&#10;LFO1&#10;LFO2&#10;LFO3"
            textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <COMBOBOX name="new combo box" id="1694f45c9257dfce" memberName="targetSelect"
            virtualName="" explicitFocusOrder="0" pos="0 0C 64M 24" editable="0"
            layout="33" items="Volume1&#10;Volume2&#10;Volume3&#10;Detune1&#10;Detune2&#10;Detune3&#10;Frequency1&#10;Frequency2&#10;Frequency3&#10;Q1&#10;Q2&#10;Q3"
            textWhenNonSelected="" textWhenNoItems="(no choices)"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
