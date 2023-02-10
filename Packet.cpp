#include "Packet.h"

Packet::Packet(std::string value)
{
  this->value = value;  
}

std::string Packet::getValue()
{
    return this->value; 
}
