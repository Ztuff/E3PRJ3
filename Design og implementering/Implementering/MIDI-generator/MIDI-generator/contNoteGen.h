#pragma once
#include "MIDIGen.h"

using namespace std;

class contNoteGen : public MIDIGen
{
public:
	contNoteGen(string root = "c", string scale = "cromatic", string direction = "rising", int dataIn = 0);		
	virtual void setDataIn(int dataIn);				//overloaded version. sets note as strategy dictates
	virtual void sendMIDI(int dataIn = -1);			//dataIn is optional								
private:
	/**** dataIn is the note control ****/
	string root_;									//strategies: c, cis, d, dis, e, f, fis, g, gis, a, ais, b
	int rootInt_;
	string scale_;									//strategies: cromatic, major, minor
	string direction_;								//strategies: rising, falling
	int dataInOld_;									//utility variable - used in playContNote
	
	void convertDataToNote();						//utility function - bruges i updateData
	void quantizeDiatonic(int dataIn);				//utility function - kvantiserer jf. scale- og root strategy
};