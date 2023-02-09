#include "rawPacket.h" 

rawPacket::rawPacket(rawPacketInfo * info, string value) : packet(value)
{
    this->rawInfo.srcAddress = info->srcAddress; 
    this->rawInfo.dstAddress = info->dstAddress; 
    this->rawInfo.crc = info->crc; 
    this->rawInfo.type = info->type; 
}

rawPacketInfo rawPacket::getInfo()
{
    return this->rawInfo;
}