#include "MappingScheme\MappingScheme.h"
#include "SampleBank.hpp"
#include <string>
#include <vector>
#include <map>

class SensorConfiguration
{
	public:
		SensorConfiguration(); //default-constructor
		SensorConfiguration( 	std::string name,
								int sensorID,
								char axis,
								MappingScheme mScheme,
								SoundPack sound,
								std::vector<MidiSignal> &midiVec);
		~SensorConfiguration();

		/*----- GET-SET METODER -----*/
		std::string getName();
		int getSensorID();
		char getAxis();
		MappingScheme &getMScheme();
		SoundPack getSound();
		void setName(std::string name);
		void setSensorID(int sensorID);
		void setAxis(char axis);
		void setMappingScheme(MappingScheme &mScheme);
		void setSoundPack(SoundPack sound);
		
	private:
		std::string name_;
		int sensorID_;
		char axis_;
		MappingScheme mScheme_;
		SoundPack sound_;
		std::vector<MidiSignal>::iterator midiIter_;
};