#include "contNoteGen.h"

contNoteGen::contNoteGen(string root, string scale, string direction, int dataIn)
{
	if(root.compare("c") == 0) root_ = root;			//Validering af root
	else if(root.compare("cis") == 0) root_ = root;
	else if(root.compare("d") == 0) root_ = root;
	else if(root.compare("dis") == 0) root_ = root;
	else if(root.compare("e") == 0) root_ = root;
	else if(root.compare("f") == 0) root_ = root;
	else if(root.compare("fis") == 0) root_ = root;
	else if(root.compare("g") == 0) root_ = root;
	else if(root.compare("gis") == 0) root_ = root;
	else if(root.compare("a") == 0) root_ = root;
	else if(root.compare("ais") == 0) root_ = root;
	else if(root.compare("b") == 0) root_ = root;
	else root_ = "c";

	rootInt_= MIDIGen::noteStringToInt(root);				//værdi fra 1 til 12
	cout << "root : " << root_ << ", rootInt = " << rootInt_ << endl;		//for testing

	if((scale.compare("cromatic") == 0) || (scale.compare("major") == 0) || (scale.compare("minor") == 0))	//strategies: "cromatic", "major", "minor"			
		scale_= scale;
	else 
		scale_ = "chromatic";
	cout << "scale : " <<scale_ << "\n";					//for testing
	
	if((direction=="rising") || (direction=="falling"))		//strategies: "rising", "falling"			
		direction_= direction;
	else 
		direction_ = "rising";
	cout << "direction : " <<direction_ << "\n";			//for testing
	
	cout << "dataIn pre setDataIn: " <<dataIn << "\n";		//for testing
		
	setDataIn(dataIn);

	cout << "dataIn post setDataIn: " <<dataIn_ << "\n";	//for testing
}

void contNoteGen::setDataIn(int dataIn)
{
	if(2 < dataIn && dataIn < 122)							//omkonvertering til værdi mellem 0-119. dataIn værdier fra 3-122 benyttes
		dataIn-= 3; 		
	else
		dataIn = (dataIn < 3 ? 0 : 119);
	
	if(direction_=="falling")								//hvis "falling" så "vend"
	{
		cout <<"indside falling " << endl;
		dataIn = 119-dataIn;
	}
	
	dataIn_ = dataIn;
}

void contNoteGen::sendMIDI(int dataIn)
{
	if(dataIn != -1)
		setDataIn(dataIn);

	if( dataIn_ != dataInOld_ )								//Gør intet hvis samme værdi igen
	{
		
		dataIn_ += 13-noteStringToInt(root_);				//Forskyd jævnfør grundtone
			
		if((scale_.compare("major") == 0) || (scale_.compare("minor") == 0))
			quantizeDiatonic(dataIn_);						//diatonisk kvantisering 

		
		dataIn_ -= 13-noteStringToInt(root_);				//Forskyd tilbage jævnfør grundtone
		
		cout << "dataIn post quantizeDiatonic " << dataIn_<< endl;	//For testing	
		cout << "Stop MIDI note ALSA\n";					//For testing
		cout << "Play MIDI note ALSA\n";					//For testing

		dataInOld_ = dataIn_;
	}
}

void contNoteGen::printStrategies()
{

}


void contNoteGen::quantizeDiatonic(int dataIn)
{
	cout << "inside quantizeDiatonic\n";
	int noteStep = dataIn%12;
	
	if(scale_.compare("major")==0)
	{
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
			case 1: dataIn_--; break;	//down to scale step 1
			case 3: dataIn_++; break;	//up to scale step 3
			case 6: dataIn_++; break;	//up to scale step 5
			case 8: dataIn_++; break;	//up to scale step 6
			case 10: dataIn_++; break;	//up to scale step 7
		}
	}else
	{
		/**** Minor (mol) kvantisering herunder ****/
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
			case 1: dataIn_--; break;		//down to scale step 1
			case 4: dataIn_--; break;		//down to scale step 3
			case 6: dataIn_++; break;		//up to scale step 5
			case 9: dataIn_--; break;		//down to scale step 6
			case 11: dataIn_--; break;		//down to scale step 7
		}
	}
}
