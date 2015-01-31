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
ModulationMatrixComponent::ModulationMatrixComponent ()
{
    addAndMakeVisible (modEntry1 = new ModulationEntryComponent());
    modEntry1->setName ("new component");

    addAndMakeVisible (modEntry2 = new ModulationEntryComponent());
    modEntry2->setName ("new component");

    addAndMakeVisible (modEntry3 = new ModulationEntryComponent());
    modEntry3->setName ("new component");

    addAndMakeVisible (modEntry4 = new ModulationEntryComponent());
    modEntry4->setName ("new component");

    addAndMakeVisible (modEntry5 = new ModulationEntryComponent());
    modEntry5->setName ("new component");

    addAndMakeVisible (modEntry6 = new ModulationEntryComponent());
    modEntry6->setName ("new component");

    addAndMakeVisible (modEntry7 = new ModulationEntryComponent());
    modEntry7->setName ("new component");

    addAndMakeVisible (modEntry8 = new ModulationEntryComponent());
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

    modEntry1->setBounds (proportionOfWidth (0.0000f), proportionOfHeight (0.0000f), proportionOfWidth (1.0000f), proportionOfHeight (0.1250f));
    modEntry2->setBounds (proportionOfWidth (0.0000f), proportionOfHeight (0.1250f), proportionOfWidth (1.0000f), proportionOfHeight (0.1250f));
    modEntry3->setBounds (proportionOfWidth (0.0000f), proportionOfHeight (0.2500f), proportionOfWidth (1.0000f), proportionOfHeight (0.1250f));
    modEntry4->setBounds (proportionOfWidth (0.0000f), proportionOfHeight (0.3750f), proportionOfWidth (1.0000f), proportionOfHeight (0.1250f));
    modEntry5->setBounds (proportionOfWidth (0.0000f), proportionOfHeight (0.5000f), proportionOfWidth (1.0000f), proportionOfHeight (0.1250f));
    modEntry6->setBounds (proportionOfWidth (0.0000f), proportionOfHeight (0.6250f), proportionOfWidth (1.0000f), proportionOfHeight (0.1250f));
    modEntry7->setBounds (proportionOfWidth (0.0000f), proportionOfHeight (0.7500f), proportionOfWidth (1.0000f), proportionOfHeight (0.1250f));
    modEntry8->setBounds (proportionOfWidth (0.0000f), proportionOfHeight (0.8750f), proportionOfWidth (1.0000f), proportionOfHeight (0.1250f));
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
                 componentName="" parentClasses="public Component" constructorParams=""
                 variableInitialisers="" snapPixels="8" snapActive="1" snapShown="1"
                 overlayOpacity="0.330" fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ffffffff"/>
  <GENERICCOMPONENT name="new component" id="29434151a6d777cc" memberName="modEntry1"
                    virtualName="" explicitFocusOrder="0" pos="0% 0% 100% 12.482%"
                    class="ModulationEntryComponent" params=""/>
  <GENERICCOMPONENT name="new component" id="2e1196520b9dfd6b" memberName="modEntry2"
                    virtualName="" explicitFocusOrder="0" pos="0% 12.482% 100% 12.482%"
                    class="ModulationEntryComponent" params=""/>
  <GENERICCOMPONENT name="new component" id="9235682affc39bad" memberName="modEntry3"
                    virtualName="" explicitFocusOrder="0" pos="0% 24.965% 100% 12.482%"
                    class="ModulationEntryComponent" params=""/>
  <GENERICCOMPONENT name="new component" id="6c0b6a2ac7e5aa47" memberName="modEntry4"
                    virtualName="" explicitFocusOrder="0" pos="0% 37.447% 100% 12.482%"
                    class="ModulationEntryComponent" params=""/>
  <GENERICCOMPONENT name="new component" id="ed0815d6618b2074" memberName="modEntry5"
                    virtualName="" explicitFocusOrder="0" pos="0% 49.929% 100% 12.482%"
                    class="ModulationEntryComponent" params=""/>
  <GENERICCOMPONENT name="new component" id="8ff6673661f7a5fa" memberName="modEntry6"
                    virtualName="" explicitFocusOrder="0" pos="0% 62.553% 100% 12.482%"
                    class="ModulationEntryComponent" params=""/>
  <GENERICCOMPONENT name="new component" id="bc4fba5e4a42b6b" memberName="modEntry7"
                    virtualName="" explicitFocusOrder="0" pos="0% 75.035% 100% 12.482%"
                    class="ModulationEntryComponent" params=""/>
  <GENERICCOMPONENT name="new component" id="6a05c9e8e97242a8" memberName="modEntry8"
                    virtualName="" explicitFocusOrder="0" pos="0% 87.518% 100% 12.482%"
                    class="ModulationEntryComponent" params=""/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
