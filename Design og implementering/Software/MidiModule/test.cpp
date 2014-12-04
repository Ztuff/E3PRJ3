#include "MidiModule.hpp"
#include "DataBank/SensorConfiguration.hpp"
#include "DataBank/MappingScheme.h"
#include "DataMsg.hpp"

#define DEBUG 1

int main()
{
	/****************************************** INITIALIZATION **********************************************/
	/*** Opret DataStruct array Dummy ***/
	DataMsg myData;
	
	for (int i = 0; i< 4; ++i)
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
														0,						//velocity params
														0,						//Common CC param
														0, 0,					//CCAbs params
														0);						//CCRel params
	
	
	SensorConfiguration *testSensConfPtr = new SensorConfiguration("testConfig",	//string name,
																	0,				//int sensorID,
																	'x',				//char axis,
																	*testMSchemePtr,	//MappingScheme mScheme,
																	midiVec);		//vector<MidiSignal> &midiVec);
	
	list <SensorConfiguration> myList;
	myList.push_back(*testSensConfPtr);
	
	/*** Klargør ALSA-delen ***/
	//????
	AlsaAdapter alsaAdapter(3);
	
	/*** Klargør MidiModule ***/
	MidiModule myMidiModule(&alsaAdapter, myList);
	
	/******************************************* FUNCITON TEST ***********************************************/
	
	myMidiModule.start();
	MsgQueue* msgQPtr = myMidiModule.getMsgQueue();
	msgQPtr->send(MidiModule::DATA_MSG, &myData);
	msgQPtr->send(MidiModule::SHUTDOWN_MSG, NULL);
	myMidiModule.join();
	
	delete testMSchemePtr;
	delete testSensConfPtr;
	
	return 0;
}

