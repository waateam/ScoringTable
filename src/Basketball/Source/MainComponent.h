/*
  ==============================================================================

	This file was auto-generated!

  ==============================================================================
*/

#ifndef MAINCOMPONENT_H_INCLUDED
#define MAINCOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"


//==============================================================================
/*
	This component lives inside our window, and this is where you should put all
	your controls and content.
*/
class MainContentComponent   : public Component,
							   private Button::Listener
{
public:
	//==============================================================================
	MainContentComponent();
	~MainContentComponent();

	void paint (Graphics&);
	void resized();

private:
	TextButton home_score_increase_button_;
	TextButton home_score_decrease_button_;

	TextButton guest_score_increase_button_;
	TextButton guest_score_decrease_button_;

	Label home_score_label_;
	Label guest_score_label_;

	int home_score_;
	int guest_score_;

	void buttonClicked(Button* b) override;

	void InitialHomeScoreLabel(Component& parent);
	void InitialGuestScoreLabel(Component& parent);

	void InitialHomeScoreIncreaseButton(Component& parent, const Component& home_score_laebl);
	void InitialHomeScoreDecreaseButton(Component& parent, const Component& home_score_laebl);

	void InitialGuestScorePlusButton(Component& parent, const Component& home_score_laebl);
	void InitialGuestScoreDecreaseButton(Component& parent, const Component& home_score_laebl);
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};


#endif  // MAINCOMPONENT_H_INCLUDED
