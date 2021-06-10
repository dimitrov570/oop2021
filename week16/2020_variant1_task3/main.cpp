#include <iostream>
#include "ProtectedArray.hpp"


int main()
{

    ProtectedArray<int> array;
    array.addElement(5,6);
    array.addElement(4,5);
    array.addElement(3,4);

    std::cout << array.getElement(0, 6) << '\n';
    std::cout << array.getElement(1, 5) << '\n';
    std::cout << array.getElement(2, 4) << '\n';

    ProtectedArray<int> copyArray = array;
    std::cout << copyArray.getElement(0, 6) << '\n';
    std::cout << copyArray.getElement(1, 5) << '\n';
    std::cout << copyArray.getElement(2, 4) << '\n';

    ProtectedArray<int> secondCopy;
    secondCopy = copyArray;
    std::cout << secondCopy.getElement(0, 6) << '\n';
    std::cout << secondCopy.getElement(1, 5) << '\n';
    std::cout << secondCopy.getElement(2, 4) << '\n';


    return 0;
}