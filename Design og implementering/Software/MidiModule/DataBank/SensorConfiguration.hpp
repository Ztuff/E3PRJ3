#ifndef SENSORCONFIGURATION_HPP
#define SENSORCONFIGURATION_HPP

#include "MappingScheme.h"
#include <string>
#include <vector>
#include <map>

using namespace std;

class SensorConfiguration
{
	public:
		SensorConfiguration();
		SensorConfiguration( 	string name,
								int sensorID,
								char axis,
								MappingScheme mScheme
								//SoundPack sound,
								);
		~SensorConfiguration();

		/*----- GET-SET METODER -----*/
		string getName();
		int getSensorID();
		char getAxis();
		MappingScheme& getMScheme();
		int getChannel() const;
		//SoundPack getSound();
		void setName(string name);
		void setSensorID(int sensorID);
		void setAxis(char axis);
		void setMappingScheme(MappingScheme mScheme);
		//void setSoundPack(SoundPack sound);
		
	private:
		string name_;
		int sensorID_;
		char axis_;
		MappingScheme mScheme_;
		//SoundPack sound_;
		int channel_;
	
};

#endif /* SENSORCONFIGURATION_HPP */
