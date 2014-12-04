#include <string>
#include <pthread.h>
#include <vector>
#include <list>
#include <iostream>
#include "DataBank/MidiSignal.h"
#include "DataBank/MappingScheme.h"
#include "DataBank/SensorConfiguration.hpp"
#include "AlsaAdapter/AlsaAdapter.hpp"
#include "../MsgHandler/message.hpp"
#include "DataMsg.hpp"

class MidiModule
{
	public:
		MidiModule(AlsaAdapter* alsaAdapter,
			 		list<SensorConfiguration> sensConfList);
		~MidiModule();
		
		void start();
		void join();
		
		MsgQueue* getMsgQueue();
		
		void eventDispatcher();
		
		enum typeId
		{
			SHUTDOWN_MSG,
			DATA_MSG
		};
			
	private:		
		AlsaAdapter* alsaAdapter_;
		MsgQueue msgQ;
		vector<MidiSignal> midiSignalVector_;
		list<SensorConfiguration> sensorConfList_;
		pthread_t threadHandle;
	
		
		void handleDataMsg(DataMsg* msg);
		void handleShutdownMsg();
		void BR3K_error(int errorNum, std::string msg);
};
