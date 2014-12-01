#include "DataBank.h"
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
	testSensorConfigurationBank();
	DataBank db;
	vector<string> mappingSchemes = db.getSensorIDs();
}

