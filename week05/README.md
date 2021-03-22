# Enum
- enum
```c++
#include <iostream>

enum Gender /*: uint8_t или int или някоя друга целочислена променлива */
{
    Male = 6,
    Female = 4000
};

int main()
{
    Gender gender = Female; //стойностите са видими в областта, където е дефиниран enum-а
    
    int a = gender; //възможно е имплицитно cast-ване

    std::cout << a << '\n';

    switch (gender)
    {
    case Gender::Male:
        std::cout << "Male";
        break;
    case Gender::Female:
        std::cout << "Female";
        break;
    default:
        break;
    }

    return 0;
}


```
- enum class  

```c++
#include <iostream>

enum class Gender /*: uint8_t или int или някоя друга целочислена променлива */
{
    Male = 6,
    Female = 4000
};

int main()

    /*
    стойностите НЕ са видими в областта, където е дефиниран enum-а
    налага се да се укаже областта (името на enum-а)
    */
    Gender gender = Gender::Female; 
    
    int a = (int)gender; //НЕ е възможно е имплицитно cast-ване

    std::cout << a << '\n';

    switch (gender)
    {
    case Gender::Male:
        std::cout << "Male";
        break;
    case Gender::Female:
        std::cout << "Female";
        break;
    default:
        break;
    }

    return 0;
}


```

Може да се изостави присвояването на целочислени стойности. Тогава автоматично ще получат нарастващи стойности, започвайки от 0.
```c++
enum class Gender /*: uint8_t или int или някоя друга целочислена променлива */
{
    Male, //ще има стойност 0
    Female //ще има стойност 1
};

```

# Приятелски класове и функции

Класове и външни функции, които имат достъп до `private` и `protected` членовете на клас, който ги дефинира като такива.

Пример за класа [Student](https://github.com/dimitrov570/oop2021/tree/main/week05/Student):  
В .hpp файл:
```c++
#pragma once
#include <iostream>

class Student
{
    //...
    friend std::ostream& operator<<(std::ostream& o, const Student& student);
    //...
};
```

В .cpp файл:
```c++
#include "Student.hpp"
#include <iostream>
#include <cstring>

//...
std::ostream& operator<<(std::ostream& o, const Student& student)
{
    return o << "Name: " << student.name << "; FN: " << student.facultyNumber << "; age: " << student.age << '\n';
}
//...
```

В main.cpp:
```c++
#inlcude <iostream>
#include "Student.hpp"

int main()
{

    Student ivan("Ivan", 10, 20);
    std::cout << ivan;

    return 0;
}
```
Резултата от изпълнението на тази програма ще бъде:   ``Name: Ivan; FN: 10; age: 20``

## Задачи

### Задача 1
Предефинирайте операторите от `TODO` списъка в класа `Rational` от миналата седмица. (Линк: [тук](https://github.com/dimitrov570/oop2021/tree/main/week04/Rational)).

### Задача 2

Предефинирайте следните оператори за класа `Vector` от предишните упражнения:
- `operator=`
- `operator[]`   

#### Бонус към Задача 2
Добавете следните методи към същия клас:
- `insertAt(int index, int value)`, който вмъква `value`, на позиция `index`
- `removeAt(int index)`, който премахва елемента на позиция `index`

Интерфейса и част от имплементацията можете да намерите [тук](https://github.com/dimitrov570/oop2021/tree/main/week03/Vector).

### Задача 3
Имплементирайте клас `Stack`, използвайки класа `Vector`. Повече информация за стек можете да намерите [тук](https://en.wikipedia.org/wiki/Stack_(abstract_data_type)).

### Задача 4
Имплементирайте Singly [linked list](https://en.wikipedia.org/wiki/Linked_list).