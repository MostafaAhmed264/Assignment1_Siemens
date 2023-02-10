#include "visitor.h"
#define DSTADDR_IDX (16)
#define DST_SIZE    (12) //12 hexa char represnting 6 bytes of Destination
#define SRCADDR_IDX (28)
#define SRC_SIZE    (12)
#define TYPE_IDX (40)
#define TYPE_SIZE (4)
#define CRC_SIZE (8)
#define ECPRI_PROTOCOL_IDX (44)
#define ECPRI_PROTOCOL_SIZE (1) 
#define ECPRI_MESSAGE_TYPE_IDX (46)
#define ECPRI_MESSAGE_TYPE_SIZE (2) 
#define ECPRI_PAYLOAD_SIZE_IDX (48)
#define ECPRI_PAYLOAD_SIZE (4)
#define ECPRI_RTC_ID_IDX (52)
#define ECPRI_RTC_ID_SIZE (4)
#define ECPRI_SEQ_ID_IDX (56)
#define ECPRI_SEQ_ID_SIZE (4)
//packetParser visitor contaning two parsing functions for the two different packets types.
class packetParser : public visitor
{
    void visitRawPacket(rawPacket * rp);
    void visitEcrpiPacket(ecpriPacket * ep);    
};