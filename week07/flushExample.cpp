#include <iostream>
#include "unistd.h"

int main()
{   
    std::cout << "Hello world!" << std::endl;
    std::cout << "Hello world again!";
    // std::cout.flush();
    sleep(3); // pauses execution for 3 seconds
    
    return 0;
}