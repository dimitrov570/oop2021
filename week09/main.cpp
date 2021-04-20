#include <iostream>
#include "Student.hpp"
#include "Teacher.hpp"
#include <fstream>

class A
{
public:
    int var; 

    virtual void print()
    {
        std::cout << var;
    }
};

void writeObjectToFile()
{
    A objA;
    objA.var = 0x12345678;

    // Ако класът А има виртуални функции, тогава във файла първо ще се запише указателя към виртуалната му таблица
    // може да го видите с hexdump
    std::ofstream fo("output.bin", std::ios::binary | std::ios::out);
    fo.write((const char*)&objA, sizeof(objA));
}

void staticBindExample()
{
    Student s("Ivan Ivanov", 22, 55555);

    s.println();

    ((Person)s).println();

}

void dynamicBindExample()
{
    Person* personTypePtr;

    personTypePtr = new Student("Ivan Ivanov", 22, 55555);
    personTypePtr->println(); // runtime <=> вземи функцията на индекс i от виртуалната таблица
    
    delete personTypePtr;

    Teacher t("Alexander Alexandrov", 55, 300);

    personTypePtr = &t;
    personTypePtr->println(); // runtime <=> вземи функцията на индекс i от виртуалната таблица
    
    // чрез референция
    Person& playerTypeReference = t;
    playerTypeReference.println();
}



int main()
{ 
    // staticBindExample();
    // dynamicBindExample();
    // writeObjectToFile();

    return 0;
}