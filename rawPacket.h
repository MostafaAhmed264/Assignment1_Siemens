#include "packet.h"
using std::string; 

/*a struct containing the information about the packet*/
typedef struct{
    string srcAddress; 
    string dstAddress; 
    string crc; 
    string type; 
}rawPacketInfo; 

class rawPacket:public packet{
    private:
        rawPacketInfo rawInfo; 
    public: 
        rawPacket(string value);
        rawPacketInfo getRawInfo(); 
        void setRawInfo(rawPacketInfo); 
        virtual void accept(visitor &v);
};