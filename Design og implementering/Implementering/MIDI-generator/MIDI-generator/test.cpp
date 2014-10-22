#include "singleNoteGen.h"

int main()
{
	/**** test of singleNoteGen ****/
	singleNoteGen testNote(10,0,150,30);	//root, octave, lowerThreshold, dataIn
	testNote.playSingleNote();
		
	return 0;
}