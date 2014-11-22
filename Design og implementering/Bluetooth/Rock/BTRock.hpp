#include <pthread.h>    //For thread handling
#include <MsgQueue.hpp> //For event based programming

class BTRock
{
public:
  BTRock( /*MsgQueue* contrQ, MsgQueue* midiQ*/ );
  ~BTRock();
  //MsgQueue* getMsgQueue();
  
 private:
  void connect();
  void disconnect();
  void send();
  void receive();
  int uart0_filestream_;
  /*MsgQueue msgQ_( 10 );
  pthread_t btThr_;
  
  struct msgQs
  {
    MsgQueue* contrQ_;
    MsgQueue* midiQ;
  };*/
};