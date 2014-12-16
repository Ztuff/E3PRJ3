#pragma once

#include <string>
#include <vector>
#include "message.hpp"


class MsgHandler
{
public:
    MsgHandler( MsgQueue* controllerQueue );
    SensorKonfInfo getSensorKonfInfo();
    void deleteSensorKonf(std::string name, std::string sensorID, std::string akse, std::string mScheme, std::string lydpakke);
    void setSensorKonf( std::string name, std::string sensorID, std::string akse, std::string mScheme, std::string lydpakke );
private:
    MsgQueue handlerQueue_;
    MsgQueue* controllerQueue_;
};
