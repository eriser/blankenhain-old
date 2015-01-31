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

#include "ModulationMatrixComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
ModulationMatrixComponent::ModulationMatrixComponent (BlankenhainAudioProcessor* processor_)
    : processor(processor_)
{
    addAndMakeVisible (modEntry1 = new ModulationEntryComponent (processor, 0));
    modEntry1->setName ("new component");

    addAndMakeVisible (modEntry2 = new ModulationEntryComponent (processor, 1));
    modEntry2->setName ("new component");

    addAndMakeVisible (modEntry3 = new ModulationEntryComponent (processor, 2));
    modEntry3->setName ("new component");

    addAndMakeVisible (modEntry4 = new ModulationEntryComponent (processor, 3));
    modEntry4->setName ("new component");

    addAndMakeVisible (modEntry5 = new ModulationEntryComponent (processor, 4));
    modEntry5->setName ("new component");

    addAndMakeVisible (modEntry6 = new ModulationEntryComponent (processor, 5));
    modEntry6->setName ("new component");

    addAndMakeVisible (modEntry7 = new ModulationEntryComponent (processor, 6));
    modEntry7->setName ("new component");

    addAndMakeVisible (modEntry8 = new ModulationEntryComponent (processor, 7));
    modEntry8->setName ("new component");


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

ModulationMatrixComponent::~ModulationMatrixComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    modEntry1 = nullptr;
    modEntry2 = nullptr;
    modEntry3 = nullptr;
    modEntry4 = nullptr;
    modEntry5 = nullptr;
    modEntry6 = nullptr;
    modEntry7 = nullptr;
    modEntry8 = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void ModulationMatrixComponent::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::white);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void ModulationMatrixComponent::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    modEntry1->setBounds (proportionOfWidth (0.0000f), proportionOfHeight (0.0000f), proportionOfWidth (1.0000f), proportionOfHeight (0.1242f));
    modEntry2->setBounds (proportionOfWidth (0.0000f), proportionOfHeight (0.1242f), proportionOfWidth (1.0000f), proportionOfHeight (0.1242f));
    modEntry3->setBounds (proportionOfWidth (0.0000f), proportionOfHeight (0.2497f), proportionOfWidth (1.0000f), proportionOfHeight (0.1242f));
    modEntry4->setBounds (proportionOfWidth (0.0000f), proportionOfHeight (0.3739f), proportionOfWidth (1.0000f), proportionOfHeight (0.1242f));
    modEntry5->setBounds (proportionOfWidth (0.0000f), proportionOfHeight (0.4994f), proportionOfWidth (1.0000f), proportionOfHeight (0.1242f));
    modEntry6->setBounds (proportionOfWidth (0.0000f), proportionOfHeight (0.6261f), proportionOfWidth (1.0000f), proportionOfHeight (0.1242f));
    modEntry7->setBounds (proportionOfWidth (0.0000f), proportionOfHeight (0.7503f), proportionOfWidth (1.0000f), proportionOfHeight (0.1242f));
    modEntry8->setBounds (proportionOfWidth (0.0000f), proportionOfHeight (0.8758f), proportionOfWidth (1.0000f), proportionOfHeight (0.1242f));
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="ModulationMatrixComponent"
                 componentName="" parentClasses="public Component" constructorParams="BlankenhainAudioProcessor* processor_"
                 variableInitialisers="processor(processor_)" snapPixels="8" snapActive="1"
                 snapShown="1" overlayOpacity="0.330" fixedSize="0" initialWidth="600"
                 initialHeight="400">
  <BACKGROUND backgroundColour="ffffffff"/>
  <GENERICCOMPONENT name="new component" id="29434151a6d777cc" memberName="modEntry1"
                    virtualName="" explicitFocusOrder="0" pos="0% 0% 100% 12.421%"
                    class="ModulationEntryComponent" params="processor, 0"/>
  <GENERICCOMPONENT name="new component" id="2e1196520b9dfd6b" memberName="modEntry2"
                    virtualName="" explicitFocusOrder="0" pos="0% 12.421% 100% 12.421%"
                    class="ModulationEntryComponent" params="processor, 1"/>
  <GENERICCOMPONENT name="new component" id="9235682affc39bad" memberName="modEntry3"
                    virtualName="" explicitFocusOrder="0" pos="0% 24.968% 100% 12.421%"
                    class="ModulationEntryComponent" params="processor, 2"/>
  <GENERICCOMPONENT name="new component" id="6c0b6a2ac7e5aa47" memberName="modEntry4"
                    virtualName="" explicitFocusOrder="0" pos="0% 37.389% 100% 12.421%"
                    class="ModulationEntryComponent" params="processor, 3"/>
  <GENERICCOMPONENT name="new component" id="ed0815d6618b2074" memberName="modEntry5"
                    virtualName="" explicitFocusOrder="0" pos="0% 49.937% 100% 12.421%"
                    class="ModulationEntryComponent" params="processor, 4"/>
  <GENERICCOMPONENT name="new component" id="8ff6673661f7a5fa" memberName="modEntry6"
                    virtualName="" explicitFocusOrder="0" pos="0% 62.611% 100% 12.421%"
                    class="ModulationEntryComponent" params="processor, 5"/>
  <GENERICCOMPONENT name="new component" id="bc4fba5e4a42b6b" memberName="modEntry7"
                    virtualName="" explicitFocusOrder="0" pos="0% 75.032% 100% 12.421%"
                    class="ModulationEntryComponent" params="processor, 6"/>
  <GENERICCOMPONENT name="new component" id="6a05c9e8e97242a8" memberName="modEntry8"
                    virtualName="" explicitFocusOrder="0" pos="0% 87.579% 100% 12.421%"
                    class="ModulationEntryComponent" params="processor, 7"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
