#include "MidiModule.h"

MidiModule::MidiModule(AlsaAdapter* alsaAdapter)
{
	timeout_in_milliseconds_ = 20;	//50 times per second = 20 ms
	mute_ = 0;	

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

void MidiModule::handleTick(list<SensKonfiguration> myList)
{
	handleQueue();
	
	int data = 0;
	
	for (list<SensKonfiguration>::iterator i = myList.begin(); i != myList.end(); ++i)	//Iterate through sensor konfigurations
	{
		switch ((i*).accis)	//Find correct data in dataArray
		{
			case 'x'
				data = dataArray[(i*).ID].x;
				break;
			case 'y'
				data = dataArray[(i*).ID].y;
				break;
			case 'z'
				data = dataArray[(i*).ID].z;
				break;
			default:
				data = dataArray[(i*).ID].x;
				break;
		}
		
		(i*).MappingScheme.map(data,(i*).MidiIter*);		/* 	Prototype: bool map(int data, MidiSignal & signal);
																alder map i den givne SensKonfigurations MappingScheme
																og giver den datapunkt jf. i SensKonfiguration indstillet sensor
																og vectorplads jf indstillet  i SensKonfiguration indstillet vectorplads */
																
	}	

}

bool MidiModule::sendVector()
{
	//se på timer:
	//når den proc'er så send midiSignalVector_
	//til alsaadapter. 
}




