#include <string>
#include <pthread.h>
#include "message.hpp"
#include "DataBank.hpp"
#include "MsgHandlerDefs.hpp"

class Controller
{
	public:
		Controller();
		~Controller();
		
		MsgQueue* getMsgQueue();
		
		void start();
		void join();
		
		void eventDispatcher();
			
	private:		
		pthread_t threadHandle;
		
    DataBank dataBank;
		MsgQueue msgQ( 20 );

		void handleGetSensorKonfInfo( HandlerQueue* msg );
    void handleSetSensorKonf( SensorKonf* msg );
		void handleShutdownMsg();
		void BR3K_error(int errorNum, std::string msg);
};
