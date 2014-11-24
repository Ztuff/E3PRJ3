#ifndef MSGHANDLING_H
#define MSGHANDLING_H
#include "MsgQueue.hpp"
#include <string>



class MsgHandling
{
public:
    MsgHandling(MsgQueue* msgQptr);
    void sendMsg(unsigned long id, int intArg = -1, string stringArg = "");
    Message sendMsgWReply(unsigned long sendId, unsigned long replyId, int intArg, string stringArgl);
};

struct DatabankInfoMsg : Message
{
    DatabankInfoMsg(vector <string> sensorListe, vector <string> mappingschemeListe, vector <string> lydpakkeListe, vector <string> midiparameterList){
        this->sensorListe = sensorListe;
        this->mappingschemeListe = mappingschemeListe;
        this->lydpakkeListe = lydpakkeListe;
        this->midiparameterList = midiparameterList;
    }

    vector <string> sensorListe, mappingschemeListe, lydpakkeListe, midiparameterListe;
};

struct sensorConfInfoMsg : Message
{

};

#endif // MSGHANDLING_H
