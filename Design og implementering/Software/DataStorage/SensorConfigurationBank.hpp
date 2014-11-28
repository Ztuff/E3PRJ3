#include "MappingScheme\MappingScheme.h"
#include "SampleBank.hpp"
#include "SensorConfiguration.hpp"
#include <string>
#include <vector>
#include <map>

class SensorConfigurationBank
{	
public:
	SensorConfigurationBank();
	MappingScheme getMappingScheme(std::string id);
	std::vector<std::string> getSensorIDs();
	std::vector<std::string> getMappingSchemes();
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
	
