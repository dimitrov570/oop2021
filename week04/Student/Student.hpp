#pragma once

class Student
{
    char* name;
    int facultyNumber;
    int age;
    Student* bestFriend;

public:
    Student(const char* Name, int fn, int Age, Student* bff = nullptr);
    Student(const Student& copyFrom);
    Student& operator=(const Student& rhs);
    ~Student();
    
    const char* getName() const;
    int getFacultyNumber() const;
    int getAge() const;
    Student* getBestFriend() const;

    void print() const;

    bool setName(const char*);
    bool setFacultyNumber(int);
    bool setAge(int);
    bool setBestFriend(Student*);

    bool operator<(const Student& rhs) const;

};