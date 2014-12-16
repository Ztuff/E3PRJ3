#include <string>
#include <pthread.h>
#include "message.hpp"
#include "DataBank.hpp"

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
        MsgQueue msgQ;

        void handleGetSensorKonfInfo( HandlerQueue* msg );
        void handleGetSensorKonf( SensorKonf* msg );
        void handleSetSensorKonf( SensorKonf* msg );
        void handleDelSensorKonf( SensorKonf* msg );
		void handleShutdownMsg();
		void BR3K_error(int errorNum, std::string msg);
};
