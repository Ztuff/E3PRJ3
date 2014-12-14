#pragma once

#include "MsgHandler.hpp"

using namespace std;

MsgHandler::MsgHandler( MsgQueue* controllerQueue )
{
  controllerQueue_ = controllerQueue;
}

SensorKonfInfo MsgHandler::getSensorKonfInfo()
{
  HandlerQueue* handlerQ = new HandlerQueue(&handlerQueue_);
  controllerQueue_->send( GET_SENSOR_KONF_INFO, handlerQ );
  unsigned long int id;
  SensorKonfInfo* msgPtr = static_cast< SensorKonfInfo* >( handlerQueue_.receive( id ) );
  while( id != RETURN_SENSOR_KONF_INFO )
    msgPtr = static_cast< SensorKonfInfo* >( handlerQueue_.receive( id ) );
  SensorKonfInfo sensorKonfInfo = *msgPtr;
  delete msgPtr;
  return sensorKonfInfo;
}

void MsgHandler::setSensorKonf( string name, string sensorID, string akse, string mScheme, string lydpakke )
{
  SensorKonf* sensorKonf = new SensorKonf( name, sensorID, akse, mScheme, lydpakke );
  controllerQueue_->send( SET_SENSOR_KONF, sensorKonf );
}

void MsgHandler::deleteSensorKonf(string name, string sensorID, string akse, string mScheme, string lydpakke)
{
    SensorKonf* sensorKonf = new SensorKonf(name, sensorID, akse, mScheme, lydpakke);
    controllerQueue_->send (DEL_SENSOR_KONF, sensorKonf);
}
