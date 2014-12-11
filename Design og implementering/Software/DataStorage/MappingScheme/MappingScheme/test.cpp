#include <vector>
#include "MappingScheme.h"

using namespace std;

int main()
{
	/*MidiSignal mySig;
	mySig.print();

	mySig.channel_ = '0';
	mySig.command_ = '8';
	mySig.param1_ = 0;
	mySig.param2_ = 0;

	mySig.print();

	*/
	
	int vectorsize = 16;
	vector<MidiSignal> MidiSigs(vectorsize);

	for (int i = 0; i < vectorsize; ++i)
	{
		MidiSigs[i].channel_='0';
		MidiSigs[i].command_='8';
		MidiSigs[i].param1_=0;
		MidiSigs[i].param2_=0;
	}

	MidiSigs[1].print();
	
	cout << "\n\n\n";
	
	cout <<   "Original signal\n  MidiSigs[1] = " << endl; 
	MidiSigs[1].print();
	
	MappingScheme *velocityPtr = new MappingScheme(	"one",				//id
													1,					//kanal
													"velocity",			//param
													"0", "0", "0",		//key params
													20,					//velocity params
													NULL,				//Common CC param
													NULL, NULL,			//CCAbs params
													NULL);				//CCRel params

	velocityPtr->map(50, MidiSigs[1]);	
	cout <<   "\nTesting velocity\n  MidiSigs[1] = " << endl; 
	MidiSigs[1].print();

	MappingScheme *keyPtr = new MappingScheme(	"two",						//id
												2,					//kanal
												"key",						//param
												"cis", "major", "falling",	//key params
												NULL,						//velocity params
												NULL,						//Common CC param
												NULL, NULL,					//CCAbs params
												NULL);						//CCRel params
	keyPtr->map(100, MidiSigs[1]);

	cout <<   "\nTesting key\n  MidiSigs[1] = " << endl; 
	MidiSigs[1].print();

	velocityPtr->map(50, MidiSigs[1]);
	keyPtr->map(100, MidiSigs[1]);

	cout <<   "\nTesting velocity and (same)key again\n  TestSignal = " << endl; 
	MidiSigs[1].print();

	MappingScheme *CCAbsPtr = new MappingScheme("three",		//id
												3,					//kanal
												"CCAbs",		//param
												"0", "0", "0",	//key params
												NULL,			//velocity params
												10,				//Common CC param: CC num
												40, 120,		//CCAbs params
												NULL);			//CCRel params
	CCAbsPtr->map(66, MidiSigs[1]);
	cout <<   "\nTesting CCAbs\n  TestSignal = " << endl; 
	MidiSigs[1].print();

	MappingScheme *CCRelPtr = new MappingScheme("four",			//id
												4,					//kanal
												"CCRel",		//param
												"0", "0", "0",	//key params
												NULL,			//velocity params
												10,				//Common CC param: CC num
												40, 120,		//CCAbs params
												MEDIUM);		//CCRel params
	CCRelPtr->map(127, MidiSigs[1]);
	cout <<   "\nTesting CCRel\n  TestSignal = " << endl; 
	MidiSigs[1].print();

	delete CCRelPtr;
	delete CCAbsPtr;
	delete velocityPtr;
	delete keyPtr; 
	return 0;
	

	return 0;
}


