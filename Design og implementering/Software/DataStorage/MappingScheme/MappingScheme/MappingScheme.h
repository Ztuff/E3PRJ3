#ifndef MAPPINGSCHEME_H_
#define MAPPINGSCHEME_H_

#define DEBUG 0

#define SLOW 1		//Used for CCRel
#define MEDIUM 2
#define FAST 3

#include <string>
#include <iostream>
#include "MidiSignal.h"

using namespace std;

struct Key
{
	string root_;					//strategies: c, cis, d, dis, e, f, fis, g, gis, a, ais, b
	string scale_;					//strategies: cromatic, major, minor
	string direction_;				//strategies: rising, falling
};
struct Velocity
{
	int lowerThreshold_;			//value from 0 to 127
};
struct ContControl
{
	int cNum_;						//0-127
	int minVal_;					//0-127
	int maxVal_;					//0-127
	int speed_;						//strategies: SLOW, MEDIUM, FAST, egt 1,2,3
};
struct CCRel						/**** dataIn is Rel CC change with 0-point at 64 ****/
{
	int cNum_;						//0-127
	
};

class MappingScheme	//KODEN KAN EVT EFFEKTIVISERES VED AT BRUGE DEFINES I STEDET FOR STRINGS I KEY
{
public:
	MappingScheme(); // der skal bruges en default constructor
	MappingScheme(	string id,			//bruges i SensorConfigurationsBanken for at kende forskel på MappingSchemes.
					string param,		//strategies: "key", "velocity", "CCAbs", "CCRel"
					string root,		//key.root, strategies: c, cis, d, dis, e, f, fis, g, gis, a, ais, b	
					string scale,		//key.scale, strategies: cromatic, major, minor
					string direction,	//key.direction, strategies: rising, falling
					int lowerThreshold,	//velocity.lowerThreshold, value from 0 to 127
					int cNum,			//controller#
					int minVal,			//CCAbs.minVal, value from 0 to 127
					int maxVal,			//CCAbs.maxVal, value from 0 to 127
					int speed);			//CCRel.speed, strategies: SLOW, MEDIUM, FAST

	bool map(int data, MidiSignal & signal);	
private:
	bool mapKey(int data, MidiSignal & signal);
	bool mapVelocity(int data, MidiSignal & signal);
	bool mapCCAbs(int data, MidiSignal & signal);
	bool mapCCRel(int data, MidiSignal & signal);
	
	/*** mapKey utility ***/
	void quantizeDiatonic(int &dataIn);	//kvantiserer jf. scale- og root strategy
	int noteStringToInt(string note);

	string id_;
	string param_;
	Key key_;
	Velocity velocity_;
	ContControl CC_;
};

#endif /* MAPPINGSCHEME_H_ */