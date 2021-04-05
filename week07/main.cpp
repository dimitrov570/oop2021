#include <fstream>
#include <iostream>

int main()
{

    std::ofstream fo("example.bin", std::ios::in | std::ios::out | std::ios::trunc);


        fo.write("a\r\n",sizeof("a\n\r"));

    int i;
    for(i = 1; i < 10; ++i)
    {
     //   fo << i << '\n'; // try without '\n'
        //fo.write((const char*)&i, sizeof(i));
    }

    fo.close();
    int r;

    std::ifstream fi("example.bin");
    
    for (int i = 0; i < 10; ++i)
    {
        fi >> r;
        std::cout << "read: " << r << '\n';
    }

    // fi.seekg(3*sizeof(int), std::ios::beg);
    // fi.read((char *)&r,sizeof(int));


    return 0;
}