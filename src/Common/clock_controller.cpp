#include "clock_controller.h"

namespace waa {
	ClockController::ClockController(int time_sec)
	{
		max_time_sec_ = time_sec;
		SetupClock(max_time_sec_);
	}

	ClockController::ClockController(int time_sec, CountingCallback counting_cb)
		:ClockController(time_sec)
	{
		if (counting_cb != nullptr) {
			counting_callback_ = counting_cb;
		}
	}

	ClockController::ClockController(int time_sec, TimeupCallback timeup_cb)
		:ClockController(time_sec)
	{
		if (timeup_cb != nullptr) {
			timeup_callback_ = timeup_cb;
		}
	}

	ClockController::ClockController(int time_sec, CountingCallback counting_cb, TimeupCallback timeup_cb)
		:ClockController(time_sec)
	{
		if (counting_cb != nullptr) {
			counting_callback_ = counting_cb;
		}

		if (timeup_cb != nullptr) {
			timeup_callback_ = timeup_cb;
		}
	}

	void ClockController::ClockStart()
	{
		startTimer(1000);
	}

	void ClockController::ClockPause()
	{
		stopTimer();
	}

	void ClockController::SetupClock(int secs)
	{
		remain_time_sec_ = secs;
	}

	int ClockController::GetClockValue()
	{
		return remain_time_sec_;
	}

	void ClockController::timerCallback()
	{
		if (remain_time_sec_ == 1) {
			stopTimer();
			timeup_callback_();
			return;
		}

		remain_time_sec_--;

		if (counting_callback_ != nullptr)
			counting_callback_(remain_time_sec_);
	}
}//namespace waa
