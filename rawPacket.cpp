#include "visitor.h"
#include "rawPacket.h" 

rawPacket::rawPacket(string value) : packet(value){}

rawPacketInfo rawPacket::getRawInfo()
{
    return this->rawInfo;
}

void rawPacket::setRawInfo(rawPacketInfo rawInfo)
{
    this->rawInfo = rawInfo; 
}
void rawPacket::accept(visitor &v)
{
    v.visitRawPacket(this);

}