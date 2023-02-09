#include "ecpriPacket.h"

#define DSTADDR_IDX (16)
#define DST_SIZE    (12) //12 hexa char represnting 6 bytes of Destination
#define SRCADDR_IDX (28)
#define SRC_SIZE    (12)
#define TYPE_IDX (40)
#define TYPE_SIZE (4)
#define CRC_SIZE (8)

void parseRawInfo(rawPacket * packet)
{
    string value = packet->getValue();
    rawPacketInfo rawInfo; 
    rawInfo.dstAddress = value.substr(DSTADDR_IDX, DST_SIZE); 
    rawInfo.srcAddress = value.substr(SRCADDR_IDX, SRC_SIZE); 
    rawInfo.type = value.substr(TYPE_IDX, TYPE_SIZE); 
    rawInfo.crc = value.substr(value.length()- 9, CRC_SIZE); /*9 is the starting INDX of the CRC from the back*/ 
    packet->setRawInfo(rawInfo); 
}