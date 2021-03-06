#include "SensorConfiguration.hpp"

SensorConfiguration::SensorConfiguration()
{
	MappingScheme mScheme;
	//SoundPack sound;
	string defaultName = "Default Sensorconfiguration";
	char defaultAxis = 'x';
	SensorConfiguration(defaultName, 1, defaultAxis, mScheme/*, sound*/);
}

SensorConfiguration::SensorConfiguration(	string name,
											int sensorID,
											char axis,
											MappingScheme mScheme
											//SoundPack sound,
											)
{
	name_ 			= name;
	sensorID_ 		= sensorID;
	axis_			= axis;
	mScheme_ 		= mScheme;
	//sound_		= sound;
}

SensorConfiguration::~SensorConfiguration()
{

}

string SensorConfiguration::getName()
{
	return name_;
}

int SensorConfiguration::getSensorID()
{
	return sensorID_;
}

char SensorConfiguration::getAxis()
{
	return axis_;
}

int SensorConfiguration::getChannel() const
{
	return channel_;
}
		
MappingScheme& SensorConfiguration::getMScheme()
{
	return mScheme_;
}

/*SoundPack SensorConfiguration::getSound()
{
	return sound_;
}*/
		
void SensorConfiguration::setName(string name)
{
	name_ = name;
}

void SensorConfiguration::setSensorID(int sensorID)
{
	sensorID_ = sensorID;
}

void SensorConfiguration::setAxis(char axis)
{
	axis_ = axis;
}

void SensorConfiguration::setMappingScheme(MappingScheme mScheme)
{
	mScheme_ = mScheme;
}

/*void SensorConfiguration::setSoundPack(SoundPack sound)
{
	sound_ = sound;
}*/

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
		
	}
	
	return vec.end();
}

