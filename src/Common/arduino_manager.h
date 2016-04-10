/**=============================================================================
* file name  : arduino_manager.h
* created    : 2016.04.09
* author     : pow
* copyright  : WAA Team. All rights reserved.
=============================================================================**/
#pragma once

#include <JuceHeader.h>
namespace waa {

class ArduinoManager
{
public:
	ArduinoManager();
	~ArduinoManager();

	bool SetupArduinoEnvironment();
	bool PingAuduino();

	bool StartArduino();
	bool EndArduino();

	bool SendCommandToArduino(const String& cmd);

private:

};


}