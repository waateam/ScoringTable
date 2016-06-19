 //SerialTest.cpp : Defines the entry point for the console application.

#include "PC2Arduino.h"
#include <iostream>
#include <windows.h>

#include "Serial.h"
#include "stdafx.h"

using namespace std;

namespace waa {

bool waa::PC2Arduino(char *command, _TCHAR* Comport)
{
	int i = 0;
	char buffer = '\0';
	bool status = false;
	tstring commPortName(Comport);
	Serial serial(commPortName);
	serial.flush();
	do {
		i++;
	} while (strcmp(command, PCCommand[i]) != 0 || i>14);

	if (i<15 && i >= 0)
	{
		serial.write(&ArduinoCommand[i]);
		serial.read(&buffer, 1);
		if (buffer == '0')	status = true;
	}
	else {
		printf("command error,please insert again\n");
	}
	

	return status;
}

};