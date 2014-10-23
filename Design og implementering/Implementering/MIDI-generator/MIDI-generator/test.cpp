#include "singleNoteGen.h"
#include "contNoteGen.h"
#include "CCAbsGen.h"
#include "CCRelGen.h"

int main()
{
	/**** test of singleNoteGen ****
	singleNoteGen testNote;								//default
	singleNoteGen testNote2("cis",-3,50,60);				//root, octave, lowerThreshold, dataIn
	testNote2.sendMIDI();*/

	/**** test of contNoteGen ****
	contNoteGen testNote;								//default
	//contNoteGen testNote2("c","major","rising",6);	//string root, string scale, string direction, int dataIn 
	testNote.sendMIDI();
	//testNote2.sendMIDI();*/

	/**** test of CCAbsGen ****
	//CCAbsGen testNote;								//default
	CCAbsGen testNote2(0,10,64);						//int minVal, int maxVal, int dataIn
	//testNote.sendMIDI();
	testNote2.sendMIDI();*/

	/**** test of CCAbsGen ****/
	//CCRelGen testNote;								//default
	CCRelGen testNote2("medium",120);						//int minVal, int maxVal, int dataIn
	//testNote.sendMIDI();
	testNote2.sendMIDI();

	return 0;
}