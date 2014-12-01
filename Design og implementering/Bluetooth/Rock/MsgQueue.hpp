#pragma once
#include "Message.hpp"
#include <iostream>
#include <queue>

class MsgQueue
{
public :
  MsgQueue( unsigned long maxSize );
  void send( unsigned long id , Message * msg = NULL );
  Message* receive( unsigned long & id);
  ~MsgQueue();
private :
  unsigned long maxSize_;
  
  struct Item
  {
    unsigned long id_;
    Message* msg_;
  };
  
  std::queue<Item> queue_;
  
  pthread_mutex_t lock_;
  pthread_cond_t cond_;
};