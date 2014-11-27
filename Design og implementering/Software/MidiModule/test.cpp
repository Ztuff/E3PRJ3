#include "MidiModule.hpp"
#include "AlsaAdapter.hpp"
#include "SensorConfiguration.hpp"

struct DataStruct	//DataStruct Dummy
{
	char x;
	char y;
	char z;
};

int main()
{
	testInit();
	
	//do something
	
	return 0;
}

void testInit()
{
	/*** Opret DataStruct array Dummy ***/
	int size = 16;
	DataStruct[size];
	
	for (int i = 0; i< size; ++i)
	{
		DataStruct[i].x = i;
		DataStruct[i].y = i;
		DataStruct[i].z = i;
	}
	
	/*** Klargør vector<MidiSignal> ***/
	vector<MidiSignal> midiVec;
	
	/*** Klargør ALSA-delen ***/
	//????
	AlsaAdapter alsaAdapter(3);
	
	/*** Opret SensorConfiguration Dummy ***/
	MappingScheme *testMScheme = new MappingScheme(	"test",						//id
													"key",						//param
													"cis", "major", "rising",	//key params
													NULL,						//velocity params
													NULL,						//Common CC param
													NULL, NULL,					//CCAbs params
													NULL);						//CCRel params
	
	
	SensorConfiguration( 	"testConfig",	//string name,
							0,				//int sensorID,
							x,				//char axis,
							*testMScheme,	//MappingScheme mScheme,
							midiVec);		//vector<MidiSignal> &midiVec);
	
	
	/*** Klargør MidiModule ***/
	MidiModule(&alsaAdapter);
}

