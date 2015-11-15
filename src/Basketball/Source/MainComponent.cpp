/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"

namespace {

enum WindowParameter : int {
	kWindowWidth = 600,
	kWindowHeight = 400
};

};

//==============================================================================
MainContentComponent::MainContentComponent()
{
	setSize(kWindowWidth, kWindowHeight);
	InitialButton(*this);
}

MainContentComponent::~MainContentComponent()
{
}

void MainContentComponent::paint (Graphics& g)
{
	g.fillAll(Colour(0xff7DB9DE));

    g.setFont (Font (16.0f));
    g.setColour (Colours::white);
    g.drawText ("Hello World!", getLocalBounds(), Justification::centred, true);
}

void MainContentComponent::resized()
{
    // This is called when the MainContentComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
}

void MainContentComponent::InitialButton(Component& parent)
{
	upgrade_device_button_.setButtonText("TEST");
	upgrade_device_button_.addListener(this);
	upgrade_device_button_.setEnabled(true);
	upgrade_device_button_.setColour(TextButton::buttonColourId, Colours::green);
	upgrade_device_button_.setColour(TextButton::textColourOffId, Colours::white);
	upgrade_device_button_.setBounds(20, 350, 50, 20);
	upgrade_device_button_.changeWidthToFitText();
	upgrade_device_button_.setCentrePosition(parent.getWidth() / 3 ,
											 parent.getHeight() / 3);
	parent.addAndMakeVisible(upgrade_device_button_);
}

void MainContentComponent::buttonClicked(Button* b)
{
	if (b == &upgrade_device_button_) {
		if (upgrade_device_button_.getButtonText().equalsIgnoreCase("Start"))
			setButtonToFinish();
		else
			setButtonToStart();
	}
}

void MainContentComponent::setButtonToStart()
{
	upgrade_device_button_.setButtonText("Start");
	upgrade_device_button_.changeWidthToFitText();
	upgrade_device_button_.setColour(TextButton::buttonColourId, Colours::green);
	upgrade_device_button_.setColour(TextButton::textColourOffId, Colours::white);
}

void MainContentComponent::setButtonToFinish()
{
	upgrade_device_button_.setButtonText("Finishhhhhhhhhhhhhhhhhhhh");
	upgrade_device_button_.changeWidthToFitText();
	upgrade_device_button_.setColour(TextButton::buttonColourId, Colours::red);
	upgrade_device_button_.setColour(TextButton::textColourOffId, Colours::gold);
}