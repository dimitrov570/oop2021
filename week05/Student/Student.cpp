#include "Student.hpp"
#include <iostream>
#include <cstring>

Student::Student(const char* Name, int fn, int Age, Student* bff) : facultyNumber(fn), age(Age), bestFriend(bff)
{
    int nameLength = strlen(Name);
    name = new char[nameLength + 1];
    strcpy(name, Name);
}

Student::Student(const Student& copyFrom)
{
    int nameLength = strlen(copyFrom.name);
    name = new char[nameLength + 1];
    strcpy(name, copyFrom.name);
    facultyNumber = copyFrom.facultyNumber;
    age = copyFrom.age;
    bestFriend = copyFrom.bestFriend;
}

Student& Student::operator=(const Student& rhs)
{
    if(this != &rhs)
    {
        delete[] name;
        int nameLength = strlen(rhs.name);
        name = new char[nameLength + 1];
        strcpy(name, rhs.name);
        facultyNumber = rhs.facultyNumber;
        age = rhs.age;
        bestFriend = rhs.bestFriend;
    }
    return *this;
}

Student::~Student()
{
    delete[] name;
}

const char* Student::getName() const
{
    return name;
}

int Student::getFacultyNumber() const
{
    return facultyNumber;
}

int Student::getAge() const
{
    return age;
}

Student* Student::getBestFriend() const
{
    return bestFriend;
}

void Student::print() const
{
    std::cout << "Name: " << name << "; FN: " << facultyNumber << "; age: " << age << '\n';
}

bool Student::setName(const char* newName)
{
    int nameLength = strlen(newName);
    if(nameLength > 0)
    {
        delete[] name;
        name = new char[nameLength + 1];
        strcpy(name, newName);
        return true;
    }
    return false;
}

bool Student::setFacultyNumber(int newFn) 
{
    if(newFn > 0)
    {
        facultyNumber = newFn;
        return true;
    }
    return false;
}

bool Student::setAge(int newAge)
{
    if(newAge >= 0)
    {
        age = newAge;
        return true;
    }
    return false;
}

bool Student::setBestFriend(Student* newBff)
{   if(this != newBff)
    {
        bestFriend = newBff;
        return true;
    }
    return false;
}


bool Student::operator<(const Student& rhs) const
{
    return this->facultyNumber < rhs.facultyNumber;
}

std::ostream& operator<<(std::ostream& o, const Student& student)
{
    return o << "Name: " << student.name << "; FN: " << student.facultyNumber << "; age: " << student.age << '\n';
} 