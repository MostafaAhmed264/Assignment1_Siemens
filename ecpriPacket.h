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
        ecpriPacket(string value);
        ecpriPacketInfo getEcpriInfo(); 
        void setEcpriInfo(ecpriPacketInfo); 
}; 