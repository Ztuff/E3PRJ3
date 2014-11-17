#include "MIDIGen.h"

MIDIGen::MIDIGen(int dataIn)
{
	setDataIn(dataIn);
}

void MIDIGen::setDataIn(int dataIn)
{
	dataIn_ = (dataIn > 127 || dataIn < 0 ? 127 : dataIn);
}

int MIDIGen::getDataIn() const
{
	return dataIn_;
}

int MIDIGen::noteStringToInt(string note)
{
	if(note.compare("c") == 0) return 1;
	else if(note.compare("cis") == 0) return 2;
	else if(note.compare("d") == 0) return 3;
	else if(note.compare("dis") == 0) return 4;
	else if(note.compare("e") == 0) return 5;
	else if(note.compare("f") == 0) return 6;
	else if(note.compare("fis") == 0) return 7;
	else if(note.compare("g") == 0) return 8;
	else if(note.compare("gis") == 0) return 9;
	else if(note.compare("a") == 0) return 10;
	else if(note.compare("ais") == 0) return 11;
	else if(note.compare("b") == 0) return 12;
	else return 1;
}