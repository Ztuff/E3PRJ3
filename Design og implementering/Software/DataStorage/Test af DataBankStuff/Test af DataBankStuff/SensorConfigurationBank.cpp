#include "SensorConfigurationBank.hpp"
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/foreach.hpp>
#include <sstream>

SensorConfigurationBank::SensorConfigurationBank()
{	
	string m_level;
	using boost::property_tree::ptree;
	ptree pt;
	read_xml("SensorConfigurationBank.xml", pt); //kør fejlhåndtering her. hvis den ikke er der, lav den

	BOOST_FOREACH(ptree::value_type &v, pt.get_child("root.sensorconfigurations"))
	{
		if (v.first == "configuration")
		{
			string name;
			int sensorid;
			char axis;
			MappingScheme mscheme;
			SoundPack sound;
			BOOST_FOREACH(ptree::value_type &w,v.second)
			{
				if(w.first == "name")
				{
					name =w.second.data();
				}
				if(w.first == "sensorid")
				{
					string stringToInt = w.second.data();
					istringstream iss(stringToInt);
					iss >> sensorid;
				}
				if(w.first == "axis")
				{
					axis = w.second.data().back();
				}
				if(w.first == "mappingscheme")
				{
					mscheme = getMappingScheme(w.second.data());
				}
				if(w.first == "soundpack")
				{
					sound = w.second.data();
				}
			}
			vector<MidiSignal> midiVec;
			SensorConfiguration newSensorConf(name, sensorid, axis, mscheme, sound, midiVec);
			sensorConfigurations_.insert(make_pair(newSensorConf.getName(), newSensorConf));
		}
	}
	save();
}

vector<string> SensorConfigurationBank::getMappingSchemes()
{
	using boost::property_tree::ptree;
	ptree pt;
	read_xml("MappingSchemes.xml", pt);
	vector<string> myMappingSchemeList;

	BOOST_FOREACH(ptree::value_type &v, pt.get_child("root.mappingschemes"))
	{
		BOOST_FOREACH(ptree::value_type &w, v.second)
		{
			if (w.first == "id")
			{
				myMappingSchemeList.push_back(w.second.data());
			}
		}
	}
	return myMappingSchemeList;
}

vector<string> SensorConfigurationBank::getSensorIDs()
{
	using boost::property_tree::ptree;
	ptree pt;
	read_xml("SensorConfigurationBank.xml", pt);
	vector<string> mySensorIDs;

	BOOST_FOREACH(ptree::value_type &v, pt.get_child("root.sensorconfigurations"))
	{
		BOOST_FOREACH(ptree::value_type &w, v.second)
		{
			if (w.first == "sensorid")
			{
				mySensorIDs.push_back(w.second.data());
			}
		}
	}
	return mySensorIDs;
}

MappingScheme SensorConfigurationBank::getMappingScheme(string id) //finder specifikt mapping scheme i MappingSchemes.xml
{
	string m_level;
	using boost::property_tree::ptree;
	ptree pt;
	read_xml("MappingSchemes.xml", pt);
	MappingScheme myMappingScheme;

	BOOST_FOREACH(ptree::value_type &v, pt.get_child("root.mappingschemes"))
	{
		ptree pt = v.second;
		string checkID = pt.get<string>("id");
		if ( checkID == id)
		{
			BOOST_FOREACH(ptree::value_type &w,v.second)
			{	
				if(w.first == "id"){
					myMappingScheme.setId(w.second.data());
				}
				if(w.first == "param"){
					myMappingScheme.setParam(w.second.data());
				}
				if(w.first == "root"){
					myMappingScheme.setRoot(w.second.data());
				}
				if(w.first == "scale"){
					myMappingScheme.setScale(w.second.data());
				}
				if(w.first == "direction"){
					myMappingScheme.setDirection(w.second.data());
				}
				if(w.first == "lowerthreshold"){
					string stringToInt = w.second.data();
					istringstream iss(stringToInt);
					int value;
					iss >> value;
					myMappingScheme.setLowerThreshold(value);
				}
				if(w.first == "cnum"){
					string stringToInt = w.second.data();
					istringstream iss(stringToInt);
					int value;
					iss >> value;
					myMappingScheme.setCNum(value);
				}
				if(w.first == "minval"){
					string stringToInt = w.second.data();
					istringstream iss(stringToInt);
					int value;
					iss >> value;
					myMappingScheme.setMinVal(value);
				}
				if(w.first == "maxval"){
					string stringToInt = w.second.data();
					istringstream iss(stringToInt);
					int value;
					iss >> value;
					myMappingScheme.setMaxVal(value);
				}
				if(w.first == "speed"){
					string stringToInt = w.second.data();
					istringstream iss(stringToInt);
					int value;
					iss >> value;
					myMappingScheme.setSpeed(value);
				}
			}
		}
	}
	return myMappingScheme;
}

SensorConfigurationBank::~SensorConfigurationBank()
{
	save();
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
	for(map<string, SensorConfiguration>:: iterator it = sensorConfigurations_.begin(); it != sensorConfigurations_.end(); ++it) 
	{
		ptree myTree;
		myTree.put("name", it->second.getName());
		myTree.put("sensorid", it->second.getSensorID());
		myTree.put("axis", it->second.getAxis());
		MappingScheme myScheme = it->second.getMScheme();
		myTree.put("mappingscheme", myScheme.getId());
		SoundPack mySound = it->second.getSound();
		myTree.put("soundpack", mySound.filepath_);

		pt.add_child("root.sensorconfigurations.configuration", myTree);
	}
	boost::property_tree::xml_writer_settings<std::string> settings('\t', 1);
	write_xml("SensorConfigurationBank.xml", pt, std::locale(), settings);
}