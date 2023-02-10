#include <iostream>
#include <fstream> 
#include "EcpriPacket.h"
#include "ParsePacket.h"
#include "Writer.h"

string getPacketType(string packet)
{
    return packet.substr(TYPE_IDX, TYPE_SIZE); 
}
/*test drive for the above functions*/
int main()
{
    //creating input stream from which we will read the packets
    std::ifstream inputFile("input_packets"); 
    //instantiating object which includes the parsing logic
    PacketParser parser;
    //creating object which holds logic for  writing to the output file
    PacketWriter writer ("output_packets.txt");
    //string for holding each line in the input file
    string packetString; 
    Packet * p;
    //check if file is opened without error
    if(inputFile.is_open())
    {
        //looping for each line in the input file
        while(inputFile)
        {
            /*
                1- we read packet string 
                2- we check the type of the packet (raw or ecpri)
                3- We parse the packet based on its type
                4- We write the parsed info in the output file
            */
            std::getline (inputFile, packetString); 
            string type = getPacketType(packetString); 
            if (type == "AEFE")
                p = new EcpriPacket(packetString); 
            else 
                p = new RawPacket(packetString);      
            p->accept(parser);
            p->accept(writer);
            delete p;
        }
    }
    else 
    {
        std::cout << " couldn't open file";
    }  
    inputFile.close(); 
}