#include "PresetBank.h"
#include "SensorConfigurationBank.h"
#include "SoundPackBank.h"

class DataStorage{
	public:
	DataStorage();
	DataStorage(String dsfPath);
	~DataStorage();
	const Preset* getActivePreset();
	bool setActivePreset(const int);
	
	private:
	PresetBank presets_;
	SensorConfigurationBank sensorConfigs_;
	SoundPackBank soundPacks_;
};
