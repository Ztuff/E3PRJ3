#include "singleNoteGen.h"
#include "contNoteGen.h"

int main()
{
	/**** test of singleNoteGen ****
	singleNoteGen testNote;							//default
	singleNoteGen testNote2("cis",-3,50,60);			//root, octave, lowerThreshold, dataIn
	testNote2.sendMIDI();*/

	/**** test of contNoteGen ****/
	//contNoteGen testNote;										//default
	contNoteGen testNote2("cis","major","falling",0);		//string root, string scale, string direction, int dataIn 
	//testNote.sendMIDI();
	//testNote2.sendMIDI();

	return 0;
}