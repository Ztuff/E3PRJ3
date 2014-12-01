#pragma once
#include "MsgQueue.hpp"
#include <pthread.h>

using namespace std;

MsgQueue::MsgQueue( unsigned long maxSize ) : maxSize_( maxSize )
{
  pthread_mutex_init( &lock_, NULL );
  pthread_cond_init( &cond_, NULL );
}

void MsgQueue::send( unsigned long id , Message * msg )
{
  pthread_mutex_lock( &lock_ );
  while( queue_.size() >= maxSize_ )
    pthread_cond_wait( &cond_, &lock_ );
  
  Item item_;
  item_.id_ = id;
  item_.msg_ = msg;
  
  queue_.push( item_ );
  
  pthread_cond_broadcast( &cond_ );
  pthread_mutex_unlock( &lock_ );
}

Message* MsgQueue::receive( unsigned long & id )
{
  pthread_mutex_lock( &lock_ );
  
  while( queue_.empty() )
    pthread_cond_wait( &cond_, &lock_ );
  
  Item item_ = queue_.front();
  
  queue_.pop();
  
  id = item_.id_;
  
  pthread_cond_broadcast( &cond_ );
  pthread_mutex_unlock( &lock_ );
  
  return item_.msg_;
}

MsgQueue::~MsgQueue()
{
  pthread_cond_destroy( &cond_ );
  pthread_mutex_destroy( &lock_ );
}