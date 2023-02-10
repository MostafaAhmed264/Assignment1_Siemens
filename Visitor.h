//abstract visitor class
#ifndef VISITOR_H
#define VISITOR_H

class Visitor
{
    public:
    virtual void visitRawPacket(class RawPacket * rp) = 0;
    virtual void visitEcrpiPacket(class EcpriPacket * ep) = 0;
};

#endif