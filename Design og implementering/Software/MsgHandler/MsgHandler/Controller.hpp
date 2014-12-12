#include <string>
#include <pthread.h>
#include "message.hpp"


class Controller
{
	public:
		Controller();
		~Controller();
		
		MsgQueue* getMsgQueue();
		
		void start();
		void join();
		
		void eventDispatcher();
		
		struct QtMsg : Message
		{
			QtMsg(MsgQueue* msgQPtr, int intArg = -1, 
				std::string stringArg = NULL)
			: qtMsgQPtr(msgQPtr),
			  intArg(intArg),
			  stringArg(stringArg)				
			{}
			MsgQueue* qtMsgQPtr;
			int intArg;
			std::string stringArg;
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
