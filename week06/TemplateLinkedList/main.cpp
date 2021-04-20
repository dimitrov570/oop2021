#include <iostream>
#include "LinkedList.hpp"

int main()
{
    LinkedList<int> lst;

    lst.push_back(1);
    lst.push_back(4);
    lst.push_front(0);

    lst.insert_at(1, 2);
    lst.insert_at(2,3);

    lst.print();

    std::cout << "List size: " << lst.getSize() << '\n';
    std::cout << "Front: " << lst.peek_front() << "; Back: " << lst.peek_back() << "; At 2nd index: " << lst.peek_at(2) << '\n';

    std::cout << "Removing at 3rd index: " << lst.remove_at(3) << '\n';
    lst.print();
    std::cout << "Popping back: " << lst.pop_back() << '\n';
    lst.print();
    std::cout << "Popping front: " << lst.pop_front() << '\n';
    lst.print();
    std::cout << "Popping front: " << lst.pop_front() << '\n';
    lst.print();
    std::cout << "Popping front: " << lst.pop_front() << '\n';
    lst.print();

    //empty
    std::cout << "List size: " << lst.getSize() << '\n';
    std::cout << "Popping front: " << lst.pop_front() << '\n';
    lst.print();
    std::cout << "Popping back: " << lst.pop_back() << '\n';
    lst.print();
    return 0;
}