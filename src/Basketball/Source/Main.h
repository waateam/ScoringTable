/**=============================================================================
* file name  : Main.h
* created    : 2015.09.09
* author     : pow
* copyright  : Copyright(C) I3D Technology Inc. All rights reserved.
=============================================================================**/
#pragma once

#include "MainComponent.h"
#include <memory>

namespace waa {
	class ArduinoManager;
	class ClockController;
}

//==============================================================================
class BasketballApplication : public JUCEApplication
{
	std::unique_ptr<waa::ArduinoManager> adm_;
	std::unique_ptr<waa::ClockController> cc_;

public:
	//==============================================================================
	BasketballApplication();

	const String getApplicationName() override       { return ProjectInfo::projectName; }
	const String getApplicationVersion() override    { return ProjectInfo::versionString; }
	bool moreThanOneInstanceAllowed() override       { return false; }

	//==============================================================================
	void initialise(const String& commandLine) override;
	void shutdown() override;
	void systemRequestedQuit() override;
	void anotherInstanceStarted(const String& commandLine) override;

	//==============================================================================
	void RegisterMainWindowCallbacks(MainContentComponent& mcc);

	void RegisterHomeScoreIncreaseButton(MainContentComponent& mcc);
	void RegisterHomeScoreDecreaseButton(MainContentComponent& mcc);

	void RegisterGuestScoreIncreaseButton(MainContentComponent& mcc);
	void RegisterGuestScoreDecreaseButton(MainContentComponent& mcc);

	bool InitializeArduinoManager();
	bool InitializeGameClock();

	/*
	This class implements the desktop window that contains an instance of
	our MainContentComponent class.
	*/
	class MainWindow : public DocumentWindow
	{
		MainContentComponent* main_component_ = nullptr;
	public:
		MainWindow(String name);

		// This is called when the user tries to close this window. Here, we'll just
		// ask the app to quit when this happens, but you can change this to do
		// whatever you need.
		void closeButtonPressed() override;

		/* Note: Be careful if you override any DocumentWindow methods - the base
		class uses a lot of them, so by overriding you might break its functionality.
		It's best to do all your work in your content component instead, but if
		you really have to override any DocumentWindow methods, make sure your
		subclass also calls the superclass's method.
		*/

		MainContentComponent& GetMainComponent() const;

	private:
		JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainWindow)
	};

private:
	ScopedPointer<MainWindow> mainWindow;
};

//==============================================================================
// This macro generates the main() routine that launches the app.
START_JUCE_APPLICATION(BasketballApplication)