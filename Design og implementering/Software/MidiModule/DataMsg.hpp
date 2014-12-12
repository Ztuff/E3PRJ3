#ifndef DATA_MSG_HPP
#define DATA_MSG_HPP

#include "../MsgHandler/message.hpp"
#include <iostream>
#define MAX_SENSORS 4

struct DataMsg: public Message
{
	public:
	
		struct Data
		{
		    char x;
		    char y;
		    char z;
		};
  
		DataMsg()
		{
			reset();
		}
		
		~DataMsg()
		{
			
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
		        << ", z value: " << ( int )( dataArray_[ i ].z ) 
		        << std::endl;
		    }
		  }
		  
		  void pack( unsigned char* rx_buffer )
		  {
		    dataArray_[ rx_buffer[ 1 ] - 1 ].x 
		    	= rx_buffer[ 2 ] - 1;
		    dataArray_[ rx_buffer[ 1 ] - 1 ].y 
		    	= rx_buffer[ 3 ] - 1;
		    dataArray_[ rx_buffer[ 1 ] - 1 ].z 
		    	= rx_buffer[ 4 ] - 1;
		  }
		  
		  Data& operator[](int i)
		  {
		  	return dataArray_[i];
		  }
		  
		  Data dataArray_[MAX_SENSORS];
		  private:
		  
};

#endif
