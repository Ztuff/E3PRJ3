#include "CCRelGen.h"

CCRelGen::CCRelGen(string speed , int dataIn): MIDIGen(dataIn)
{
	if((speed == "slow") || (speed == "medium") || (speed == "fast"))	//validate speed strategy
		speed_ = speed;
	else
		speed_ = "medium";

	if(speed_.compare("slow") == 0) speedScaling_ = 1;					//initialize speedScaling
	else if(speed_.compare("medium") == 0) speedScaling_ = 2;
	else if(speed_.compare("fast") == 0) speedScaling_ = 3;

	cout << "dataIn : " <<dataIn_ << endl;
	cout << "speed : " << speed_ << endl;
	cout << "speedScaling : " << speedScaling_ << endl;
}

void CCRelGen::sendMIDI(int dataIn)			//dataIn is optional
{
	if(dataIn != -1)
	{
		MIDIGen::setDataIn(dataIn);
	}

	if( dataIn_ != dataInOld_ )								//Gør intet hvis samme værdi igen
	{
		
		/** select strategy according to input range **/
		int strategy;
		if(dataIn_ < 26) strategy = -2;
		else if(dataIn_ < 51) strategy = -1;
		else if(dataIn_ < 77) strategy = 0;
		else if(dataIn_ < 102) strategy = 1;
		else strategy = 2; 

		cout << "strategy : " << strategy << endl;
		if(strategy !=0)
		{
			strategy = strategy*speedScaling_;
		}

		cout << "strategy post scaling: " << strategy << endl;												
		cout << "Send MIDI to ALSA\n";						// send besked med Strategy til ALSA - tag højde for fortegn
		
		dataInOld_ = dataIn_;
	}
}