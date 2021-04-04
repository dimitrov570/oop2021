#include <iostream>

const int BUFF_SIZE = 10;

void catBuffered(std::istream& is, std::ostream& os)
{

}

void catByteByByte(std::istream& is, std::ostream& os)
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
      catByteByByte(std::cin, std::cout);
    }


    return 0;
}