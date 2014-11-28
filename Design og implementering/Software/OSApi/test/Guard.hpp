#ifndef GUARD_HPP
#define GUARD_HPP

#include <osapi/ThreadFunctor.hpp>
#include <osapi/MsgQueue.hpp>
#include "SyncPrint.hpp"
#include "Car.hpp"


class Car;

class Guard : public osapi::ThreadFunctor
{
public:
  Guard(osapi::MsgQueue* entryMsgQ, SyncPrint* sPrint);
  ~Guard();
  osapi::MsgQueue* getMsgQueue();
  virtual void run();
		
  class CarMessage : public osapi::Message
  {
  public:
    osapi::MsgQueue* carMsgQ;
    CarMessage(osapi::MsgQueue* msgQ) : carMsgQ(msgQ){};
  };

  enum TypeId{
    CAR_ENTRY_REQ,
    CAR_HAS_ENTERED,
    CAR_EXIT_REQ,
    CAR_HAS_LEFT,
    SHUTDOWN
  };
		
private:
  void handleUnknownType();
  void handleEntryReq(CarMessage* msg);
  void handleCarHasEntered();
  void handleExitReq(CarMessage* msg);
  void handleCarHasLeft();

  osapi::MsgQueue* entryMsgQ;
  osapi::MsgQueue msgQ;
  bool entry;
  bool active;
  SyncPrint* sPrint;
  int carsInParkingLot;
};

#endif
