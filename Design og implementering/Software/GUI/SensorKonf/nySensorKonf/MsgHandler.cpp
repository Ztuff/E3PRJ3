#pragma once

#include "MsgHandler.hpp"
#include "Controller.h"

using namespace std;

MsgHandler( MsgQueue* controllerQueue )
{
  controllerQueue_ = controllerQueue;
}

SensorKonfInfo getSensorKonfInfo()
{
  HandlerQueue handlerQ( handlerQueue_ );
  controllerQueue->send( &handlerQ );
  unsigned long int id;
  return static_cast< SensorKonfInfo >( handlerQueue_->receive( id ) );
}

void setSensorKonf( string sensorID, string akse, string mScheme, string lydpakke )
{
  SensorKonf sensorKonf( sensorID, akse, mScheme, lydpakke );
  controllerQueue_->send( SET_SENSOR_KONF, &sensorKonf );
}
