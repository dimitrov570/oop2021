#include <iostream>

int main()
{
    int x;

    // Пробвайте с въвеждане на число, буква и EOF(linux: ctrl + D; windows: ctrl + Z).
    std::cin >> x;
    
    std::cout << "good(): " << std::cin.good() << '\n';
    std::cout << "bad(): " << std::cin.bad() << '\n';
    std::cout << "fail(): " << std::cin.fail() << '\n';
    std::cout << "eof(): " << std::cin.eof() << '\n';
    std::cout << "rdstate(): " << std::cin.rdstate() << '\n';
    
    std::cin.clear();
    
    std::cout << "After clear: \n";

    std::cout << "good(): " << std::cin.good() << '\n';
    std::cout << "bad(): " << std::cin.bad() << '\n';
    std::cout << "fail(): " << std::cin.fail() << '\n';
    std::cout << "eof(): " << std::cin.eof() << '\n';
    std::cout << "rdstate(): " << std::cin.rdstate() << '\n';

    return 0;
}