#include "MappingScheme.h"

using namespace std;

MappingScheme:: MappingScheme()
{
	MappingScheme("defaultID", 1, "velocity", "0", "0", "0", 0, 0, 0, 0, SLOW);
}

MappingScheme::	MappingScheme(	string id,
								int channel,
								string param,	
								string root,		//key
								string scale,		//key
								string direction,	//key
								int lowerThreshold,	//velocity
								int cNum,			//CC (both)
								int minVal,			//CCAbs
								int maxVal,			//CCAbs
								int speed)			//CCRel
{
	/*** Initailize atributes ***/

	id_= id;

	channel_=((channel < 16 || channel >= 0) ? channel : 1);

	param_=((param == "key" || param == "velocity" || param == "CCAbs" || param == "CCRel") ? param : "velocity");

	key_.root_=((root == "c" || root == "cis" || root == "d" || root == "dis" || root == "e" || root == "f" || root == "fis" 
		|| root == "g" || root == "gis" || root == "a" || root == "ais" || root == "b") ? root : "0");

	key_.scale_=((scale == "cromatic" || scale == "major" || scale == "minor") ? scale : "0");

	key_.direction_=((direction == "rising" || direction == "falling") ? direction : "0");

	velocity_.lowerThreshold_=((lowerThreshold < 128 || lowerThreshold >= 0) ? lowerThreshold : 0);

	CC_.cNum_=((cNum < 128 || cNum >= 0) ? cNum : 0); //set both CCAbs and CCRel 
	
	CC_.minVal_=((minVal < 128 || minVal >= 0) ? minVal : 0);
	
	CC_.maxVal_=((maxVal < 128 || maxVal >= 0) ? maxVal : 0);
	
	CC_.speed_ = ((speed == SLOW || speed == MEDIUM || speed == FAST) ? speed : SLOW);

	for (int i = 0; i<CHANNELNO; i++)
	{
		noteOn[i] = 1;				//Initialize noteOn to 1 as default
	}
}

MappingScheme::~MappingScheme()
{
	for (int i = 0; i<CHANNELNO; i++)
	{
		noteOn[i] = 1;				//set noteOn to 1
	}
}

bool MappingScheme::map(int data, MidiSignal & signal)
{
	if(MAPDEBUG)
		cout << "Inside map\n";

	if(param_ == "key")
		mapKey(data, signal);
	else if(param_ == "velocity")
		mapVelocity(data, signal);
	else if(param_ == "CCAbs") 
		mapCCAbs(data, signal);
	else if(param_ == "CCRel") 
		mapCCRel(data, signal);
	else
	{
		cout << "ERROR: Calling map for undefined param" << endl;
		return 0;
	}
	return 1;
}

bool MappingScheme::mapKey(int data, MidiSignal & signal)
{
	if(MAPDEBUG)
		cout << "Inside mapKey\n";

	signal.channel_ = channel_;

	/*** omkonvertering til v�rdi mellem 0-119. dataIn v�rdier fra 3-122 benyttes ***/
	if(2 < data && data < 122)							
		data-= 3; 		
	else
		data = (data < 3 ? 0 : 119);
	
	if(key_.direction_=="falling")			//hvis "falling" s� "vend"
	{
		if(MAPDEBUG)
			cout <<"key_.direction_==falling" << endl;
		
		data = 119-data;
	}

	/*** Forskyd j�vnf�r grundtone ***/
	data += 13-noteStringToInt(key_.root_);		
			
	if(key_.scale_=="major" || key_.scale_=="minor")
		quantizeDiatonic(data);		//diatonisk kvantisering 

	data -= 13-noteStringToInt(key_.root_);		//Forskyd tilbage j�vnf�r grundtone
	
	if(MAPDEBUG)
		cout << "Data post quantizeDiatonic: " << data<< endl;
	
	if((signal.param1Old_ != data) || (noteOn[channel_] == 0))
		signal.command_ = NOTEOFF;	
	else
	{
		signal.command_ = NOTEON;
		signal.param1_ = data;	//set key value hvis forrige tone er slukket.	
	}
	
	param1Old_ = data;
	
	

	return 1;
}

bool MappingScheme::mapVelocity(int data, MidiSignal & signal)
{
	if(MAPDEBUG)
		cout << "Inside mapVelocity\n";

	signal.channel_ = channel_;
	
	data = ((data > 127) || (data < 0) ? 65 : data);
	signal.param2_ = data;	//set velocity value

	if((signal.command_== NOTEOFF) && (data > velocity_.lowerThreshold_))		//Hvis Note-Off og data er h�jere end lowerThreshold
	{
		signal.command_ = NOTEON;
		noteOn[channel_] = 1;
	}	
	else if((signal.command_== NOTEON) && (data > velocity_.lowerThreshold_))	//Hvis Note-On og data er h�jere end lowerThreshold
	{
		signal.command_ = AFTERTOUCH;	
	}
	else if(((signal.command_== NOTEON)||(signal.command_== AFTERTOUCH)) && (data < velocity_.lowerThreshold_))	//Hvis Note-On og data er lavere end lowerThreshold
	{
		signal.command_ = NOTEOFF;
		noteOn[channel_] = 0;
	}
	

	return 1;
}

