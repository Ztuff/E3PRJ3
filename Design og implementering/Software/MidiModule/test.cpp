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
	
	for (int i = 50; i< 54; ++i)
	{
		myData[i].x = i;
		myData[i].y = i;
		myData[i].z = i;
	}
	
		
	/*** Opret Mapping Scheme og SensorConfiguration Dummy ***/
	MappingScheme *testMSchemePtr = new MappingScheme(	"test",					//id
														1,						//channel
														"key",					//param
														"cis", "major", "rising",	//key params
														0,						//velocity params
														0,						//Common CC param
														0, 0,					//CCAbs params
														0);						//CCRel params
	
	
	SensorConfiguration *testSensConfPtr = new SensorConfiguration("testConfig",	//string name,
																	0,				//int sensorID,
																	'x',			//char axis,
																	*testMSchemePtr	//MappingScheme mScheme,
																	);		//vector<MidiSignal> &midiVec);
	
	list <SensorConfiguration> myList;
	myList.push_back(*testSensConfPtr);
	
	/*** Klargør ALSA-delen ***/
	//????
	AlsaAdapter alsaAdapter(3);
	
	/*** Klargør MidiModule ***/
	MidiModule myMidiModule(&alsaAdapter);
	myMidiModule.setPreset(myList);
	
	/******************************************* FUNCITON TEST ***********************************************/
	
	myMidiModule.start();
	MsgQueue* msgQPtr = myMidiModule.getMsgQueue();
	for(;;)
	{
		msgQPtr->send(MidiModule::DATA_MSG, &myData);
	}
	
	msgQPtr->send(MidiModule::SHUTDOWN_MSG, NULL);
	myMidiModule.join();
	
	delete testMSchemePtr;
	delete testSensConfPtr;
	
	return 0;
}

