#include <iostream>

int main()
{
    unsigned int i = 0;
    --i;
    std::cout << i << "\n"; 

    i = UINT32_MAX;
    --i;
    std::cout << i << "\n\n";


    int j = 0;
    --j;
    std::cout << j << "\n";

    j = INT32_MAX;
    ++j;
    std::cout << j << "\n";

}