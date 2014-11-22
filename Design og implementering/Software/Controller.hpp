#include <pthread.h>
#include "MsgQueue.h"
#include "msghandling.h"  

class Controller
{
	public:
		Controller();
		~Controller();
		
		MsgQueue* getMsgQueue();
		
		void start();
		void join();
		
		struct QtMsg : Message
		{
			QtMsg(MsgQueue* msgQPtr, int intArg = -1, string stringArg = NULL)
			{
				qtMsgQPtr = msgQPtr;
				this.intArg = intArg;
				this.stringArg = stringArg;
			}
			MsgQueue* qtMsgQPtr;
			int intArg;
			string stringArg;
		}
		
		enum typeId
		{
			SHUTDOWN_MSG,
			GET_NEW_SENS_CONF_INFO
			
			//put msg types here as they are implemented.
		}
			
	private:
		void* eventDispatcher(void*);
		
		pthread_t threadHandle;
		
		MsgQueue msgQ;
		
}
