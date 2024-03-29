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

#ifndef __JUCE_HEADER_3DB5996FF2CF23E__
#define __JUCE_HEADER_3DB5996FF2CF23E__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
#include "PluginProcessor.h"
#include "ADSRComponent.h"
#include "GroupWrapComponent.h"
#include "LFOComponent.h"
#include "OscillatorComponent.h"
#include "FilterComponent.h"
#include "ModulationMatrixComponent.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class BlankenhainAudioProcessorEditor  : public AudioProcessorEditor,
                                         public Timer
{
public:
    //==============================================================================
    BlankenhainAudioProcessorEditor (BlankenhainAudioProcessor* ownerFilter);
    ~BlankenhainAudioProcessorEditor();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void timerCallback();
    BlankenhainAudioProcessor* getProcessor() const;
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    LookAndFeel_V3 lookAndFeel;
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<GroupWrapComponent<ADSRComponent>> adsr1Wrapper;
    ScopedPointer<GroupWrapComponent<LFOComponent>> lfo1Wrapper;
    ScopedPointer<GroupWrapComponent<ADSRComponent>> adsr2Wrapper;
    ScopedPointer<GroupWrapComponent<LFOComponent>> lfo2Wrapper;
    ScopedPointer<GroupWrapComponent<OscillatorComponent>> osc1Wrapper;
    ScopedPointer<GroupWrapComponent<OscillatorComponent>> osc2Wrapper;
    ScopedPointer<GroupWrapComponent<FilterComponent>> filter1Wrapper;
    ScopedPointer<GroupWrapComponent<FilterComponent>> filter2Wrapper;
    ScopedPointer<GroupWrapComponent<OscillatorComponent>> osc3Wrapper;
    ScopedPointer<GroupWrapComponent<ADSRComponent>> adsr3Wrapper;
    ScopedPointer<GroupWrapComponent<LFOComponent>> lfo3Wrapper;
    ScopedPointer<GroupWrapComponent<FilterComponent>> filter3Wrapper;
    ScopedPointer<GroupWrapComponent<ModulationMatrixComponent>> modMatrix;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (BlankenhainAudioProcessorEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_3DB5996FF2CF23E__
