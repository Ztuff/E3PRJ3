#pragma once

#include <string>
#include <vector>
#include "message.hpp"
#include "MsgHandlerDefs.hpp"


class MsgHandler
{
	public:
    MsgHandler( MsgQueue* controllerQueue );
    SensorKonfInfo getSensorKonfInfo();
    void setSensorKonf( string sensorID, string akse, string mScheme, string lydpakke );
	private:		
    MsgQueue handlerQueue_( 5 );
    MsgQueue* controllerQueue_;
};