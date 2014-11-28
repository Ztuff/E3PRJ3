#include "Guard.hpp"

using namespace osapi;

Guard::Guard(MsgQueue* entryMsgQ, SyncPrint* sPrint) 
  : entryMsgQ(entryMsgQ), 
    msgQ(5),
    sPrint(sPrint)
			  
{

  entry = !entryMsgQ; //if entryMsgQ == null, entry = true;
}

Guard::~Guard()
{
}

MsgQueue* Guard::getMsgQueue()
{
  return &msgQ;
}

void Guard::run()
{
  unsigned long msgId;
  Message* msg;
  active = true;
  while(active){
    msg = msgQ.receive(msgId);
  		
    switch(msgId){
	handleUnknownType();
      break;
    case CAR_EXIT_REQ:
      if(!entry)
	handleExitReq(static_cast<CarMessage*>(msg));
      else
	handleUnknownType();
      break;
  				
    case CAR_HAS_LEFT:
      if(!entry)
	handleCarHasLeft();
      else
	handleUnknownType();
      break;
  				
    case CAR_ENTRY_REQ:
      if(entry)
	handleEntryReq(static_cast<CarMessage*>(msg));
      else
	handleUnknownType();
      break;
  				
    case CAR_HAS_ENTERED:
      if(entry)
	handleCarHasEntered();
      else
	handleUnknownType();
      break;
  	case SHUTDOWN:
		active = false;
		break;
    default:
      handleUnknownType();
      break;
    }
  		
    delete msg;
  } 	
}

void Guard::handleUnknownType(){
  if(entry) sPrint->print("Entry ");
  else sPrint->print("Exit ");
  sPrint->println("guard received an event of unknown type.");
}

void Guard::handleEntryReq(CarMessage* msg)
{	    
  sPrint->println("Entry Control granted permission for 1 car.");
    
  msg->carMsgQ->send(Car::ENTRY_GRANTED, NULL);
}

void Guard::handleCarHasEntered(){
  //print status
  sPrint->println("A car has entered.");
}

void Guard::handleExitReq(CarMessage* msg){
  sPrint->println("Exit Control granted permission for 1 car.");
  msg->carMsgQ->send(Car::EXIT_GRANTED, NULL);
}

void Guard::handleCarHasLeft(){
  //print status
  sPrint->println("A car has left.");
}

