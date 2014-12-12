#include <vector>
#include "MappingScheme.h"

using namespace std;

int main()
{
	int vectorsize = 16;
	vector<MidiSignal> MidiSigs(vectorsize);

	for (int i = 0; i < vectorsize; ++i)
	{
		MidiSigs[i].channel_=0;
		MidiSigs[i].command_=NOTEOFF;
		MidiSigs[i].param1_=0;
		MidiSigs[i].param2_=0;
	}
	
	cout <<   "Original signal\n  MidiSigs[1] = " << endl; 
	MidiSigs[1].print();
	
	/** TEST AF VELOCITY **/
	MappingScheme *velocityPtr = new MappingScheme(	"one",				//id
													1,					//kanal
													"velocity",			//param
													"0", "0", "0",		//key params
													20,					//velocity params
													0,				//Common CC param
													0, 0,			//CCAbs params
													0);				//CCRel params

	velocityPtr->map(50, MidiSigs[1]);	
	cout <<   "\nTesting velocity with data = 50\n  MidiSigs[1] = " << endl; 
	MidiSigs[1].print();

	velocityPtr->map(45, MidiSigs[1]);	
	cout <<   "\nTesting velocity with data = 45\n  MidiSigs[1] = " << endl; 
	MidiSigs[1].print();

	velocityPtr->map(19, MidiSigs[1]);	
	cout <<   "\nTesting velocity with data = 19\n  MidiSigs[1] = " << endl; 
	MidiSigs[1].print();

	velocityPtr->map(200, MidiSigs[1]);	
	cout <<   "\nTesting velocity with data = 200\n  MidiSigs[1] = " << endl; 
	MidiSigs[1].print();

	/** TEST AF KEY **/
	MappingScheme *keyPtr = new MappingScheme(	"two",						//id
												2,					//kanal
												"key",						//param
												"cis", "major", "falling",	//key params
												0,						//velocity params
												0,						//Common CC param
												0, 0,					//CCAbs params
												0);						//CCRel params
	
	cout <<   "\nTesting key with data = 120\n  MidiSigs[1] = " << endl; 
	keyPtr->map(120, MidiSigs[1]);
	MidiSigs[1].print();

	cout <<   "\nTesting velocity and (same)key again\n  TestSignal = " << endl; 
	keyPtr->map(120, MidiSigs[1]);
	MidiSigs[1].print();

	MappingScheme *CCAbsPtr = new MappingScheme("three",		//id
												3,					//kanal
												"CCAbs",		//param
												"0", "0", "0",	//key params
												0,			//velocity params
												10,				//Common CC param: CC num
												40, 120,		//CCAbs params
												0);			//CCRel params
	CCAbsPtr->map(64, MidiSigs[1]);
	cout <<   "\nTesting CCAbs with data = 64\n  TestSignal = " << endl; 
	MidiSigs[1].print();

	MappingScheme *CCRelPtr = new MappingScheme("four",			//id
												4,					//kanal
												"CCRel",		//param
												"0", "0", "0",	//key params
												0,			//velocity params
												10,				//Common CC param: CC num
												40, 85,		//CCAbs params
												MEDIUM);		//CCRel params
	CCRelPtr->map(127, MidiSigs[1]);
	cout <<   "\nTesting CCRel with data = 127\n  TestSignal = " << endl; 
	MidiSigs[1].print();

	CCRelPtr->map(127, MidiSigs[1]);
	cout <<   "\nTesting CCRelwith data = 127\n  TestSignal = " << endl; 
	MidiSigs[1].print();

	CCRelPtr->map(13, MidiSigs[1]);
	cout <<   "\nTesting CCRelwith data = 13\n  TestSignal = " << endl; 
	MidiSigs[1].print();

	delete CCRelPtr;
	delete CCAbsPtr;
	delete velocityPtr;
	delete keyPtr; 
	
	

	return 0;
}


