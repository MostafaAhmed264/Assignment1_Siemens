#include <iostream>
#include <fstream> 
#include "ecpriPacket.h"
#include "parsePacket.h"

string getPacketType(string packet)
{
    return packet.substr(TYPE_IDX, TYPE_SIZE); 
}
void writeInfo(rawPacket * packet, std::ofstream * outFile)
{
   (*outFile) << "CRC: " << packet->getRawInfo().crc<< '\n';  
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
    packetParser parser;
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
                p->accept(parser);
                writeInfo(p, &outFile); 
            }
            else 
            {
                rawPacket * p = new rawPacket(packetString);
                p->accept(parser);
                writeInfo(p, &outFile); 
            }
        }
    }   
}