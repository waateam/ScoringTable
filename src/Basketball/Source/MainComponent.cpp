/*
  ==============================================================================

	This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"

const char kScoreFontName[] = "Segoe UI";

namespace {

enum WindowParameter : int {
	kWindowWidth = 600,
	kWindowHeight = 400
};

void InitialControlScoreTextButton(TextButton& button,
								   Component& parent,
								   const String& button_text = String::empty,
								   int x = 0,
								   int y = 0,
								   Colour button_color = Colours::white,
								   Colour text_color = Colours::black)
{
	button.setButtonText(button_text);
	button.setEnabled(true);
	button.setColour(TextButton::buttonColourId, button_color);
	button.setColour(TextButton::textColourOffId, text_color);
	button.setBounds(x,
					 y,
					 50,
					 20);
	button.changeWidthToFitText();
	parent.addAndMakeVisible(button);
}

};

//==============================================================================
MainContentComponent::MainContentComponent()
{
	setSize(kWindowWidth, kWindowHeight);
	InitialHomeScoreLabel(*this);
	InitialGuestScoreLabel(*this);
	InitialHomeScoreIncreaseButton(*this, home_score_label_);
	InitialHomeScoreDecreaseButton(*this, home_score_increase_button_);
	InitialGuestScorePlusButton(*this, guest_score_label_);
	InitialGuestScoreDecreaseButton(*this, guest_score_increase_button_);
}

MainContentComponent::~MainContentComponent()
{
}

void MainContentComponent::paint (Graphics& g)
{
	g.fillAll(Colour(0xff7DB9DE));

	g.setFont (Font (48.0f));
	g.setColour (Colours::white);

	g.drawText ("Score Table Test",
				juce::Rectangle<int>(getLocalBounds().getWidth(), getLocalBounds().getHeight()/3),
				Justification::centred,
				true);
}

void MainContentComponent::resized()
{
	// This is called when the MainContentComponent is resized.
	// If you add any child components, this is where you should
	// update their positions.
}

void MainContentComponent::InitialHomeScoreLabel(Component& parent)
{
	home_score_ = 0;
	home_score_label_.setColour(Label::textColourId, Colours::black);
	home_score_label_.setText((String)home_score_, dontSendNotification);
	home_score_label_.setFont(Font(kScoreFontName, 50, juce::Font::bold));
	home_score_label_.setBounds((parent.getWidth() /3)*2,
							   parent.getHeight() /5,
							   200,
							   100);

	parent.addAndMakeVisible(home_score_label_);
}

void MainContentComponent::InitialGuestScoreLabel(Component& parent)
{
	guest_score_ = 0;
	guest_score_label_.setColour(Label::textColourId, Colours::black);
	guest_score_label_.setText((String)guest_score_, dontSendNotification);
	guest_score_label_.setFont(Font(kScoreFontName, 50, juce::Font::bold));
	guest_score_label_.setBounds(parent.getWidth() /3,
								parent.getHeight() / 5,
								200,
								100);

	parent.addAndMakeVisible(guest_score_label_);
}

void MainContentComponent::InitialHomeScoreIncreaseButton(Component& parent,
														  const Component& home_score_laebl)
{
	InitialControlScoreTextButton(home_score_increase_button_,
								  parent,
								  "+1",
								  home_score_laebl.getX() - 25,
								  home_score_laebl.getBottom() + 10,
								  Colours::green,
								  Colours::white);

	home_score_increase_button_.addListener(this);
}

void MainContentComponent::InitialHomeScoreDecreaseButton(Component& parent,
														  const Component& home_score_increase_button)
{
	InitialControlScoreTextButton(home_score_decrease_button_,
								  parent,
								  "-1",
								  home_score_increase_button.getRight() + 20,
								  home_score_increase_button.getY(),
								  Colours::red,
								  Colours::white);

	home_score_decrease_button_.addListener(this);
}

void MainContentComponent::InitialGuestScorePlusButton(Component& parent,
													   const Component& guest_score_laebl)
{
	InitialControlScoreTextButton(guest_score_increase_button_,
								  parent,
								  "+1",
								  guest_score_laebl.getX() - 25,
								  guest_score_laebl.getBottom() + 10,
								  Colours::green,
								  Colours::white);

	guest_score_increase_button_.addListener(this);
}

void MainContentComponent::InitialGuestScoreDecreaseButton(Component& parent,
														   const Component& guest_score_increase_button)
{
	InitialControlScoreTextButton(guest_score_decrease_button_,
								  parent,
								  "-1",
								  guest_score_increase_button.getRight() + 20,
								  guest_score_increase_button.getY(),
								  Colours::red,
								  Colours::white);

	guest_score_decrease_button_.addListener(this);
}

void MainContentComponent::buttonClicked(Button* b)
{
	if (b == &home_score_increase_button_) {
		home_score_label_.setText((String)(++home_score_),
								  juce::NotificationType::sendNotification);
	}
	else if (b == &home_score_decrease_button_) {
		if (home_score_ == 0)
			return;

		home_score_label_.setText((String)(--home_score_),
								  juce::NotificationType::sendNotification);
	}
	else if (b == &guest_score_increase_button_) {
		guest_score_label_.setText((String)(++guest_score_),
								  juce::NotificationType::sendNotification);
	}
	else if (b == &guest_score_decrease_button_) {
		if (guest_score_ == 0)
			return;

		guest_score_label_.setText((String)(--guest_score_),
								  juce::NotificationType::sendNotification);
	}
}