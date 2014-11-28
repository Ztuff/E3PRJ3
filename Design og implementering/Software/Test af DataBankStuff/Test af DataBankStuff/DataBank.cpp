#include "DataBank.h"

using namespace std;

DataBank::DataBank()
{
}

DataBank::~DataBank()
{

}

vector<string> DataBank::getMappingSchemes()
{
	return cbank_.getMappingSchemes();
}

vector<string> DataBank::getSensorIDs()
{
	return cbank_.getSensorIDs();
}

void DataBank::saveSensorConf(SensorConfiguration sensorConf)
{
	cbank_.add(sensorConf);
}

void DataBank::removeSensorConf(SensorConfiguration sensorConf)
{
	cbank_.removeSensorConf(sensorConf.getName());
}

void DataBank::saveSample(SoundPack sound)
{
	sbank_.add(sound.filepath_);
}

void DataBank::removeSample(SoundPack sound)
{
	sbank_.add(sound.filepath_);
}

