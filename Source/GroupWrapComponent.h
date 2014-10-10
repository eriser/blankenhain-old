#ifndef GROUPWRAPCOMPONENT_H_INCLUDED
#define GROUPWRAPCOMPONENT_H_INCLUDED

#include "JuceHeader.h"

#include <utility>

template<typename Subcomponent>
class GroupWrapComponent : public GroupComponent {
public:
	template<typename... Args>
	GroupWrapComponent(Args&&... args) :
		subcomponent(std::forward<Args>(args)...)
	{
		addAndMakeVisible(subcomponent);
	}

	Subcomponent& getWrapped() {
		return subcomponent;
	} 

	void resized() override {
		// TODO remove constants
		subcomponent.setBounds(
			getLocalBounds().reduced(8, 12).translated(0, 4)
			);
	}

	void setName(const String &newName) override {
		setText(newName);
		GroupComponent::setName(newName);
	}

private:
	Subcomponent subcomponent;
};

#endif  // GROUPWRAPCOMPONENT_H_INCLUDED
