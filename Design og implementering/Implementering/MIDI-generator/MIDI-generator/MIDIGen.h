#pragma once
#include <iostream>

using namespace std;

class MIDIGen
{
public:
	MIDIGen(unsigned int dataIn = 0);		//dataIn: 0-127
	void setDataIn(unsigned int dataIn);
	unsigned int getDataIn();
private:
	unsigned int dataIn_;
	//unsigned int noteStringToInt(string note);	//utility function
};