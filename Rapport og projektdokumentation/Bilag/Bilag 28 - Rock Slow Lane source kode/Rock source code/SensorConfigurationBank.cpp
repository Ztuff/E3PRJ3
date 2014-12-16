#include "SensorConfigurationBank.hpp"
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/foreach.hpp>
#include <sstream>

SensorConfigurationBank::SensorConfigurationBank()
{	
	using boost::property_tree::ptree;
	ptree pt;
	read_xml("SensorConfigurationBank.xml", pt); //kør fejlhåndtering her. hvis den ikke er der, lav den
	loadMappingSchemes();
	BOOST_FOREACH(ptree::value_type &v, pt.get_child("root.sensorconfigurations"))
	{
		if (v.first == "configuration")
		{
			string name;
			string sensorid;
			char axis;
			string mscheme;
			SoundPack sound;
			BOOST_FOREACH(ptree::value_type &w,v.second)
			{
				if(w.first == "name")
				{
					name =w.second.data();
				}
				if(w.first == "sensorid")
				{
					sensorid = w.second.data();
				}
				if(w.first == "axis")
				{
                    axis = w.second.data()[0];
				}
				if(w.first == "mappingscheme")
				{
					mscheme = w.second.data();
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

vector<string> SensorConfigurationBank::getMappingSchemes()
{
	vector<string> mappingSchemeList;
	for(map<string, MappingScheme>:: iterator it = mappingSchemes_.begin(); it != mappingSchemes_.end(); ++it) 
	{
		mappingSchemeList.push_back(it->first);
	}
	return mappingSchemeList;
}

void SensorConfigurationBank::loadMappingSchemes()
{
	string m_level;
	using boost::property_tree::ptree;
	ptree pt;
	read_xml("MappingSchemes.xml", pt);

	BOOST_FOREACH(ptree::value_type &v, pt.get_child("root.mappingschemes"))
	{
		ptree pt = v.second;
		MappingScheme myMappingScheme;
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
		mappingSchemes_.insert(std::make_pair(myMappingScheme.getId(), myMappingScheme));
	}
}

MappingScheme SensorConfigurationBank::getMappingScheme(string id) //finder specifikt mapping scheme i MappingSchemes.xml
{
	return mappingSchemes_[id];
}

void SensorConfigurationBank::addMappingScheme(MappingScheme mScheme)
{
	mappingSchemes_.insert(std::make_pair(mScheme.getId(), mScheme));
	saveMappingSchemes();
}

void SensorConfigurationBank::saveMappingSchemes()
{
	using boost::property_tree::ptree;
	ptree pt;
	for(map<string, MappingScheme>:: iterator it = mappingSchemes_.begin(); it != mappingSchemes_.end(); ++it) 
	{
		ptree myTree;
		myTree.put("id", it->second.getId());
		myTree.put("param", it->second.getParam());
		myTree.put("root", it->second.getRoot());
		myTree.put("scale", it->second.getScale());
		myTree.put("direction", it->second.getDirection());
		myTree.put("lowerthreshold", it->second.getLowerThreshold());
		myTree.put("cnum", it->second.getCNum());
		myTree.put("minval", it->second.getMinVal());
		myTree.put("maxval", it->second.getMaxVal());
		myTree.put("speed", it->second.getSpeed());

		pt.add_child("root.mappingschemes.scheme", myTree);
	}
    write_xml("MappingSchemes.xml", pt);
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
		myTree.put("mappingscheme", it->second.getMScheme());
		SoundPack mySound = it->second.getSound();
		myTree.put("soundpack", mySound.filepath_);

		pt.add_child("root.sensorconfigurations.configuration", myTree);
	}
    write_xml("SensorConfigurationBank.xml", pt);
}
