#include "SensorConfigurationBank.hpp"

SensorConfigurationBank::SensorConfigurationBank()
{	
	//læs fra fil... gem i sensorConfigurations
	sensorConfigurations_ = sensorConfigurations;
}

SensorConfigurationBank::~SensorConfigurationBank()
{

}

void SensorConfigurationBank:: edit(string key)
{
	sensorConfigurations_.erase(key);
	add(key);
}

void SensorConfigurationBank:: list() //I tvivl om Void-returtypen
{
	//Burde den ikke sende en reference eller hele sensorConfigurations_ tilbage til DataStorage-klassen...?
}

SensorConfiguration SensorConfigurationBank:: get(string key)
{
	return sensorConfigurations_[key];
}

void SensorConfigurationBank:: add(SensorConfiguration sensorConf, string key) //key'en skal være det samme som navnet på sensorkonfigurationen
{
	sensorConfigurations_.insert(std::make_pair(key, sensorConf)); //Forbinder key med sensorkonfiguration og indsætter den i banken.
	saveAll();
}

void SensorConfigurationBank:: removeSensorConf(string key) //key eller sensorID?
{
	sensorConfigurations_.erase(key);
	saveAll();
}

void SensorConfigurationBank::saveBank()
{
	//gem i XML
}


SensorConfiguration::SensorConfiguration(
	string name,
	int sensorID,
	int signalIndex,
	MIDIParameter midiParam,
	MappingScheme mScheme,
	Soundpack sound)
{
	name_ 			= name;
	sensorID_ 		= sensorID;
	signalIndex_ 	= signalIndex;
	midiParam_ 		= midiParam;
	mScheme_ 		= mScheme;
	sound_			= sound;
}

SensorConfiguration::~SensorConfiguration()
{
}
