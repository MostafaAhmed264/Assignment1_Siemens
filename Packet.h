#include <string>

class Packet{ 
    private: 
        std::string value; 
    public: 
        //Constructor using a string that can be read from the file
        Packet(std::string value);
        //getter for value
        std::string getValue(); 
        virtual void accept(class Visitor &v) = 0;
}; 