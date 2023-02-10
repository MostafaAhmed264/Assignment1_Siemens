#include "visitor.h"
#include "ecpriPacket.h"

ecpriPacket::ecpriPacket(string value) : rawPacket(value){}

ecpriPacketInfo ecpriPacket::getEcpriInfo()
{
    return this->ecpriInfo; 
}

void ecpriPacket::setEcpriInfo(ecpriPacketInfo ecpriInfo)
{
    this->ecpriInfo = ecpriInfo; 
}
void ecpriPacket::accept(visitor &v)
{
    v.visitEcrpiPacket(this);
}