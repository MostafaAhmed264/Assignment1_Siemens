#include "rawPacket.h"

typedef struct{
    string messageType; 
    string payloadSize; 
    string protocolVersion; 
    string RTCID; 
    string sequenceID; 
}ecpriPacketInfo; 

class ecpriPacket:public rawPacket{
    private:
        ecpriPacketInfo ecpriInfo; 
    public: 
        ecpriPacket(string value);
        ecpriPacketInfo getEcpriInfo(); 
        void setEcpriInfo(ecpriPacketInfo); 
        void accept(visitor &v);
}; 