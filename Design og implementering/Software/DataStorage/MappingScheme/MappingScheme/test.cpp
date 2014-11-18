#include "MappingScheme.h"

int main()
{
	MidiSignal testSignal = {0,0x80,0,0};
	cout <<   "Start signal\nTestSignal = " << endl; 
	testSignal.print();
	
	MappingScheme *velocityPtr = new MappingScheme(	"velocity",			//param
													"0", "0", "0",		//key params
													20,					//velocity params
													NULL,				//Common CC param
													NULL, NULL,			//CCAbs params
													"0");				//CCRel params

	velocityPtr->map(50, testSignal);	
	cout <<   "\nTesting velocity\nTestSignal = " << endl; 
	testSignal.print();

	MappingScheme *keyPtr = new MappingScheme(	"key",						//param
												"cis", "major", "falling",	//key params
												NULL,						//velocity params
												NULL,						//Common CC param
												NULL, NULL,					//CCAbs params
												"0");						//CCRel params
	keyPtr->map(100, testSignal);

	cout <<   "\nTesting key\nTestSignal = " << endl; 
	testSignal.print();

	velocityPtr->map(50, testSignal);
	keyPtr->map(100, testSignal);

	cout <<   "\nTesting velocity and (same)key again\nTestSignal = " << endl; 
	testSignal.print();

	delete velocityPtr;
	delete keyPtr;
	return 0;
}


