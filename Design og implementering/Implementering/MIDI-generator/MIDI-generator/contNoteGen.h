#pragma once
#include "MIDIGen.h"

using namespace std;

class contNoteGen : public MIDIGen
{
public:
	contNoteGen(string root = "c", string scale = "cromatic", string direction = "rising", int dataIn = 0);		
	virtual void setDataIn(int dataIn);				//overload der sætter tone jf. direction strategy
	virtual void sendMIDI(int dataIn = -1);			//dataIn frivillig								
private:
	/**** dataIn is the note control ****/
	string root_;									//strategies: c, cis, d, dis, e, f, fis, g, gis, a, ais, b
	int rootInt_;
	string scale_;									//strategies: cromatic, major, minor
	string direction_;								//strategies: rising, falling
	unsigned int dataInOld_;						//utility variabel - benyttes ved playContNote
	
	void convertDataToNote();						//utility funktion - bruges i updateData
	void quantizeDiatonic(int &dataIn);				//utility funktion - kvantiserer jf. scale- og root strategy
};