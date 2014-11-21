#include <pthread.h>
#include "MsgQueue.h"

class Controller
{
	public:
		Controller();
		~Controller();
		
		MsgQueue* getMsgQueue();
		
		void start();
		void join();
		
		class qtMsg : public Message
		{
			public:
				MsgQueue* qtMsgQPtr;
				int intArg;
				string stringArg;
		}
		
		enum typeId
		{
			SHUTDOWN_MSG
			
			//put msg types here as they are implemented.
		}
			
	private:
		void* eventDispatcher(void*);
		
		pthread_t threadHandle;
		
}
