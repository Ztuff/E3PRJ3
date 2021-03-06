#include "SensorConfiguration.hpp"

SensorConfiguration::SensorConfiguration()
{
	SoundPack sound;
	string defaultName = "Default Sensorconfiguration";
	char defaultAxis = 'x';
	vector<MidiSignal> midiVec;
	SensorConfiguration(defaultName, "Accelerometer", defaultAxis, "mappingscheme1", sound, midiVec);
}

/** Udvider vector med "num" og initialiserer til default **/
vector<MidiSignal>::iterator MidiSignalVectorAdd(vector<MidiSignal> &vec, int num)	
{
	for (int i = 0; i < num; ++i)
	{
		vec.push_back(MidiSignal());
		
		vec[i].channel_='0';
		vec[i].command_=NOTEOFF;
		vec[i].param1_=0;
		vec[i].param2_=0;
		vec[i].param1Old_=0;
		vec[i].param2Old_=0;
	}
	
	return vec.end();
}

SensorConfiguration::SensorConfiguration(	string name,
											string sensorID,
											char axis,
											string mScheme,
											SoundPack sound,
											vector<MidiSignal> &midiVec)
{
	name_ 			= name;
	sensorID_ 		= sensorID;
	axis_			= axis;
	mScheme_ 		= mScheme;
	sound_			= sound;
	
	midiIter_ = MidiSignalVectorAdd(midiVec, 1);	/*	MidiIter er attribut i SensorKonfiguration
													MidiSignalVectorAdd returnerer iterator til den nye sidste plads i vector
													og modtager parametrene(vector&, #nyePladser) */
}

SensorConfiguration::~SensorConfiguration()
{

}

string SensorConfiguration::getName()
{
	return name_;
}

string SensorConfiguration::getSensorID()
{
	return sensorID_;
}

char SensorConfiguration::getAxis()
{
	return axis_;
}
		
string SensorConfiguration::getMScheme()
{
	return mScheme_;
}
		
SoundPack SensorConfiguration::getSound()
{
	return sound_;
}
		
void SensorConfiguration::setName(string name)
{
	name_ = name;
}

void SensorConfiguration::setSensorID(string sensorID)
{
	sensorID_ = sensorID;
}

void SensorConfiguration::setAxis(char axis)
{
	axis_ = axis;
}

void SensorConfiguration::setMappingScheme(string mScheme)
{
	mScheme_ = mScheme;
}

void SensorConfiguration::setSoundPack(SoundPack sound)
{
	sound_ = sound;
}

