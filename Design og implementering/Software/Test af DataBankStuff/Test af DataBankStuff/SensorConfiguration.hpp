#include "MappingScheme\MappingScheme.h"
#include "SampleBank.hpp"
#include <string>
#include <vector>
#include <map>

using namespace std;

class SensorConfiguration
{
	public:
		SensorConfiguration(); //default-constructor
		SensorConfiguration( 	string name,
								int sensorID,
								char axis,
								MappingScheme mScheme,
								SoundPack sound,
								vector<MidiSignal> &midiVec);
		~SensorConfiguration();

		/*----- GET-SET METODER -----*/
		string getName();
		int getSensorID();
		char getAxis();
		MappingScheme &getMScheme();
		SoundPack getSound();
		void setName(string name);
		void setSensorID(int sensorID);
		void setAxis(char axis);
		void setMappingScheme(MappingScheme &mScheme);
		void setSoundPack(SoundPack sound);
		
	private:
		string name_;
		int sensorID_;
		char axis_;
		MappingScheme mScheme_;
		SoundPack sound_;
		vector<MidiSignal>::iterator midiIter_;
	
};