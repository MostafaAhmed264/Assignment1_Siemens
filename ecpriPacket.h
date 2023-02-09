#include "rawPacket.h"

typedef struct{
    string messageType; 
    string payloadSize; 
    string protocolVersion; 
    string RTCID; 
    string sequenceID; 
}ecpriPacketInfo; 

class ecpriPacket:rawPacket{
    private:
        ecpriPacketInfo ecpriInfo; 
    public: 
        ecpriPacket(ecpriPacketInfo * ecpriInfo,rawPacketInfo * rawInfo, string value);
        ecpriPacketInfo getEcpriInfo(); 
}; 