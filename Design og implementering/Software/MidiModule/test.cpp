#include "MidiModule.hpp"

struct DataStruct	//DataStruct Dummy
{
	char x;
	char y;
	char z;
};

int main()
{
	/****************************************** INITIALIZATION **********************************************/
	/*** Opret DataStruct array Dummy ***/
	const int size = 16;
	DataStruct myData[size];
	
	for (int i = 0; i< size; ++i)
	{
		myData[i].x = i;
		myData[i].y = i;
		myData[i].z = i;
	}
	
	/*** Klargør vector<MidiSignal> ***/
	vector<MidiSignal> midiVec;
	
	/*** Opret Mapping Scheme og SensorConfiguration Dummy ***/
	MappingScheme *testMSchemePtr = new MappingScheme(	"test",						//id
														"key",						//param
														"cis", "major", "rising",	//key params
														NULL,						//velocity params
														NULL,						//Common CC param
														NULL, NULL,					//CCAbs params
														NULL);						//CCRel params
	
	
	SensorConfiguration *testSensConfPtr = new SensorConfiguration("testConfig",	//string name,
																	0,				//int sensorID,
																	x,				//char axis,
																	*testMScheme,	//MappingScheme mScheme,
																	midiVec);		//vector<MidiSignal> &midiVec);
	
	list <SensorConfiguration> myList(*testSensConfPtr);
	
	/*** Klargør ALSA-delen ***/
	//????
	AlsaAdapter alsaAdapter(3);
	
	/*** Klargør MidiModule ***/
	MidiModule myMidiModule(&alsaAdapter, myList);
	
	/******************************************* FUNCITON TEST ***********************************************/
	
	MidiModule.run();
	
	delete testMSchemePtr;
	delete testSensConfPtr;
	
	return 0;
}

