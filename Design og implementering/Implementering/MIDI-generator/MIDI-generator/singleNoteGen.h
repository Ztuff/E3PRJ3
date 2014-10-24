#pragma once
#include "MIDIGen.h"

using namespace std;

class singleNoteGen : public MIDIGen
{
public:
	singleNoteGen(string root = "c", int octave = 0, unsigned int lowerThreshold = 0, int dataIn = 0);
	virtual void sendMIDI(int dataIn = -1);	//dataIn optional
	virtual void printStrategies();
private:
	/**** dataIn is the input velocoty ****/
	int root_;						//value from 1 to 12
	int octave_;					//value from -3 ti 8
	int note_;						//value from 0 to 127
	unsigned int lowerThreshold_;	//value from 0 to 127
	bool noteState_;				//utility atribute
};