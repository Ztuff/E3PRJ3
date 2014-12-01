//#include <pthread.h>    //For thread handling
//#include "MsgQueue.hpp" //For event based programming
#include <iostream>

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
  
  struct Data
  {
    char x;
    char y;
    char z;
  };
  
  struct AllData// : public Message
  {
    AllData()
    {
      reset();
    }
    
    void reset()
    {
      for( int i = 0; i < MAX_SENSORS; i++ )
      {
        dataArray_[ i ].x = 0;
        dataArray_[ i ].y = 0;
        dataArray_[ i ].z = 0;
      }
    }
    
    void print()
    {
      for( int i = 0; i < MAX_SENSORS; i++ )
      {
        std::cout << std::endl << "ID: " << i << std::endl
          << "x value: " << ( int )( dataArray_[ i ].x )
          << ", y value: " << ( int )( dataArray_[ i ].y )
          << ", z value: " << ( int )( dataArray_[ i ].z ) << std::endl;
      }
    }
    
    void pack( unsigned char* rx_buffer )
    {
      dataArray_[ rx_buffer[ 1 ] - 1 ].x = rx_buffer[ 2 ] - 1;
      dataArray_[ rx_buffer[ 1 ] - 1 ].y = rx_buffer[ 3 ] - 1;
      dataArray_[ rx_buffer[ 1 ] - 1 ].z = rx_buffer[ 4 ] - 1;
    }
    
    Data dataArray_[ MAX_SENSORS ];
  };
  
  AllData allData;
  
  
  
  /*MsgQueue msgQ_( 10 );
  pthread_t btThr_;
  
  struct msgQs
  {
    MsgQueue* contrQ_;
    MsgQueue* midiQ;
  };*/
};