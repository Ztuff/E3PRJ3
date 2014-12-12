#include "DataBank.hpp"

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

vector<string> DataBank::getSoundPacks()
{
	return sbank_.list();
}

void DataBank::saveMappingScheme(MappingScheme m)
{
	cbank_.addMappingScheme(m);
}

void DataBank::setSensorKonf(string id, string akse, string mScheme, string sPack)
{
	SensorConfiguration sensorConf;
	sensorConf.setName(id);
	sensorConf.setSensorID(id);
	sensorConf.setAxis(akse[0]);
	sensorConf.setMappingScheme(mScheme);
	sensorConf.setSoundPack(sPack);
	cbank_.add(sensorConf);
}

void DataBank::editSensorConf(SensorConfiguration sensorConf)
{
	cbank_.edit(sensorConf);
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

