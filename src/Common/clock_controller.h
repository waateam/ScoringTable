/**=============================================================================
* file name  : clock_controller.h
* created    : 2016.05.22
* author     : pow
* copyright  : WAA Team. All rights reserved.
=============================================================================**/
#pragma once

#include <JuceHeader.h>

namespace waa {

	class ClockController : private Timer
	{
		typedef std::function<void()> TimeupCallback;
		typedef std::function<void(int remain_second)> CountingCallback;
	public:
		ClockController(int time_sec);
		ClockController(int time_sec, CountingCallback counting_cb);
		ClockController(int time_sec, TimeupCallback timpup_cb);
		ClockController(int time_sec, CountingCallback counting_cb, TimeupCallback timeup_cb);
		~ClockController() {};

		void ClockStart();
		void ClockPause();

		void SetupClock(int secs);
		int GetClockValue();
	private:
		int max_time_sec_;
		int remain_time_sec_;
		TimeupCallback timeup_callback_;
		CountingCallback counting_callback_;

		void timerCallback() override;

		JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ClockController);
	};


}