#pragma once
#include "MIDIGen.h"

using namespace std;

class contNoteGen : public MIDIGen
{
public:
	contNoteGen(string root = "c", string scale = "cromatic", string direction = "rising");
	void playContNote();
private:
	string root_;					//strategies: c, cis, d, dis, e, f, fis, g, gis, a, ais, b
	string scale_;					//strategies: cromatic, major, minor
	string direction_;				//strategies: rising, falling
	unsigned int oldDataIn_;		//Bruges til afspilning

	void quantizeDiatonic(unsigned int &dataIn);	//kvantiserer jf. scale- og root strategy
};