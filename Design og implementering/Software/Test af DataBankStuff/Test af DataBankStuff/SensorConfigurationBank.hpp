#include "MappingScheme\MappingScheme.h"
#include "SampleBank.hpp"
#include <string>
#include <vector>
#include <map>

class SensorConfiguration{
	public:
	SensorConfiguration();
	SensorConfiguration( 	std::string name,
							std::string sensorID,
							int signalIndex,
							MappingScheme mScheme,
							SoundPack sound);
	~SensorConfiguration();

	/*----- GET-SET METODER -----*/
	std::string getName()
	{
		return name_;
	}

	std::string getSensorID()
	{
		return sensorID_;
	}

	int getsignalIndex()
	{
		return signalIndex_;
	}
	
	MappingScheme getMScheme()
	{
		return mScheme_;
	}
	
	SoundPack getSound()
	{
		return sound_;
	}
	
	void setName(std::string name)
	{
		name_ = name;
	}

	void setSensorID(std::string sensorID)
	{
		sensorID_ = sensorID;
	}

	void setSignalIndex(int signalIndex)
	{
		signalIndex_ = signalIndex;
	}

	void setMappingScheme(MappingScheme mScheme)
	{
		mScheme_ = mScheme;
	}

	void setSoundPack(SoundPack sound)
	{
		sound_ = sound;
	}
	/*----- GET-SET METODER -----*/
	private:
	std::string name_;
	std::string sensorID_;
	int signalIndex_;
	MappingScheme mScheme_;
	SoundPack sound_;
	
};
class SensorConfigurationBank
{	
public:
	SensorConfigurationBank();
	MappingScheme getMappingScheme(std::string id);
	~SensorConfigurationBank();
	void edit(SensorConfiguration sensorConf);
	std::vector<std::string> list();
	SensorConfiguration get(std::string key);
	
	void add(SensorConfiguration sensorConf);
	void removeSensorConf(std::string key);
	void save();
	
private:
	std::map<std::string, SensorConfiguration> sensorConfigurations_;
};
	
