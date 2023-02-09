#include "packet.h"

packet::packet(std::string value)
{
  this->value = value;  
}

std::string packet::getValue()
{
    return this->value; 
}
