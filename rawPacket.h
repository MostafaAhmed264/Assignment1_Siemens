#include "packet.h"
using std::string; 

/*a struct containing the information about the packet*/
typedef struct{
    string srcAddress; 
    string dstAddress; 
    string crc; 
    string type; 
}rawPacketInfo; 

class rawPacket:packet{
    private:
        rawPacketInfo rawInfo; 
    public: 
        rawPacket(rawPacketInfo * info, string value);
        rawPacketInfo getInfo(); 
};