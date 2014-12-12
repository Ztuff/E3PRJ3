#include "MappingScheme\MappingScheme.h"
#include "SampleBank.hpp"
#include <string>
#include <vector>
#include <map>

class SensorConfiguration
{
	public:
		SensorConfiguration(); //default-constructor
		SensorConfiguration( 	string name,
								string sensorID,
								char axis,
								string mScheme,
								SoundPack sound,
								std::vector<MidiSignal> &midiVec);
		~SensorConfiguration();

		/*----- GET-SET METODER -----*/
		string getName();
		string getSensorID();
		char getAxis();
		string getMScheme();
		SoundPack getSound();
		void setName(std::string name);
		void setSensorID(string sensorID);
		void setAxis(char axis);
		void setMappingScheme(string mScheme); 
		void putNewMappingScheme(string mScheme); //Når en helt ny sensorkonfiguration tilføjes
		void setSoundPack(SoundPack sound);
		
	private:
		std::string name_;
		string sensorID_;
		char axis_;
		string mScheme_;
		SoundPack sound_;
		std::vector<MidiSignal>::iterator midiIter_;
};