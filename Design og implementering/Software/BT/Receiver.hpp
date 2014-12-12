#ifndef RECEIVER_HPP
#define RECEIVER_HPP

//#include <pthread.h>    //For thread handling
//#include "MsgQueue.hpp" //For event based programming
#include <iostream>
#include <unistd.h>     //Used for UART
#include <fcntl.h>      //Used for UART
#include <termios.h>    //Used for UART
#include "../MidiModule/DataMsg.hpp"

#define MAX_RECEIVED_BYTES 66

class Receiver
{
public:
  Receiver( /*MsgQueue* contrQ,*/ MsgQueue* midiQ );
  ~Receiver();
//void send();
  void receive();
  void start( unsigned long loops );
//MsgQueue* getMsgQueue();
  
private:
  void connect();
  void disconnect();
  int uart0_filestream_;
  unsigned char lastID_;
  
  MsgQueue* midiQ_;
  
  /*MsgQueue msgQ_( 10 );
  pthread_t btThr_;
  
  struct msgQs
  {
    MsgQueue* contrQ_;
    MsgQueue* midiQ;
  };*/
};

#endif
