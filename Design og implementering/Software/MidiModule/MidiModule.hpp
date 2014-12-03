#include <string>
#include <pthread.h>
#include "message.hpp"

class MidiMapper
{
	public:
		MidiMapper();
		~MidiMapper();
		
		MsgQueue* getMsgQueue();
		
		void start();
		void join();
		
		void eventDispatcher();
		
		struct DataMsg : Message
		{
			//Skriv det her Stuff:)
		};
		
		enum typeId
		{
			SHUTDOWN_MSG,
			GET_NEW_SENS_CONF_INFO
			
			//put msg types here as they are implemented.
		};
			
	private:		
		pthread_t threadHandle;
		
		MsgQueue msgQ;

		void handleGetNewSensConfInfo(QtMsg* msg);
		void handleShutdownMsg();
		void BR3K_error(int errorNum, std::string msg);
};
