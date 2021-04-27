#include <iostream>
#include <fstream>

class X 
{
    int* varX;

public:

    X(int _varX = 0) 
    {
        varX = new int(_varX);
    }

    virtual void print()
    {
        std::cout << "class X: varX - " << *varX;
    }

    void foo()
    {
        std::cout <<"foo()\n";
        this->print();
    }

    virtual ~X()
    {
        delete varX;
    }
};

class Y: public X
{
    int* varY;

public:

    Y(int _varX, int _varY) : X(_varX) 
    {
        varY = new int(_varY);
    }

    void print() override
    {
        X::print();
        std::cout << "\n";
        std::cout << "class Y: varY - " << *varY;
    }

    ~Y()
    {
        delete varY;
    }
};

void testWithPointers()
{
    X* ptrOfTypeX = new Y(1,2); // сочи към обект от тип Y
    ptrOfTypeX->print(); // ако print() е виртуален ще се извика този от Y

    std::cout << '\n';
    std::cout << '\n';

    delete ptrOfTypeX;

    ptrOfTypeX = new X(1); // сочи към обект от тип X
    ptrOfTypeX->print();
    std::cout << '\n';

    delete ptrOfTypeX;
}

void testWithReference()
{
    Y obj(3,4);
    X& refOfTypeX = obj; // референция от тип X за обект от тип Y
    refOfTypeX.print(); // ако print() е виртуален ще се извика този от Y
    std::cout << '\n';
}


int main()
{
    //testWithPointers();
    //testWithReference();
 
    return 0;
}