#include "Car.hpp"

using namespace osapi;

Car::Car(int id, Guard* entryG, Guard* exitG, 
	 SyncPrint* sPrint, int numTimesToShop, int waitTime)
  : 
  id(id),
  msgQ(10),
  sPrint(sPrint),
  numTimesToShop(numTimesToShop),
  waitTime(waitTime)
{
  entryMsgQ = entryG->getMsgQueue();
  exitMsgQ = exitG->getMsgQueue();	
}

MsgQueue* Car::getMsgQueue()
{
  return &msgQ;
}

void Car::run()
{
  //The first entry request is sent as initialization to get
  //things started.
  entryMsgQ->send(Guard::CAR_ENTRY_REQ, 
		  new Guard::CarMessage(&msgQ)); 
  	
  sPrint->carPrintln(id, "Waiting at entry.");
  	
  //event loop
  unsigned long msgId;
  Message* msg;
  active = true;
  // timesShopped < NUM_REPEATS
  while(active){
    msg = msgQ.receive(msgId);
  		
    switch(msgId)
      {
      case ENTRY_GRANTED:
	handleEntryGranted();
	break;
      case EXIT_GRANTED:
	handleExitGranted();
	break;
      default:
	sPrint->carPrintln(id, "Received message of unknown type.");
	break;
      }
  		
    delete msg;
  }
  	
  sPrint->carPrintln(id, "Thread terminating.");
}

void Car::handleEntryGranted()
{
  //Enter parkinglot
  sPrint->carPrintln(id, "Driving into parkinglot.");
  	
  //send message to entryGuard and unlock entry Mutex
  entryMsgQ->send(Guard::CAR_HAS_ENTERED, NULL); 
  // This Message doesn't need a CarMessage object, 
  // because the car does'nt need a response
  	
  //Shopping
  sPrint->carPrintln(id, "Shopping");
  sleep(rand() % waitTime * 1000 + 1);
  	
  //drive to exit
  exitMsgQ->send(Guard::CAR_EXIT_REQ, 
		 new Guard::CarMessage(&msgQ));
  	
  sPrint->carPrintln(id, "Waiting at exit.");
}

void Car::handleExitGranted()
{	
  //Exit parkinglot
  sPrint->carPrintln(id, "Leaving parkinglot.");
  	
  //send message to exitGuard and unlock exit Mutex
  exitMsgQ->send(Guard::CAR_HAS_LEFT, NULL); 
  // This Message doesn't need a CarMessage object, 
  // because the car does'nt need a response
  	
  timesShopped++;
  	
  if(timesShopped >= numTimesToShop)
  {
  	active = false;
  	return;
  }
  	
  //Wait
  
  	
  //drive to entry
  entryMsgQ->send(Guard::CAR_ENTRY_REQ, 
		  new Guard::CarMessage(&msgQ)); 
  	
  sPrint->carPrintln(id, "Waiting at entry.");
}

	

