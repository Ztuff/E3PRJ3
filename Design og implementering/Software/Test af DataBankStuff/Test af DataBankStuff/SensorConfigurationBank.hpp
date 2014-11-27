#include "MappingScheme\MappingScheme.h"
#include "SampleBank.hpp"
#include <string>
#include <vector>
#include <map>

class SensorConfiguration{
	public:
	SensorConfiguration();
	SensorConfiguration( 	std::string name,
							int sensorID,
							char axis,
							int signalIndex,
							MappingScheme mScheme,
							SoundPack sound);
	~SensorConfiguration();

	/*----- GET-SET METODER -----*/
	std::string getName()
	{
		return name_;
	}

	int getSensorID()
	{
		return sensorID_;
	}

	char getAxis()
	{
		return axis_;
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

	void setSensorID(int sensorID)
	{
		sensorID_ = sensorID;
	}

	void setAxis(char axis)
	{
		axis_ = axis;
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
	int sensorID_;
	char axis_;
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
	
