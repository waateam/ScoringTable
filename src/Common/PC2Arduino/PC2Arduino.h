#pragma once

#include <iostream>
#include <windows.h>

#include "Serial.h"
#include "stdafx.h"

namespace waa {
	const char PCCommand[15][10] = { "pause", "continue", "start600", "start24", "start14", "TimeInc", "TimeDec", "faul",
		"period", "left", "right", "IncA", "DecA", "IncB", "DecB" };
	const char ArduinoCommand[15][2] = { "T", "T", "t", "R", "r", "U", "D", "F", "P", "V", "V", "A", "a", "B", "b", };
	
	bool OpenCom(void);
	bool PC2Arduino(char *command);
}