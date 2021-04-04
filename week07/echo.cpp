#include <iostream>
#include <fstream>
#include "unistd.h"

const int BUFF_SIZE = 10;

void echoBuffered(std::istream& is, std::ostream& os)
{

}

void echoByteByByte(std::istream& is, std::ostream& os)
{
    
}

int main(int argc, char* argv[])
{

    // std::cout << argc << '\n';
    // std::cout << argv[0] << '\n';
    // std::cout << argv[1] << '\n';
    if (argc == 2)
    {
        
    }
    else {
      echoByteByByte(std::cin, std::cout);
    }

    return 0;
}