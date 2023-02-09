#include "ecpriPacket.h"

ecpriPacket::ecpriPacket(ecpriPacketInfo * ecpriInfo,rawPacketInfo * rawInfo, string value) : rawPacket(rawInfo, value)
{
    this->ecpriInfo.messageType = ecpriInfo->messageType; 
    this->ecpriInfo.payloadSize = ecpriInfo->payloadSize; 
    this->ecpriInfo.protocolVersion = ecpriInfo->protocolVersion; 
    this->ecpriInfo.RTCID = ecpriInfo->RTCID; 
    this->ecpriInfo.sequenceID = ecpriInfo->sequenceID; 
}

ecpriPacketInfo ecpriPacket::getEcpriInfo()
{
    return this->ecpriInfo; 
}
