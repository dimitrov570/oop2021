#include "Person.hpp"

class Teacher : public Person
{

int salary;

public:
    Teacher(const char*, int, int);

    void print() const;
    void println() const;

};