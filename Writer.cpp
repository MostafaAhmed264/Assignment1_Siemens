#include "Writer.h"
#include "EcpriPacket.h"
#include <fstream>


PacketWriter::PacketWriter(std::string file)
{
    this->outFile.open(file);
}


void PacketWriter::visitRawPacket(RawPacket * packet)
{
    (this->outFile) << packet->getValue() << '\n'; 
    (this->outFile) << "CRC: " << packet->getRawInfo().crc << '\n'; 
    (this->outFile) << "Destenation Address: " << packet->getRawInfo().dstAddress <<'\n';
    (this->outFile) << "Source Address: " << packet->getRawInfo().srcAddress <<'\n';
    (this->outFile) << "Type: " << packet->getRawInfo().type <<'\n';
    (this->outFile) << "**************************************************************************" << '\n';
}
void PacketWriter::visitEcrpiPacket(EcpriPacket* packet)
{
    (this->outFile) << packet->getValue() << '\n'; 
    (this->outFile) << "CRC: " << packet->getRawInfo().crc << '\n'; 
    (this->outFile) << "Concatenation Indicator: " << packet->getEcpriInfo().CI<<'\n';
    (this->outFile) << "Destenation Address: " << packet->getRawInfo().dstAddress <<'\n';
    (this->outFile) << "Source Address: " << packet->getRawInfo().srcAddress <<'\n';
    (this->outFile) << "Message Type: " << packet->getEcpriInfo().messageType <<'\n';
    (this->outFile) << "Payload Size: " << packet->getEcpriInfo().payloadSize <<'\n';
    (this->outFile) << "RTC ID: " << packet->getEcpriInfo().RTCID <<'\n';
    (this->outFile) << "Sequence ID: " << packet->getEcpriInfo().sequenceID <<'\n';
    (this->outFile) << "Type: " << packet->getRawInfo().type <<'\n';
    (this->outFile) << "protocol version: " << packet->getEcpriInfo().protocolVersion <<'\n';
    (this->outFile) << "**************************************************************************" << '\n';
}
 PacketWriter::~ PacketWriter()
 {
    outFile.close();    
 }