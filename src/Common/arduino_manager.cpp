/**=============================================================================
* file name  : arduino_manager.cpp
* created    : 2016.04.09
* author     : pow
* copyright  : WAA Team. All rights reserved.
=============================================================================**/

#include "arduino_manager.h"

namespace waa {

ArduinoManager::ArduinoManager()
{
}

ArduinoManager::~ArduinoManager()
{
}

bool ArduinoManager::SetupArduinoEnvironment()
{
	return true;
}

bool ArduinoManager::PingAuduino()
{
	return true;
}

bool ArduinoManager::StartArduino()
{
	return true;
}

bool ArduinoManager::EndArduino()
{
	return true;
}

bool SendCommandToArduino(const String& cmd)
{
	return true;
}


}
