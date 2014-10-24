#pragma once

#include <string>
#include <iostream>

using namespace std;

class MIDIGen
{
public:
	MIDIGen(int dataIn = 0);							//dataIn: 0-127
	int getDataIn() const;
	virtual void setDataIn(int dataIn);
	virtual void sendMIDI(int dataIn = -1) = 0;			//Abstract function
	virtual void printStrategies() = 0;
protected:
	int noteStringToInt(string note);					//utility function, default return 1
	int dataIn_;
};