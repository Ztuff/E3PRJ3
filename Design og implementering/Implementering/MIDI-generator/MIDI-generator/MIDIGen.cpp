#include "MIDIGen.h"

MIDIGen::MIDIGen(unsigned int dataIn)
{
	setDataIn(dataIn);
}

void MIDIGen::setDataIn(unsigned int dataIn)
{
	dataIn_ = (dataIn > 127 ? 127 : dataIn);
}

unsigned int MIDIGen::getDataIn()
{
	return dataIn_;
}

/*unsigned int MIDIGen::noteStringToInt(string note)
{
	switch(note)
	{
		case "c": return 1;
		case "cis": return 2;
		case "d": return 3;
		case "dis": return 4;
		case "e": return 5;
		case "f": return 6;
		case "fis": return 7;
		case "g": return 8;
		case "gis": return 9;
		case "a": return 10;
		case "ais": return 11;
		case "b": return 12;
	}
}*/