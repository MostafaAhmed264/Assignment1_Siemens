#include"parsePacket.h"
#include "ecpriPacket.h"
#include <string>
using std::string;
 //raw ethernet frame pasring function
void packetParser::visitRawPacket(rawPacket * packet)
{
    string value = packet->getValue();
    rawPacketInfo rawInfo; 
    rawInfo.dstAddress = value.substr(DSTADDR_IDX, DST_SIZE); 
    rawInfo.srcAddress = value.substr(SRCADDR_IDX, SRC_SIZE); 
    rawInfo.type = value.substr(TYPE_IDX, TYPE_SIZE); 
    rawInfo.crc = value.substr(value.length()- 8, CRC_SIZE); /*9 is the starting INDX of the CRC from the back*/ 
    packet->setRawInfo(rawInfo); 
   


}
//ecrpi frame parsing function
void packetParser::visitEcrpiPacket(ecpriPacket * packet)
{ 
    visitRawPacket((rawPacket *) packet); 
    string value = packet->getValue(); 
    ecpriPacketInfo ecpriInfo; 
    ecpriInfo.messageType = value.substr(ECPRI_MESSAGE_TYPE_IDX, ECPRI_MESSAGE_TYPE_SIZE); 
    ecpriInfo.payloadSize = value.substr(ECPRI_PAYLOAD_SIZE_IDX, ECPRI_PAYLOAD_SIZE); 
    ecpriInfo.protocolVersion = value.substr(ECPRI_PROTOCOL_IDX, ECPRI_PROTOCOL_SIZE); 
    ecpriInfo.RTCID = value.substr(ECPRI_RTC_ID_IDX, ECPRI_RTC_ID_SIZE); 
    ecpriInfo.sequenceID = value.substr(ECPRI_SEQ_ID_IDX, ECPRI_SEQ_ID_SIZE);
    packet->setEcpriInfo(ecpriInfo); 

}