/*
  ==============================================================================

	This file was auto-generated!

  ==============================================================================
*/

#ifndef MAINCOMPONENT_H_INCLUDED
#define MAINCOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include <map>

namespace waa {

enum ButtonType : int {
	kHomeScoreIncreaseButton = 1,
	kHomeScoreDecreaseButton,
	kGuestScoreIncreaseButton,
	kGuestScoreDecreaseButton,

	kGameClockStartButton,
	kGameClockPauseButton
};

};


//==============================================================================
/*
	This component lives inside our window, and this is where you should put all
	your controls and content.
*/
class MainContentComponent   : public Component,
							   private Button::Listener
{
	typedef std::function<bool()> ButtonClickCallback;
	typedef std::map<int, ButtonClickCallback> CallbackBucket;
public:
	//==============================================================================
	MainContentComponent();
	~MainContentComponent();

	void SetHomeScore(const int score);
	int GetHomeScore() const;

	void SetGuestScore(const int score);
	int GetGuestScore() const;

	void RegisterMainWindowCallbacks(const int callback_id,
									 ButtonClickCallback bc_cb);

	void paint (Graphics&);
	void resized();

	void SetGameClock(int time_sec);
private:
	CallbackBucket observers_;

	TextButton home_score_increase_button_;
	TextButton home_score_decrease_button_;

	TextButton guest_score_increase_button_;
	TextButton guest_score_decrease_button_;

	TextButton game_clock_start_button_;
	TextButton game_clock_stop_button_;

	Label game_clock_label_;
	Label shot_clock_label_;
	Label home_score_label_;
	Label guest_score_label_;

	void buttonClicked(Button* b) override;

	void InitailGameClock(Component& parent);
	void InitialGameClockStartButton(Component & parent, const Component & game_clock_label);
	void InitialGameClockStopButton(Component & parent, const Component & game_clock_label);
	//void InitialGameClockLabel(Component& parent);
	void InitialShotClockLabel(Component& parent,
							   const Component& game_clock_label);

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
