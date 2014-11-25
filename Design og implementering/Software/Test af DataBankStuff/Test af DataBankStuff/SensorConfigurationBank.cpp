#include "SensorConfigurationBank.hpp"
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/foreach.hpp>
#include <sstream>

SensorConfigurationBank::SensorConfigurationBank()
{	
	//læs fra fil... gem i sensorConfigurations
	string m_level;
	using boost::property_tree::ptree;
	ptree pt;
	read_xml("SensorConfigurationBank.xml", pt); //kør fejlhåndtering her. hvis den ikke er der, lav den

	BOOST_FOREACH(ptree::value_type &v, pt.get_child("root.sensorconfigurations"))
	{
		if (v.first == "configuration")
		{
			SensorConfiguration newSensorConf;
			BOOST_FOREACH(ptree::value_type &w,v.second)
			{
				if(w.first == "name")
				{
					newSensorConf.setName(w.second.data());
				}
				if(w.first == "sensorid")
				{
					string stringToInt = w.second.data();
					istringstream iss(stringToInt);
					int value;
					iss >> value;
					newSensorConf.setSensorID(value);
				}
				if(w.first == "signalindex")
				{
					string stringToInt = w.second.data();
					istringstream iss(stringToInt);
					int value;
					iss >> value;
					newSensorConf.setSignalIndex(value);
				}
				if(w.first == "mappingscheme")
				{
					newSensorConf.setMappingScheme(getMappingScheme(w.second.data()));
				}
				if(w.first == "soundpack")
				{
					newSensorConf.setSoundPack(w.second.data());
				}
			}
			sensorConfigurations_.insert(make_pair(newSensorConf.getName(), newSensorConf));
		}
	}
	//save();
}

MappingScheme SensorConfigurationBank::getMappingScheme(string id) //finder specifikt mapping scheme i MappingSchemes.xml
{
	string m_level;
	using boost::property_tree::ptree;
	ptree pt;
	read_xml("MappingSchemes.xml", pt);
	MappingScheme newMappingScheme;
	//get de 10 parametre fra den xml node med den id node der indeholder 'id'
	return newMappingScheme;
}

SensorConfigurationBank::~SensorConfigurationBank()
{
	//save();
}

void SensorConfigurationBank:: edit(SensorConfiguration sensorConf)
{
	sensorConfigurations_.erase(sensorConf.getName());
	add(sensorConf);
}

vector<string> SensorConfigurationBank:: list()
{
	vector<string> sensorConfigs;
	for(map<string, SensorConfiguration>:: iterator it = sensorConfigurations_.begin(); it != sensorConfigurations_.end(); ++it) 
	{
		sensorConfigs.push_back(it->first);
	}
	return sensorConfigs;
}

SensorConfiguration SensorConfigurationBank:: get(string key)
{
	return sensorConfigurations_[key];
}

void SensorConfigurationBank:: add(SensorConfiguration sensorConf) //key'en skal være det samme som navnet på sensorkonfigurationen
{
	sensorConfigurations_.insert(std::make_pair(sensorConf.getName(), sensorConf)); //Forbinder key med sensorkonfiguration og indsætter den i banken.
	save();
}

void SensorConfigurationBank:: removeSensorConf(string key) //key eller sensorID?
{
	sensorConfigurations_.erase(key);
	save();
}

void SensorConfigurationBank::save()
{
	using boost::property_tree::ptree;
	ptree pt;
	pt.put("root.sensorconfigurations", "");
	for(map<string, SensorConfiguration>:: iterator it = sensorConfigurations_.begin(); it != sensorConfigurations_.end(); ++it) 
	{
		//tilføj node som har (sensorconfiguration-attributer)-mængder af child-nodes
	}
	write_xml("SensorConfigurationBank.xml", pt); //Sletter den gamle fil (hvis den er der) og laver en helt ny, i princippet.
}

SensorConfiguration::SensorConfiguration()
{
	MappingScheme mScheme;
	SoundPack sound;
	string defaultString = "Default Sensorconfiguration";
	SensorConfiguration(defaultString, -1, -1, mScheme, sound);
}

SensorConfiguration::SensorConfiguration(
	string name,
	int sensorID,
	int signalIndex,
	MappingScheme mScheme,
	SoundPack sound)
{
	name_ 			= name;
	sensorID_ 		= sensorID;
	signalIndex_ 	= signalIndex;
	mScheme_ 		= mScheme;
	sound_			= sound;
}

SensorConfiguration::~SensorConfiguration()
{
}
