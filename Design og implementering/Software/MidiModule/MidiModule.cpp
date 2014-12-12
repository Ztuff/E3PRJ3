#include "MidiModule.hpp"

void* MidiModuleThreadFunction(void* arg)
{
	static_cast<MidiModule*>(arg)->eventDispatcher();
	return NULL;
}

using namespace std;

MidiModule::MidiModule(AlsaAdapter* alsaAdapter) 	//in test
 : alsaAdapter_(alsaAdapter),
   msgQ(50)
   {}

MidiModule::~MidiModule()
{}

MsgQueue* MidiModule::getMsgQueue()
{
	return &msgQ;
}


void MidiModule::start()
{
  int Ct = pthread_create(&threadHandle, NULL,
  	 MidiModuleThreadFunction, this);
  if( Ct != 0)
  {
    BR3K_error(Ct, "Error: Couldn't create MidiModule thread");
  }
}

void MidiModule::join()
{
  int Cj = pthread_join(threadHandle, NULL);
  if( Cj != 0)
  {
    BR3K_error(Cj, "Error: Couldn't join MidiModule thread");
  }
}

void MidiModule::BR3K_error(int errorNum, std::string msg)
{
	std::cout << "An error has occured." << std::endl;
	std::cout << "Error code: " << errorNum << std::endl;
	std::cout << "Msg: " << msg << std::endl;
}




void MidiModule::eventDispatcher()
{
	 Message* msgPtr;
	 unsigned long id;
	 bool active = true;
	 while(active){
	 	msgPtr = msgQ.receive(id);
	 	
	 	switch(id)
	 	{
	 		case DATA_MSG:
	 			handleDataMsg(static_cast<DataMsg*>(msgPtr));
	 			break;
	 		case SHUTDOWN_MSG:
	 			handleShutdownMsg();
	 			active = false;
	 			break;
	 		default:
	 			BR3K_error(-1, "MidiModule eventDispatch received unknown type.\n");
	 			break;
	 	}
	 	//if(msgPtr != NULL) delete msgPtr;
	 }
	 
	 return;
}

void MidiModule::setPreset(list<SensorConfiguration> & sensConfList)
{
	/** Send stop to all MidiSignals **/
	//stopMidiSignals();

	
	/** Initialize new preset **/
	sensorConfList_ = sensConfList;
	midiSignalVector_ = std::vector<MidiSignal>(sensConfList.size());

}

void MidiModule::handleDataMsg(DataMsg* msg)
{
	cout << "entering handleDataMsg" << endl;
	/******* Update vector<MidiSignal> jf modtaget data. *******/
	int data = 0;
	int index = 0;
	for (list<SensorConfiguration>::iterator i = sensorConfList_.begin(); i != sensorConfList_.end(); ++i)	//Iterate through sensor konfigurations
	{
		switch ((*i).getAxis())	//Find correct data in dataArray
		{
			case 'x':
				cout << "setting data = x "<< endl;
				cout << "sensorID is = " << (*i).getSensorID() << endl;
				data = msg->operator[]((*i).getSensorID()).x;
				cout << "Data is: " << data << endl;
				break;
			case 'y':
				data = (*msg)[(*i).getSensorID()].y;
				break;
			case 'z':
				data = (*msg)[(*i).getSensorID()].z;
				break;
			default:
				data = (*msg)[(*i).getSensorID()].x;
				break;
		}
		midiSignalVector_[0].print();
		

		(*i).getMScheme().map(data,midiSignalVector_[index++]);		/* 	Prototype: bool map(int data, MidiSignal & signal);
																alder map i den givne SensKonfigurations MappingScheme
																og giver den datapunkt jf. i SensKonfiguration indstillet sensor
																og vectorplads jf indstillet  i SensKonfiguration indstillet vectorplads */															
	}	
	
	/******* Send opdateret vector af MidiSignaler *******/

	midiSignalVector_[0].print();
	
	cout << "Size of signalVector: " << midiSignalVector_.size() << endl;
	alsaAdapter_->send(midiSignalVector_);		
}

void MidiModule::handleShutdownMsg(){
	cout << "MidiModule shutting down." << endl;
}


	 	
	
