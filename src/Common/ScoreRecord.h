#pragma once
#include <iostream>
#include <windows.h>
#define DEF_TEAM_HOME 0
#define DEF_TEAM_GUEST 0
namespace waa {
	
	int ScoreTimeStamp[2][100] = {};
	void TimeStampInitial(void);
	void time_record(int team, int score, int time);
}