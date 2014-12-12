#pragma once
#include <queue>
#include <pthread.h>
#include <iostream>

class Message
{
public:
    virtual ~Message() {}
};

class MsgQueue
{
public:
  MsgQueue(unsigned long maxSize) : maxSize_(maxSize)
  {
    pthread_mutex_init(&msgMutex, NULL);
    pthread_cond_init(&msgCond, NULL);
    //	
  }
  
  void send(unsigned long id, Message* msg = NULL)
  {
    pthread_mutex_lock(&msgMutex);
    while ( msgQueue_.size() >= maxSize_ )
    {
      pthread_cond_wait(&msgCond, &msgMutex);	
    }
    
    Package* package = new Package;
    package->id = id;
    package->msg = msg;
    msgQueue_.push(package);
    
    pthread_cond_signal(&msgCond);
    
    pthread_mutex_unlock(&msgMutex);
  }

  Message* receive(unsigned long& id)
  {
    pthread_mutex_lock(&msgMutex);
	
    while ( msgQueue_.empty() )
    {
      pthread_cond_wait(&msgCond, &msgMutex);
    }
    Package* package = msgQueue_.front();
    msgQueue_.pop();
    pthread_cond_signal(&msgCond);
    
    id = package->id;
    Message* msg = package->msg;
    delete package;
    pthread_mutex_unlock(&msgMutex);
    
    return msg;
  }

  ~MsgQueue()
  {
    pthread_mutex_destroy(&msgMutex);
    pthread_cond_destroy(&msgCond);
  }
private:

	typedef struct Package
  {
  		unsigned long id;
  		Message* msg;
	} Package;

	std::queue<Package*> msgQueue_;
	const unsigned long maxSize_;
	pthread_mutex_t msgMutex;
	pthread_cond_t msgCond;
};
