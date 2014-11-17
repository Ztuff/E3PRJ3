#ifndef MAPPINGSCHEME_H_
#define MAPPINGSCHEME_H_

#define DEBUG 0

#include <string>
#include <iostream>

using namespace std;

struct MidiSignal
{
	int channel_;
	int command_;
	int param1_;
	int param2_;

	void print()
	{
		cout<<   "     channel_ = " << channel_
			<< "\n     command_ = 0x"<< hex << command_
			<< "\n     param1_ = "<< param1_
			<< "\n     param2_ = "<< param2_ << endl;
	}
};


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
struct CCAbs
{
	int minVal_;					//0-127
	int maxVal_;					//0-127
};
struct CCRel						/**** dataIn is Rel CC change with 0-point at 64 ****/
{
	string speed_;					//strategies: "slow", "medium", "fast"
};

class MappingScheme
{
public:
	MappingScheme(string param,	
					string root,		//key.root, strategies: c, cis, d, dis, e, f, fis, g, gis, a, ais, b	
					string scale,		//key.scale, strategies: cromatic, major, minor
					string direction,	//key.direction, strategies: rising, falling
					int lowerThreshold,	//velocity.lowerThreshold, value from 0 to 127
					int minVal,			//CCAbs.minVal, value from 0 to 127
					int maxVal,			//CCAbs.maxVal, value from 0 to 127
					string speed);		//CCRel.speed, strategies: "slow", "medium", "fast"

	bool map(int data, MidiSignal & signal);	
private:
	bool mapKey(int data, MidiSignal & signal);
	bool mapVelocity(int data, MidiSignal & signal);
	bool mapCCAbs(int data, MidiSignal & signal);
	bool mapCCRel(int data, MidiSignal & signal);
	
	/*** mapKey utility ***/
	void quantizeDiatonic(int &dataIn);			//kvantiserer jf. scale- og root strategy
	int noteStringToInt(string note);	
	int param1Old_;

	string param_;
	Key key_;
	Velocity velocity_;
	CCAbs CCAbs_;
	CCRel CCRel_;
};

#endif /* MAPPINGSCHEME_H_ */