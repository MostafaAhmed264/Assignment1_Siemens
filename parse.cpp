#include <iostream>
#include <fstream> 
#include "ecpriPacket.h"

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

string getPacketType(string packet)
{
    return packet.substr(TYPE_IDX, TYPE_SIZE); 
}

void parseRawInfo(rawPacket * packet)
{
    string value = packet->getValue();
    rawPacketInfo rawInfo; 
    rawInfo.dstAddress = value.substr(DSTADDR_IDX, DST_SIZE); 
    rawInfo.srcAddress = value.substr(SRCADDR_IDX, SRC_SIZE); 
    rawInfo.type = value.substr(TYPE_IDX, TYPE_SIZE); 
    rawInfo.crc = value.substr(value.length()- 8, CRC_SIZE); /*9 is the starting INDX of the CRC from the back*/ 
    packet->setRawInfo(rawInfo); 
}

void parseEcpriInfo(ecpriPacket * packet)
{
    parseRawInfo((rawPacket *) packet); 
    string value = packet->getValue(); 
    ecpriPacketInfo ecpriInfo; 
    ecpriInfo.messageType = value.substr(ECPRI_MESSAGE_TYPE_IDX, ECPRI_MESSAGE_TYPE_SIZE); 
    ecpriInfo.payloadSize = value.substr(ECPRI_PAYLOAD_SIZE_IDX, ECPRI_PAYLOAD_SIZE); 
    ecpriInfo.protocolVersion = value.substr(ECPRI_PROTOCOL_IDX, ECPRI_PROTOCOL_SIZE); 
    ecpriInfo.RTCID = value.substr(ECPRI_RTC_ID_IDX, ECPRI_RTC_ID_SIZE); 
    ecpriInfo.sequenceID = value.substr(ECPRI_SEQ_ID_IDX, ECPRI_SEQ_ID_SIZE);
    packet->setEcpriInfo(ecpriInfo); 
}

void writeInfo(rawPacket * packet, std::ofstream * outFile)
{
   (*outFile) << "CRC: " << packet->getRawInfo().crc;  
}

void writeInfo(ecpriPacket * packet, std::ofstream * outFile)
{
    (*outFile) << packet->getValue() << '\n'; 
    (*outFile) << "CRC: " << packet->getRawInfo().crc << '\n'; 
    (*outFile) << "Concatenation Indicator: 0" << '\n';
    (*outFile) << "Destenation Address: " << packet->getRawInfo().dstAddress <<'\n';
    (*outFile) << "Source Address: " << packet->getRawInfo().srcAddress <<'\n';
    (*outFile) << "Message Type: " << packet->getEcpriInfo().messageType <<'\n';
    (*outFile) << "Payload Size: " << packet->getEcpriInfo().payloadSize <<'\n';
    (*outFile) << "RTC ID: " << packet->getEcpriInfo().RTCID <<'\n';
    (*outFile) << "Sequence ID: " << packet->getEcpriInfo().sequenceID <<'\n';
    (*outFile) << "Type: " << packet->getRawInfo().type <<'\n';
    (*outFile) << "protocol version: " << packet->getEcpriInfo().protocolVersion <<'\n';
    (*outFile) << "**************************************************************************" << '\n';
}


/*test drive for the above functions*/
int main()
{
    std::ifstream inputFile("input_packets"); 
    std::ofstream outFile("output_packets.txt");
    string packetString; 
    if(inputFile.is_open())
    {
        while(inputFile)
        {
            std::getline (inputFile, packetString); 
            string type = getPacketType(packetString); 
            if (type == "AEFE")
            {
                ecpriPacket * p = new ecpriPacket(packetString);
                parseEcpriInfo(p);
                writeInfo(p, &outFile); 
            }
        }
    }   
}