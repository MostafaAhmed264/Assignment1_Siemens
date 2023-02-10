#include "Packet.h"
using std::string; 

/*a struct containing the information about the packet*/
typedef struct{
    string srcAddress; 
    string dstAddress; 
    string crc; 
    string type; 
}rawPacketInfo; 

class RawPacket:public Packet{
    private:
        rawPacketInfo rawInfo; 
    public: 
        RawPacket(string value);
        rawPacketInfo getRawInfo(); 
        void setRawInfo(rawPacketInfo); 
        virtual void accept(Visitor &v);
};