#include "MappingScheme.h"
#include "SampleBank.hpp"
#include "SensorConfiguration.hpp"
#include <string>
#include <vector>
#include <map>

class SensorConfigurationBank
{	
public:
	SensorConfigurationBank();
	void addMappingScheme(MappingScheme mScheme);
	void loadMappingSchemes();
	void saveMappingSchemes();
	MappingScheme getMappingScheme(std::string id);
	std::vector<std::string> getMappingSchemes();
	std::vector<std::string> getSensorIDs();
	~SensorConfigurationBank();
	void edit(SensorConfiguration sensorConf);
	std::vector<std::string> list();
	SensorConfiguration get(std::string key);
	
	void add(SensorConfiguration sensorConf);
	void removeSensorConf(std::string key);
	void save();
	
private:
	std::map<std::string, SensorConfiguration> sensorConfigurations_;
	std::map<std::string, MappingScheme> mappingSchemes_;
};
	
