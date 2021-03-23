#include <iostream>
#include <vector>
#include <algorithm>
#include "Student.hpp"

int main()
{
    Student s1("Ivan", 10, 20);
    Student s2("Stoyan", 12, 20, &s1);
    s2.setBestFriend(&s1);
    Student s3("Aleksandar", 8, 21);
    Student s4("Kaloyan", 6, 21, &s3);
    s3.setBestFriend(&s4);

    (s3 = s1).setName("Michael");

    std::vector<Student> studentVector;
    studentVector.push_back(s1);
    studentVector.push_back(s2);
    studentVector.push_back(s3);
    studentVector.push_back(s4);

    std::sort(studentVector.begin(), studentVector.end());

    for(int i = 0; i < studentVector.size(); ++i)
    {
        std::cout << studentVector[i]; 
    }
    
    return 0;
}