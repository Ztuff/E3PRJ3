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

SensorConfiguration::SensorConfiguration(const SensorConfiguration &sensorConfigurationToCopy)
{
	name_ = sensorConfigurationToCopy.name_;
	sensorID_ = sensorConfigurationToCopy.sensorID_;
	axis_ = sensorConfigurationToCopy.axis_;
	mScheme_ = sensorConfigurationToCopy.mScheme_;
}

const SensorConfiguration& SensorConfiguration::operator=(const SensorConfiguration &right) // const return avoids: ( a1 = a2 ) = a3
{
	if (&right != this)							// avoids self-assignment
	{
		name_ = right.name_;
		sensorID_ = right.sensorID_;
		axis_ = right.axis_;
		mScheme_ = right.mScheme_;
	}

	return *this;   		// enables x = y = z
}

string SensorConfiguration::getName() const
{
	return name_;
}

int SensorConfiguration::getSensorID() const
{
	return sensorID_;
}

char SensorConfiguration::getAxis() const
{
	return axis_;
}
		
MappingScheme SensorConfiguration::getMScheme() const
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

