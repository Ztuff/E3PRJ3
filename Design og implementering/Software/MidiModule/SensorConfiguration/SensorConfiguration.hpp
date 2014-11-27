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
								int signalIndex,
								MappingScheme mScheme,
								SoundPack sound,
								vector<MidiSignal> &midiVec);
		~SensorConfiguration();

		/*----- GET-SET METODER -----*/
		string getName()
		int getSensorID()
		char getAxis()
		int getsignalIndex()
		MappingScheme getMScheme()
		SoundPack getSound()
		void setName(string name)
		void setSensorID(int sensorID)
		void setAxis(char axis)
		void setSignalIndex(int signalIndex)
		void setMappingScheme(MappingScheme mScheme)
		void setSoundPack(SoundPack sound)
		
	private:
		string name_;
		int sensorID_;
		char axis_;
		int signalIndex_;
		MappingScheme mScheme_;
		SoundPack sound_;
		vector<MidiSignal>::iterator midiIter_;
	
};