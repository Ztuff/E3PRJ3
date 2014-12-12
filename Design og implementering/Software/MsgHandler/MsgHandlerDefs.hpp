#include "message.hpp"

enum typeId
{
  GET_SENSOR_KONF_INFO,
  RETURN_SENSOR_KONF_INFO,
  SET_SENSOR_KONF,
  SHUTDOWN_MSG
  
  //put msg types here as they are implemented.
};

// Umiddelbart erstattet af de andre, forskellige structs
/*struct QtMsg : Message
{
  QtMsg(MsgQueue* msgQPtr, int intArg = -1, std::string stringArg = NULL)
    : qtMsgQPtr(msgQPtr), intArg(intArg), stringArg(stringArg)				
  {}
  
  MsgQueue* qtMsgQPtr;
  int intArg;
  std::string stringArg;
};*/

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