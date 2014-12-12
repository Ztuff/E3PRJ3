#include <unistd.h>
#include "MidiModule/MidiModule.hpp"
#include "MidiModule/DataBank/SensorConfiguration.hpp"
#include "MidiModule/DataBank/MappingScheme.h"
#include "MidiModule/DataMsg.hpp"
#include "BT/Receiver.hpp"

#define DEBUG 1

int main()
{
	/****************************************** INITIALIZATION **********************************************/
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
	
	AlsaAdapter alsaAdapter(2);
	alsaAdapter.open();

	/*** Klargør MidiModule ***/
	MidiModule myMidiModule(&alsaAdapter);
	myMidiModule.setPreset(myList);
	
	
	/******************************************* FUNCITON TEST ***********************************************/
	
	myMidiModule.start();
	
	Receiver rx(myMidiModule.getMsgQueue());
	rx.start(100);	

	myMidiModule.join();
	
	delete testSensConfPtr;
	delete testMSchemePtr;
	
	return 0;
}

