#pragma once

#include <string>
#include <vector>
#include "message.hpp"


class MsgHandler
{
	public:
    MsgHandler( MsgQueue* controllerQueue );
    SensorKonfInfo getSensorKonfInfo();
    void setSensorKonf( string sensorID, string akse, string mScheme, string lydpakke );
	private:		
    MsgQueue handlerQueue_( 5 );
    MsgQueue* controllerQueue_;
    
    struct HandlerQueue: public Message
    {
      HandlerQueue( MsgQueue* handlerQ )
        : handlerQ_( handlerQ )
      {}
      MsgQueue* handlerQ_;
    };
    
    struct SensorKonfInfo: public Message
    {
      vector< string > mSchemes;
      vector< string > lydpakker;
    };
    
    struct SensorKonf: public Message
    {
      SensorKonf( string sensorID, string akse, string mScheme, string lydpakke )
        : sensorID_( sensorID ), akse_( akse ), mScheme_( mScheme ), lydpakke_( lydpakke )
      {}
      
      string sensorID_;
      string akse_;
      string mScheme_;
      string lydpakke_;
    };
};