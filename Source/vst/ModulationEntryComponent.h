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

#ifndef __JUCE_HEADER_A1F77DC294F86BA2__
#define __JUCE_HEADER_A1F77DC294F86BA2__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"

class BlankenhainAudioProcessor;
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class ModulationEntryComponent  : public Component,
                                  public SliderListener,
                                  public ComboBoxListener
{
public:
    //==============================================================================
    ModulationEntryComponent (BlankenhainAudioProcessor* processor_, int instance_);
    ~ModulationEntryComponent();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void sliderValueChanged (Slider* sliderThatWasMoved);
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged);



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	bool isActive() const;

	BlankenhainAudioProcessor* processor;
	int instance;
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<Slider> scaleSlider;
    ScopedPointer<ComboBox> sourceSelect;
    ScopedPointer<ComboBox> targetSelect;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ModulationEntryComponent)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_A1F77DC294F86BA2__
