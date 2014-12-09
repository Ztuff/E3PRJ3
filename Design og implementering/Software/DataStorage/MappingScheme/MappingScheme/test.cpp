#include <vector>
#include "MappingScheme.h"
#define VECTORSIZE 16

int main()
{
	MidiSignal mySig;
	mySig.print();
	mySig.channel_ = '0';
	mySig.command_ = '8';
	mySig.param1_ = 0;
	mySig.param2_ = 0;
	mySig.param1Old_ = 0;
	mySig.param2Old_ = 0;

	mySig.print();

	return 0;
	/*vector<MidiSignal> MidiSigs(VECTORSIZE);

	for (int i = 0; i < VECTORSIZE; ++i)
	{
		MidiSigs[i].channel_=0;
		MidiSigs[i].command_=0x80;
		MidiSigs[i].param1_=0;
		MidiSigs[i].param2_=0;
		MidiSigs[i].param1Old_=0;
		MidiSigs[i].param2Old_=0;
	}

	MidiSigs[16].print();
	*/
	/*
	MidiSignal testSignal = {'1','8',0,0};
	cout <<   "Original signal\n  TestSignal = " << endl; 
	testSignal.print();
	
	MappingScheme *velocityPtr = new MappingScheme(	"one",				//id
													"velocity",			//param
													"0", "0", "0",		//key params
													20,					//velocity params
													NULL,				//Common CC param
													NULL, NULL,			//CCAbs params
													NULL);				//CCRel params

	velocityPtr->map(50, testSignal);	
	cout <<   "\nTesting velocity\n  TestSignal = " << endl; 
	testSignal.print();

	MappingScheme *keyPtr = new MappingScheme(	"two",						//id
												"key",						//param
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

	MappingScheme *CCAbsPtr = new MappingScheme("three",		//id
												"CCAbs",		//param
												"0", "0", "0",	//key params
												NULL,			//velocity params
												10,				//Common CC param: CC num
												40, 120,		//CCAbs params
												NULL);			//CCRel params
	CCAbsPtr->map(66, testSignal);
	cout <<   "\nTesting CCAbs\n  TestSignal = " << endl; 
	testSignal.print();

	MappingScheme *CCRelPtr = new MappingScheme("four",			//id
												"CCRel",		//param
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
	*/
}


