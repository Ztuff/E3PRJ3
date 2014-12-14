#include <vector>
#include <string>
#include "SensorConfigurationBank.hpp"

class Preset{
	public:
	Preset();
	~Preset();
	int getID()
	{
		return presetID_;
	}
	private:
	std::vector<SensorConfiguration*> sensorConfigs_;
	int presetID_;
};

class PresetBank{
	public:
	PresetBank();
	void edit(Preset pre);
	//std::vector<std::string> list();
	Preset get(int ID);
	void save();
	~PresetBank();
	
	private:
	std::vector<Preset> presets_;
};

