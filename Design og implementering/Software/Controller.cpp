#include "Controller.hpp"

Controller::Controller()
{
	msgQ = MsgQueue();
{
	
}

MsgQueue* Controller::getMsgQueue()
{
	return &MsgQueue;
}

void Controller::start()
{
  int Ct = pthread_create(&threadHandle, NULL,Controller::eventDispatcher, NULL)
  if( Ct != 0)
  {
    BR3K_error(Ct, "Error: Couldn't create controller thread");
  }
}

void Controller::join()
{
  int Cj = pthread_join(&threadHandle, NULL);
  if( Cj != 0)
  {
    BR3K_error(Cj, "Error: Couldn't join controller thread");
  }
}

void* Controller::eventDispatcher(void*)
{
	 Message msg;
	 unsigned long id;
	 bool active = true;
	 while(active){
	 	id = msgQ.receive(&msg);
	 	
	 	switch(id)
	 	{
	 		case GET_NEW_SENS_CONF_INFO:
	 			handleGetNewSensConfInfo(static_cast<QtMsg>(msg));
	 			break;
	 		case SHUTDOWN_MSG:
	 			handleShutdownMsg();
	 			break;
	 		default:
	 			br3kError("Controller eventDispatch received unknown type.\n", -1);
	 			break;
	 	}
	 	delete msg;
	 }
	 
	 return;
}
	 			
	 		
	 		
	 	
	
