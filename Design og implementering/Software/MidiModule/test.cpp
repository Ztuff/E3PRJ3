#include <unistd.h>
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
	
	for (int i = 0 ; i< 4; ++i)
	{
		myData[i].x = i+50;
		myData[i].y = i+50;
		myData[i].z = i+50;
	}
	
		
	/*** Opret Mapping Scheme og SensorConfiguration Dummy ***/
	MappingScheme *testMSchemePtr = new MappingScheme(	"test",					//id
														1,						//channel
														"velocity",					//param
														"cis", "major", "rising",	//key params
														0,						//velocity params
														0,						//Common CC param
														0, 0,					//CCAbs params
														0);						//CCRel params
	
	
	SensorConfiguration *testSensConfPtr = new SensorConfiguration("testConfig",	//string name,
																	1,				//int sensorID,
																	'x',			//char axis,
																	*testMSchemePtr	//MappingScheme mScheme,
																	);		//vector<MidiSignal> &midiVec);
	
	list <SensorConfiguration> myList;
	myList.push_back(*testSensConfPtr);
	
	/*** Klargør ALSA-delen ***/
	
	AlsaAdapter alsaAdapter(2);
	alsaAdapter.open();

	/*** Klargør MidiModule ***/
	MidiModule myMidiModule(&alsaAdapter);
	myMidiModule.setPreset(myList);
	
	/******************************************* FUNCITON TEST ***********************************************/
	
	myMidiModule.start();
	MsgQueue* msgQPtr = myMidiModule.getMsgQueue();
	for(int i = 0; i<1; i++)
	{
		for(int i = 0; i<127; i++)
		{
			for (int index = 50; index< 54; ++index)	//opdater data
			{
				myData[i].x = index;
				myData[i].y = index;
				myData[i].z = index;
			}

			usleep(19000);		//sleep. T=20ms -> f=50Hz
			msgQPtr->send(MidiModule::DATA_MSG, &myData);
			
		}
	}

	
	msgQPtr->send(MidiModule::SHUTDOWN_MSG, NULL);
	myMidiModule.join();
	
	delete testMSchemePtr;
	delete testSensConfPtr;
	
	return 0;
}

