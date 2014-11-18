#include "MappingScheme.h"

int main()
{
	MidiSignal testSignal = {0,0x80,0,0};
	cout <<   "Original signal\n  TestSignal = " << endl; 
	testSignal.print();
	
	MappingScheme *velocityPtr = new MappingScheme(	"velocity",			//param
													"0", "0", "0",		//key params
													20,					//velocity params
													NULL,				//Common CC param
													NULL, NULL,			//CCAbs params
													NULL);				//CCRel params

	velocityPtr->map(50, testSignal);	
	cout <<   "\nTesting velocity\n  TestSignal = " << endl; 
	testSignal.print();

	MappingScheme *keyPtr = new MappingScheme(	"key",						//param
												"cis", "major", "falling",	//key params
												NULL,						//velocity params
												NULL,						//Common CC param
												NULL, NULL,					//CCAbs params
												NULL);						//CCRel params
	keyPtr->map(100, testSignal);

	cout <<   "\nTesting key\n  TestSignal = " << endl; 
	testSignal.print();

	velocityPtr->map(50, testSignal);
	keyPtr->map(100, testSignal);

	cout <<   "\nTesting velocity and (same)key again\n  TestSignal = " << endl; 
	testSignal.print();

	MappingScheme *CCAbsPtr = new MappingScheme("CCAbs",		//param
												"0", "0", "0",	//key params
												NULL,			//velocity params
												10,				//Common CC param: CC num
												40, 120,		//CCAbs params
												NULL);			//CCRel params
	CCAbsPtr->map(66, testSignal);
	cout <<   "\nTesting CCAbs\n  TestSignal = " << endl; 
	testSignal.print();

	MappingScheme *CCRelPtr = new MappingScheme("CCRel",		//param
												"0", "0", "0",	//key params
												NULL,			//velocity params
												10,				//Common CC param: CC num
												40, 120,		//CCAbs params
												MEDIUM);		//CCRel params
	CCRelPtr->map(127, testSignal);
	cout <<   "\nTesting CCRel\n  TestSignal = " << endl; 
	testSignal.print();

	delete CCRelPtr;
	delete CCAbsPtr;
	delete velocityPtr;
	delete keyPtr;
	return 0;
}


