#include "Controller.hpp"

using namespace std;

Controller::Controller()
: msgQ(40)
{
}

MsgQueue* Controller::getMsgQueue()
{
  return &msgQ;
}

void* threadFunction(void* arg)
{
  static_cast<Controller*>(arg)->eventDispatcher();
  return NULL;
}

void Controller::start()
{
  int Ct = pthread_create(&threadHandle, NULL,
     threadFunction, this);
  if( Ct != 0)
  {
    BR3K_error(Ct, "Error: Couldn't create controller thread");
  }
}

void Controller::join()
{
  int Cj = pthread_join(threadHandle, NULL);
  if( Cj != 0)
  {
    BR3K_error(Cj, "Error: Couldn't join controller thread");
  }
}

void Controller::BR3K_error(int errorNum, std::string msg)
{
  std::cout << "An error has occured." << std::endl;
  std::cout << "Error code: " << errorNum << std::endl;
  std::cout << "Msg: " << msg << std::endl;
}

void Controller::eventDispatcher()
{
  Message* msgPtr;
  unsigned long id;
  bool active = true;
  while( active )
  {
    msgPtr = msgQ.receive(id);
    switch(id)
    {
    case GET_SENSOR_KONF_INFO:
      handleGetSensorKonfInfo( static_cast< HandlerQueue* >( msgPtr ) );
      break;
    case SET_SENSOR_KONF;
      handleSetSensorKonf( static_cast< SensorKonf* >( msgPtr ) );
    case SHUTDOWN_MSG:
      handleShutdownMsg();
      active = false;
      break;
    default:
      BR3K_error(-1, "Controller eventDispatch received unknown type.\n");
      break;
    }
    delete msgPtr;
  }
}

void Controller::handleGetSensorKonfInfo( HandlerQueue* msg )
{
  SensorKonfInfo* msgPtr = new SensorKonfinfo();
  msgPtr->mSchemes = dataBank.getMappingSchemes();
  msgPtr->lydpakker = dataBank.getSoundPacks();
  msg->handlerQ_.send( RETURN_SENSOR_KONF_INFO, msgPtr );
}

void Controller::handleSetSensorKonf( SensorKonf* msg )
{
  dataBank.setSensorKonf( msg->sensorID_, msg->akse_, msg->mScheme_, msg->lydpakke_ );
}

void Controller::handleShutdownMsg()
{
  cout << "shutdown" << endl;
}