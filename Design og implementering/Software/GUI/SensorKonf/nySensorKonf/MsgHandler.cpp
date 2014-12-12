#pragma once

#include "MsgHandler.hpp"

using namespace std;

MsgHandler( MsgQueue* controllerQueue )
{
  controllerQueue_ = controllerQueue;
}

SensorKonfInfo getSensorKonfInfo()
{
  HandlerQueue* handlerQ = new HandlerQueue( handlerQueue_ );
  controllerQueue->send( GET_SENSOR_KONF_INFO, &handlerQ );
  unsigned long int id;
  SensorKonfInfo msgPtr = static_cast< SensorKonfInfo >( handlerQueue_->receive( id ) );
  while( id != RETURN_SENSOR_KONF_INFO )
    msgPtr = static_cast< SensorKonfInfo >( handlerQueue_->receive( id ) );
  SensorKonfInfo sensorKonfInfo = *msgPtr;
  delete msgPtr;
  return sensorKonfInfo;
}

void setSensorKonf( string sensorID, string akse, string mScheme, string lydpakke )
{
  SensorKonf* sensorKonf = new SensorKonf( sensorID, akse, mScheme, lydpakke );
  controllerQueue_->send( SET_SENSOR_KONF, sensorKonf );
}
