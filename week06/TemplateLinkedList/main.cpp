#include <iostream>
#include "LinkedList.hpp"

int main()
{
    LinkedList<int> lst;

    lst.push_back(4);
    lst.push_front(3);
    lst.push_back(55);
    lst.push_front(-2);

    lst.print();

    return 0;
}