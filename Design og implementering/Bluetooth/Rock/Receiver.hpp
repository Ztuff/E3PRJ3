//#include <pthread.h>    //For thread handling
//#include "MsgQueue.hpp" //For event based programming

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
  
  struct data
  {
    char x;
    char y;
    char z;
  };
  
  data dataArray_[ MAX_SENSORS ];
  
  /*MsgQueue msgQ_( 10 );
  pthread_t btThr_;
  
  struct msgQs
  {
    MsgQueue* contrQ_;
    MsgQueue* midiQ;
  };*/
};