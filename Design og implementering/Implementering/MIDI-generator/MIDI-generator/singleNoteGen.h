#pragma once
#include "MIDIGen.h"

using namespace std;

class singleNoteGen : public MIDIGen
{
public:
	singleNoteGen(unsigned int root = 1, int octave = 0, unsigned int lowerThreshold = 0, unsigned int dataIn = 0);
	void playSingleNote();
private:
	//dataIn is the input velocoty
	int root_;						//værdi fra 1 til 12
	int octave_;					//værdi fra -3 til 8
	int note_;						//værdi fra 0 til 127
	unsigned int lowerThreshold_;	//værdi fra 0 til 127
	bool noteState_;				//utility atribut
};