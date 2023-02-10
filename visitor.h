//abstract visitor class
class visitor
{
    public:
    virtual void visitRawPacket(class rawPacket * rp) = 0;
    virtual void visitEcrpiPacket(class ecpriPacket * ep) = 0;

};