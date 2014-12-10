#include "PresetBank.hpp"

class DataBank
{
public:
	DataBank();
	~DataBank();
	std::vector<std::string>		getMappingSchemes();
	std::vector<std::string>		getSensorIDs();
	std::vector<std::string>		getSoundPacks();

	void saveSensorConf(SensorConfiguration sensorConf); //tilføjer sensorkonf til banken og derefter gemmer banken selv
	void editSensorConf(SensorConfiguration sensorConf);
	void removeSensorConf(SensorConfiguration sensorConf);
	void saveSample(SoundPack sound);
	void removeSample(SoundPack sound);
	void savePreset(Preset p);

	
private:
	PresetBank pbank_;
	SampleBank sbank_;
	SensorConfigurationBank cbank_;
};