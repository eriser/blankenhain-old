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

#ifndef __JUCE_HEADER_C67DDBB34A3E06D8__
#define __JUCE_HEADER_C67DDBB34A3E06D8__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
#include "ParameterEditor.h"

class BlankenhainAudioProcessor;
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class LFOComponent  : public Component,
                      public ParameterEditor,
                      public SliderListener,
                      public ComboBoxListener
{
public:
    //==============================================================================
    LFOComponent (BlankenhainAudioProcessor* processor_, int instance_);
    ~LFOComponent();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
	void updateUi() override;
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void sliderValueChanged (Slider* sliderThatWasMoved);
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged);



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	BlankenhainAudioProcessor* processor;
	int instance;
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<Slider> rateSlider;
    ScopedPointer<ComboBox> waveform;
    ScopedPointer<Slider> depthSlider;
    ScopedPointer<Label> label;
    ScopedPointer<Label> label2;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (LFOComponent)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_C67DDBB34A3E06D8__
