#include "Visitor.h"
#include "RawPacket.h" 

RawPacket::RawPacket(string value) : Packet(value){}

rawPacketInfo RawPacket::getRawInfo()
{
    return this->rawInfo;
}

void RawPacket::setRawInfo(rawPacketInfo rawInfo)
{
    this->rawInfo = rawInfo; 
}
void RawPacket::accept(Visitor &v)
{
    v.visitRawPacket(this);

}