bool MappingScheme::mapCCAbs(int data, MidiSignal & signal)
{
	if(MAPDEBUG)
		cout << "Inside mapCCAbs\n";

	signal.channel_ = channel_;

	data = (data > 127 || data < 0 ? 127 : data);	//Valider data

	int range = CC_.maxVal_- CC_.minVal_;		//check for neccesity of scaling
	if(data > CC_.minVal_ || data < range)
	{
		if(MAPDEBUG)
			cout << "Entering scaling\n";

		data= int((data*range)/127 + CC_.minVal_);	//int casting nessecary
	}
				
	/*** Set MidiSignal ***/
	signal.command_ = CONTROLCHANGE;	//Set command
	signal.param1_ = CC_.cNum_;				//Set CC#
	signal.param2_ = data;					//Set controller value
	
	return 1;
}

bool MappingScheme::mapCCRel(int data, MidiSignal & signal)
{
	if(MAPDEBUG)
		cout << "Inside mapCCRel\n";

	signal.channel_ = channel_;

	data = (data > 127 || data < 0 ? 127 : data);	//Valider data

	/** Select strategy according to input range **/
	int strategy;
	if(data < 26) strategy = -2;
	else if(data < 51) strategy = -1;
	else if(data < 77) strategy = 0;
	else if(data < 102) strategy = 1;
	else strategy = 2; 
	
	if(MAPDEBUG)
		cout << "strategy : " << strategy << endl;

	if(strategy !=0)
	{
		strategy = strategy*CC_.speed_;	//Additional scaling akkording to speed
	}
	
	if(MAPDEBUG)
		cout << "Strategy post scaling: " << strategy << endl;												
	
	/*** Set MidiSignal ***/
	signal.command_ = CONTROLCHANGE;			//Set command
	signal.param1_ = CC_.cNum_;						//Set CC#
	
	if(((signal.param2_ + strategy) <= CC_.maxVal_) && ((signal.param2_ + strategy)>= CC_.minVal_))
		signal.param2_ = signal.param2_ + strategy;	//Set controller value relative to old
	else if((signal.param2_ + strategy) > CC_.maxVal_)
		signal.param2_ = CC_.maxVal_;
	else
		signal.param2_ = CC_.minVal_;

	signal.param2_ = signal.param2_;				//Set old value
	
	return 1;
}

int MappingScheme::noteStringToInt(string note)
{
	if(MAPDEBUG)
		cout << "Inside noteStringToInt\n";

	if(note.compare("c") == 0) return 1;
	else if(note.compare("cis") == 0) return 2;
	else if(note.compare("d") == 0) return 3;
	else if(note.compare("dis") == 0) return 4;
	else if(note.compare("e") == 0) return 5;
	else if(note.compare("f") == 0) return 6;
	else if(note.compare("fis") == 0) return 7;
	else if(note.compare("g") == 0) return 8;
	else if(note.compare("gis") == 0) return 9;
	else if(note.compare("a") == 0) return 10;
	else if(note.compare("ais") == 0) return 11;
	else if(note.compare("b") == 0) return 12;
	else return 1;
}
void MappingScheme::quantizeDiatonic(int &dataIn)
{
	if(MAPDEBUG)
		cout << "inside quantizeDiatonic\n";
	
	int noteStep = dataIn%12;
	
	if(key_.scale_=="major")
	{
		if(MAPDEBUG)
			cout << "inside major quantizer\n";
		/**** Major (dur) kvantisering herunder ****/
		switch (noteStep){
			case 0:						//prim
			case 2:						//sekund
			case 4:						//terts
			case 5:						//kvart
			case 7:						//kvint
			case 9:						//sekst
			case 11:					//septim
				break;					//do nothing
			case 1: dataIn--; break;	//down to scale step 1
			case 3: dataIn++; break;	//up to scale step 3
			case 6: dataIn++; break;	//up to scale step 5
			case 8: dataIn++; break;	//up to scale step 6
			case 10: dataIn++; break;	//up to scale step 7
		}
	}else if(key_.scale_=="minor")
	{
		/**** Minor (mol) kvantisering herunder ****/
		if(MAPDEBUG)
			cout << "inside minor quantizer\n";

		switch(noteStep)
		{
			case 0:							//prim
			case 2:							//sekund
			case 3:							//terts
			case 5:							//kvart
			case 7:							//kvint
			case 8:							//sekst
			case 10:						//septim
				break;						//do nothing
			case 1: dataIn--; break;		//down to scale step 1
			case 4: dataIn--; break;		//down to scale step 3
			case 6: dataIn++; break;		//up to scale step 5
			case 9: dataIn--; break;		//down to scale step 6
			case 11: dataIn--; break;		//down to scale step 7
		}
	}else
		cout << "Invalid scale\n";
}
