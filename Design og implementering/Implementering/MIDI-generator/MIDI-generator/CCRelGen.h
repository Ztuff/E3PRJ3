#pragma once
#include "MIDIGen.h"

using namespace std;

class CCRelGen : public MIDIGen
{
public:
	CCRelGen(string speed = "medium", int dataIn = 0);		
	virtual void sendMIDI(int dataIn = -1);		//dataIn is optional	
	virtual void printStrategies() const;
private:
	/**** dataIn is Rel CC change with 0-point at 64 ****/
	string speed_;								//strategies: "slow", "medium", "fast"
	int speedScaling_;							//utility variable
	int dataInOld_;								//utility variable - used in playContNote
};