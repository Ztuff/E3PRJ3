#pragma once
#include "MIDIGen.h"

using namespace std;

class CCAbsGen : public MIDIGen
{
public:
	CCAbsGen(int minVal = 0, int maxVal = 127, int dataIn = 0);		
	virtual void sendMIDI(int dataIn = -1);		//dataIn is optional
	virtual void printStrategies();
private:
	/**** dataIn is the absolute CC value ****/
	int minVal_;								//minimal value for dataIn after conversion	
	int maxVal_;								//maximal value for dataIn after conversion	
	int dataInOld_;								//utility variable - used in playContNote
};