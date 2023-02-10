#include "Visitor.h"
#include <fstream> 
class PacketWriter :public Visitor
{
    public:
    std::ofstream outFile;
    PacketWriter(std::string file); 
    void visitRawPacket(class RawPacket * rp);
    void visitEcrpiPacket(class EcpriPacket * ep);
    ~ PacketWriter();

};