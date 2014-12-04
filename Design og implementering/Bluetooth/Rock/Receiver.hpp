//#include <pthread.h>    //For thread handling
//#include "MsgQueue.hpp" //For event based programming
#include <iostream>
#include "DataMsg.hpp"

#define MAX_RECEIVED_BYTES 66
#define MAX_SENSORS 16


class Receiver
{
public:
  Receiver( /*MsgQueue* contrQ, MsgQueue* midiQ*/ );
  ~Receiver();
//void send();
  void receive();
//MsgQueue* getMsgQueue();
  
private:
  void connect();
  void disconnect();
  int uart0_filestream_;
  unsigned char lastID_;
  
  
  AllData allData;
  
  
  
  /*MsgQueue msgQ_( 10 );
  pthread_t btThr_;
  
  struct msgQs
  {
    MsgQueue* contrQ_;
    MsgQueue* midiQ;
  };*/
};
