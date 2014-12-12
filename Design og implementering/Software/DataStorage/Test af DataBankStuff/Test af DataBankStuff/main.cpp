#include "DataBank.hpp"
#include <vector>
#include <string>

using namespace std; 

void testSampleBank()
{
	SampleBank sb;
	sb.add("test.mp3");
	SoundPack testSoundPack = sb.get("test.mp3");
	vector<string> testVector = sb.list();

}

void testSensorConfigurationBank()
{
	SensorConfigurationBank scb; //mapping schemes skal have et NAVN i Mapping Scheme.h filen
}

int main()
{
	//testSampleBank();
	//testSensorConfigurationBank();
	DataBank db;
	MappingScheme mScheme;
	mScheme.setId("mappingscheme4");
	mScheme.setParam("velocity");
	mScheme.setRoot("d");
	mScheme.setScale("cromatic");
	mScheme.setDirection("falling");
	mScheme.setLowerThreshold(32);
	mScheme.setCNum(8);
	mScheme.setMinVal(8);
	mScheme.setMaxVal(16);
	mScheme.setSpeed(2);
	db.saveMappingScheme(mScheme);
}

