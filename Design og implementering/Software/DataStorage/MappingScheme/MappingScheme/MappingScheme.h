#ifndef MAPPINGSCHEME_H_
#define MAPPINGSCHEME_H_

#define MAPDEBUG 1
#define CHANNELNO 16

#define SLOW 1		//Used for CCRel
#define MEDIUM 2
#define FAST 3

#include <string>
#include <iostream>
#include "MidiSignal.h"

static bool noteOn[CHANNELNO];			//These variables enable key MappingSchemes to detect when a velocity MappingScheme of same channel mutes the note.

struct Key
{
	std::string root_;					//strategies: c, cis, d, dis, e, f, fis, g, gis, a, ais, b
	std::string scale_;					//strategies: cromatic, major, minor
	std::string direction_;				//strategies: rising, falling
};
struct Velocity
{
	int lowerThreshold_;			//value from 0 to 127
};
struct ControlChange
{
	int cNum_;						//0-127
	int minVal_;					//0-127
	int maxVal_;					//0-127
	int speed_;						//strategies: SLOW, MEDIUM, FAST, egt 1,2,3
};


class MappingScheme	//KODEN KAN EVT EFFEKTIVISERES VED AT BRUGE DEFINES I STEDET FOR STRINGS I KEY
{
public:
	MappingScheme(); // der skal bruges en default constructor
	MappingScheme(	std::string id,			//bruges i SensorConfigurationsBanken for at kende forskel på MappingSchemes.
					int channel,			//kanal
					std::string param,		//strategies: "key", "velocity", "CCAbs", "CCRel"
					std::string root,		//key.root, strategies: c, cis, d, dis, e, f, fis, g, gis, a, ais, b	
					std::string scale,		//key.scale, strategies: cromatic, major, minor
					std::string direction,	//key.direction, strategies: rising, falling
					int lowerThreshold,	//velocity.lowerThreshold, value from 0 to 127
					int cNum,			//controller#
					int minVal,			//CCAbs.minVal, value from 0 to 127
					int maxVal,			//CCAbs.maxVal, value from 0 to 127
					int speed);			//CCRel.speed, strategies: SLOW, MEDIUM, FAST

	~MappingScheme();
	bool map(int data, MidiSignal & signal);	
private:
	bool mapKey(int data, MidiSignal & signal);
	bool mapVelocity(int data, MidiSignal & signal);
	bool mapCCAbs(int data, MidiSignal & signal);
	bool mapCCRel(int data, MidiSignal & signal);
	
	/*** mapKey utility ***/
	void quantizeDiatonic(int &dataIn);	//kvantiserer jf. scale- og root strategy
	int noteStringToInt(std::string note);

	std::string id_;
	std::string param_;
	Key key_;
	Velocity velocity_;
	ControlChange CC_;
	int channel_;
};

#endif /* MAPPINGSCHEME_H_ */
