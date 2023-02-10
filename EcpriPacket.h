#include "RawPacket.h"
//A struct containing additonal parameters of the ecpri packet
typedef struct{
    string messageType; 
    string payloadSize; 
    string protocolVersion; 
    string RTCID; 
    string sequenceID; 
    string CI;
}ecpriPacketInfo; 

class EcpriPacket:public RawPacket{
    private:
        ecpriPacketInfo ecpriInfo; 
    public: 
        EcpriPacket(string value);
        ecpriPacketInfo getEcpriInfo(); 
        void setEcpriInfo(ecpriPacketInfo); 
        void accept(Visitor &v);
        ~ EcpriPacket();
}; 