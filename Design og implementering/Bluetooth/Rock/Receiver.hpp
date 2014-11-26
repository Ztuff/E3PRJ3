//#include <pthread.h>    //For thread handling
//#include "MsgQueue.hpp" //For event based programming

#define RX_BUFFER_SIZE 100

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
  /*MsgQueue msgQ_( 10 );
  pthread_t btThr_;
  
  struct msgQs
  {
    MsgQueue* contrQ_;
    MsgQueue* midiQ;
  };*/
};