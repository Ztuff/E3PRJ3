#include <vector>
#include "MidiSignal.h"
#define VECTORSIZE 16

using namespace std;

int main()
{
	vector<MidiSignal> MidiSigs(VECTORSIZE);
	MidiSignalVectorInit(MidiSigs, VECTORSIZE);

	MidiSigs[15].print();	//check correct init
	
	
	
	return 0;
}

/** Udvider vector med "num" og initialiserer til default **/
vector<MidiSignal>::iterator MidiSignalVectorAdd(vector<MidiSignal> &vec, int num)	
{
	for (int i = 0; i < VECTORSIZE; ++i)
	{
		vec.push_back(MidiSignal());
		
		vec[i].channel_=0;
		vec[i].command_=0x80;
		vec[i].param1_=0;
		vec[i].param2_=0;
		vec[i].param1Old_=0;
		vec[i].param2Old_=0;
	}
	
	return vec.end();
}

