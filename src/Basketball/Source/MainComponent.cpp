/*
  ==============================================================================

	This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"

using namespace waa;

const char kScoreFontName[] = "Segoe UI";
const char kGameClockFontName[] = "Segoe UI";

namespace {

enum WindowParameter : int {
	kWindowWidth = 600,
	kWindowHeight = 400
};

void InitialScoreTextControlButton(TextButton& button,
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

	InitailGameClock(*this);
	InitialShotClockLabel(*this, game_clock_label_);

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

void MainContentComponent::InitailGameClock(Component & parent)
{
	game_clock_label_.setColour(Label::textColourId, Colours::red);
	game_clock_label_.setText(String(0), dontSendNotification);
	game_clock_label_.setFont(Font(kGameClockFontName, 100, juce::Font::bold));

	const Rectangle<int> label_size(0, 0, 200, 100);
	game_clock_label_.setBounds((parent.getWidth() / 2) - (label_size.getWidth() / 2),
		0,
		label_size.getWidth(),
		label_size.getHeight());

	parent.addAndMakeVisible(game_clock_label_);
}

void MainContentComponent::InitialShotClockLabel(Component& parent,
												 const Component& game_clock_label)
{
	shot_clock_label_.setColour(Label::textColourId, Colours::red);
	shot_clock_label_.setText("24", dontSendNotification);
	shot_clock_label_.setFont(Font(kScoreFontName, 75, juce::Font::bold));

	const Rectangle<int> label_size(0, 0, 75, 75);
	shot_clock_label_.setBounds((parent.getWidth() / 2) - (label_size.getWidth() / 2),
								parent.getBottom() - label_size.getHeight()*2,
								label_size.getWidth(),
								label_size.getHeight());

	parent.addAndMakeVisible(shot_clock_label_);
}

void MainContentComponent::RegisterMainWindowCallbacks(const int callback_id,
													   ButtonClickCallback bc_cb)
{
	observers_.insert(std::make_pair(callback_id, bc_cb));
}

void MainContentComponent::paint (Graphics& g)
{
	g.fillAll(Colour(0xff7DB9DE));
}

void MainContentComponent::resized()
{
	// This is called when the MainContentComponent is resized.
	// If you add any child components, this is where you should
	// update their positions.
}

void MainContentComponent::SetGameClock(int time_sec)
{
	game_clock_label_.setText(String(time_sec), dontSendNotification);
}

void MainContentComponent::InitialHomeScoreLabel(Component& parent)
{
	home_score_label_.setColour(Label::textColourId, Colours::gold);
	home_score_label_.setText("0", dontSendNotification);
	home_score_label_.setFont(Font(kScoreFontName, 50, juce::Font::bold));
	home_score_label_.setBounds((parent.getWidth() /3)*2,
							   parent.getHeight() /5,
							   200,
							   100);

	parent.addAndMakeVisible(home_score_label_);
}

void MainContentComponent::InitialGuestScoreLabel(Component& parent)
{
	guest_score_label_.setColour(Label::textColourId, Colours::gold);
	guest_score_label_.setText("0", dontSendNotification);
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
	InitialScoreTextControlButton(home_score_increase_button_,
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
	InitialScoreTextControlButton(home_score_decrease_button_,
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
	InitialScoreTextControlButton(guest_score_increase_button_,
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
	InitialScoreTextControlButton(guest_score_decrease_button_,
								  parent,
								  "-1",
								  guest_score_increase_button.getRight() + 20,
								  guest_score_increase_button.getY(),
								  Colours::red,
								  Colours::white);

	guest_score_decrease_button_.addListener(this);
}

void MainContentComponent::SetHomeScore(const int score)
{
	home_score_label_.setText(static_cast<String>(score),
							  juce::NotificationType::sendNotification);
}

int MainContentComponent::GetHomeScore() const
{
	return home_score_label_.getText().getIntValue();
}

void MainContentComponent::SetGuestScore(const int score)
{
	guest_score_label_.setText(static_cast<String>(score),
							  juce::NotificationType::sendNotification);
}

int MainContentComponent::GetGuestScore() const
{
	return guest_score_label_.getText().getIntValue();
}

void MainContentComponent::buttonClicked(Button* b)
{
	CallbackBucket::iterator cb_iter;
	if (b == &home_score_increase_button_) {
		cb_iter = observers_.find(kHomeScoreIncreaseButton);
		if (cb_iter != observers_.end())
			cb_iter->second();
	}
	else if (b == &home_score_decrease_button_) {
		cb_iter = observers_.find(kHomeScoreDecreaseButton);
		if (cb_iter != observers_.end())
			cb_iter->second();
	}
	else if (b == &guest_score_increase_button_) {
		cb_iter = observers_.find(kGuestScoreIncreaseButton);
		if (cb_iter != observers_.end())
			cb_iter->second();
	}
	else if (b == &guest_score_decrease_button_) {
		cb_iter = observers_.find(kGuestScoreDecreaseButton);
		if (cb_iter != observers_.end())
			cb_iter->second();
	}
}