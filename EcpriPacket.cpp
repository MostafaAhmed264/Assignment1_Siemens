#include "Visitor.h"
#include "EcpriPacket.h"

EcpriPacket::EcpriPacket(string value) : RawPacket(value){}

ecpriPacketInfo EcpriPacket::getEcpriInfo()
{
    return this->ecpriInfo; 
}

void EcpriPacket::setEcpriInfo(ecpriPacketInfo ecpriInfo)
{
    this->ecpriInfo = ecpriInfo; 
}
void EcpriPacket::accept(Visitor &v)
{
    v.visitEcrpiPacket(this);
}
