#include "MappingScheme/MappingScheme/MappingScheme.h"
#include <string>
class SensorConfigurationBank{
	public:
	SensorConfigurationBank();
	~SensorConfigurationBank();
	void edit(string key);
	string[] list(); //returtype?
	SensorConfiguration get(string key);
	void add(SensorConfiguration);
	void removeSensorConf(string key);
	void saveBank();
	
	private:
	map<SensorConfiguration> sensorConfigurations_;
	
};
	
class SensorConfiguration{
	public:
	SensorConfiguration( 	string name,
							int sensorID,
							int signalIndex,
							MIDIParameter midiParam,
							MappingScheme mScheme,
							Soundpack sound);
	~SensorConfiguration();
	
	private:
	string name_;
	int sensorID_;
	int signalIndex_;
	MIDIParameter midiParam_;
	MappingScheme mScheme_;
	Soundpack sound_;
	
};