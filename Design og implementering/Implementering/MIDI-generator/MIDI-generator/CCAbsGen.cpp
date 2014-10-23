#include "CCAbsGen.h"

CCAbsGen::CCAbsGen(int minVal, int maxVal , int dataIn): MIDIGen(dataIn)
{
	if(maxVal > minVal)
	{
		minVal_ = (minVal > 127 || minVal < 0 ? 0 : minVal);
		maxVal_ = (maxVal > 127 || maxVal < 0 ? 127 : maxVal);
	}else
	{
		minVal_ = 0;
		maxVal_ = 127;
	}
	cout << "dataIn : " <<dataIn_ << endl;
	cout << "minVal : " << minVal_ << endl;
	cout << "maxVal : " << maxVal_ << endl;
}

void CCAbsGen::sendMIDI(int dataIn)			//dataIn is optional
{
	if(dataIn != -1)
	{
		MIDIGen::setDataIn(dataIn);
	}

	if( dataIn_ != dataInOld_ )								//Gør intet hvis samme værdi igen
	{
		int range = maxVal_- minVal_;					//check for neccesity of scaling
		if(dataIn_ > minVal_ || dataIn_ < range)
		{
			cout << "Entering scaling\n";
			dataIn_= int((dataIn_*range)/127 + minVal_);	//int casting nessecary
		}
		cout << "dataIn post scaling " << dataIn_ << endl;
		cout << "Send ccVal ALSA\n";
		
		dataInOld_ = dataIn_;
	}
}