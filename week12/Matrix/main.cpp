#include "Matrix.hpp"
#include <iostream>

int main() {
    Matrix<int> test1(3,2);

    Matrix<int> copy = test1;

    test1.setAt(1,1,5);
    test1.setAt(2,1,4);
    test1.setAt(3,1,3);

    test1.setAt(1,2,3);
    test1.setAt(2,2,1);
    test1.setAt(3,2,7);
    
    test1.print();

    test1.transpose();
    test1.print();
    test1.transpose();
    test1.print();
 
    return 0;
}
