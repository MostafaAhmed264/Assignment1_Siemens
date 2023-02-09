#include <string>

class packet{ 
    private: 
        std::string value; 
    public: 
        //Constructor using a string that can be read from the file
        packet(std::string value);
        //getter for value
        std::string getValue(); 
}; 