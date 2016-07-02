#include "ScoreRecord.h"

namespace waa {
	
	int ScoreTimeStamp[2][100] = {};
	void time_record(int team ,int score,int time){
		ScoreTimeStamp[team][score] = time;
	}
	void TimeStampInitial(void){
		int i = 0;
		for (i = 0; i < 100; i++){
			ScoreTimeStamp[0][i] = 0;
			ScoreTimeStamp[1][i] = 0;
		}		
	}
	
};//namespace waa