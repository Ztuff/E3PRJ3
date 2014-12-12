#include "MidiModule.hpp"

MidiModule::MidiModule(AlsaAdapter* alsaAdapter)
{
	timeout_in_milliseconds_ = 20;	//50 times per second = 20 ms
	mute_ = 0;	
	
	alsaAdapter_ = alsaAdapter;

}

MidiModule::~MidiModule()
{
	
}

list<SensorConfiguration>::iterator MidiModule::createSensorConfList()
{
	//oprette list af sensorkonfs

	//returnere iterator over denne liste
}

void MidiModule::startTimer()
{
	init_timer(&my_timer_); 
	my_timer_.expires = jiffies + timeout_in_sec*HZ; 
	my_timer_.function = timer_funct; 
	add_timer(&my_timer_);
}

void MidiModule::timerFunct()
{
	my_timer_.expires = jiffies + timeout_in_milliseconds*HZ;    //Re-schedule the timer 
	add_timer(&my_timer_);                					 	 //Add to timer queue
	
	wqFlag = 1;
	wake_up_interruptible(&wq);
}

void MidiModule::handleDataMsg(DataMsg msg); 
{
	/******* Update vector<MidiSignal> jf modtaget data. *******/
	int data = 0;
	
	for (list<SensConfiguration>::iterator i = sensorConfList_.begin(); i != sensorConfList_.end(); ++i)	//Iterate through sensor konfigurations
	{
		switch ((*i).axis_)	//Find correct data in dataArray
		{
			case 'x'
				data = dataArray[(*i).sensorID_].x;
				break;
			case 'y'
				data = dataArray[(*i).sensorID_].y;
				break;
			case 'z'
				data = dataArray[(*i).sensorID_].z;
				break;
			default:
				data = dataArray[(*i).sensorID_].x;
				break;
		}
		
		(*i).mScheme_.map(data,*((*i).midiIter_));		/* 	Prototype: bool map(int data, MidiSignal & signal);
															alder map i den givne SensKonfigurations MappingScheme
															og giver den datapunkt jf. i SensKonfiguration indstillet sensor
															og vectorplads jf indstillet  i SensKonfiguration indstillet vectorplads */															
	}	
	
	/******* Send opdateret vector af MidiSignaler *******/
	alsaAdapter_->send(const & midiSignalVector_);		

}

bool MidiModule::sendVector()
{
	//se på timer:
	//når den proc'er så send midiSignalVector_
	//til alsaadapter. 
}




