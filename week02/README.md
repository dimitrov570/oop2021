## Основни ООП принципи
- Енкапсулация
- Абстракция
- Наследяване
- Полиморфизъм

## Енклапсулация
- Спецификатори за достъп
  - private - достъпни само от методите на класа
     - private член-данни 
     - private методи
  - public - достъпни и отвън
  - protected - достъпни само от методите на класа и на класове наследници
- В заглавни (header) файлове се пишат:
  - дефиниции на класове
  - декларации на методи
- Имплементациите се пишат в source файловете
    - по този начин не разкриваме имплементацията, а само интерфейса
    - външните функции зависят само от интерфейса, следователно можем да променим имплементацията без да правим промени по външните функции

## Абстракция
- използване на функционалности, без да знаем каква е имплементацията 

## Класове
- член-данни
- член-функции (методи)
- конструктори 

## Член-данни от същия тип

- директна рекурсия 
```c++
class MyClass {

    int var;
    MyClass obj; //забранено
public:

    void print();

};
```

- чрез указател
```c++
class MyClass {

    int var;
    MyClass* obj; //позволено
public:

    void print();

};
```

### Обекти
- инстанции на класове (променливи от този тип клас)

### Подравняване

### Конструктори
- конструктор по подразбиране:  ``MyClass()``
- конструктор с параметри:  ``MyClass(int)``

```c++
class MyClass {

    int var;

public:
    MyClass(); //default constructor
    MyClass(int); //constructor with parameters
    void print();

};
```

Извикване на контруктор:
```c++
    MyClass var; //default constructor called
    MyClass var(5); //implicit call
    MyClass var = MyClass(5); //explicit call
```


### Инициализиращ списък (Member initializer list)

- задават се стойности на член-данните по време на тяхната дефиниция (преди тялото на конструктора).
Пример:
```c++
    Rational::Rational(int num, double denom) : numerator(num), denominator(denom) {}
```
- иначе първо се заделя паметта (извиква се конструктора по подразбиране за обекти) и след това се присвояват стойностите. 
Пример:
```c++
    MyClass::MyClass(int value1, double value2) 
    {   
        this->var1 = value1;
        this->var2 = value2;
    }
```
- позволява инициализация на константи. Пример:
    ```c++
        class Example {
            const int MY_CONST;
            int var;

        public:
            Example(int constValue, int Var) : MY_CONST(constValue), var(Var) {}
        }
    ```
    - защо следното няма да работи:
    ```c++
        Example(int constValue, int Var) : var(Var) {
                MY_CONST = constValue;
            }
    ```


### this
- указател към текущия обект
- при извикване на функция автоматично се подава константен указател ``this`` като първи аргумент
    - пример: метода ``print()`` от ``MyClass``
    ```c++
        void print(MyClass* const this); 
    ```
    - при извикване на метода ``obj.print()`` се получава ``MyClass::print(&obj);``

### const
- пример: ``void print() const;``
- означава, че този метод не може да променя член-данните на класа
- по-точно метода автоматично получава константен указател към константа 
```c++
    int getVar(MyClass const * const this);
```

### Селектори 
- член-функции за достъп до член-данните на класовете

```c++
    int getVar() const {
        return var;
    }
```

### Мутатори
- член-функции за промяна на член-данните на класовете

```c++
    int setVar(int newValue) {
        this->var = newValue;
    }
```

### Достъп до членовете на класа
- чрез обект
```c++
    MyClass obj;
    obj.print();
```

- чрез указател
```c++
    MyClass *ptr = &obj;
    ptr->print();
    (*ptr).print(); //също като горното
```

### Всеки запис или клас дефинира област (scope)
- за да достъпим членовете извън класа трябва да укажем и името на областта

## Пример с MyClass
### В header файла ``MyClass.hpp`` се съдържа интерфейса на класа

```c++
#pragma once

class MyClass {

    int var;

public:

    MyClass();
    MyClass(int);

    int getVar() const;
    void print() const;

    void setVar(int newVar);
};
```

### В source файла се съдържа имплементацията на класа

```c++
#include "MyClass.hpp"

MyClass::MyClass()
{
    this->var = 0;
}

MyClass::MyClass(int newVar) : var(newVar) {}

int MyClass::getVar() const 
{
    return var;
}

void MyClass::print() const 
{
    std::cout << var << "\n";
}

void MyClass::setVar(int newVar) 
{
    this->var = newVar;
}

```

### Вградени (inline) функции
- тялото им се заместа при всяко тяхно извикване
- такива са:
    - член-функции дефинирани в дефиницията на класа
    - функции, които преди дефиницията имат ключова дума ``inline``


## Какво прави #include?

# Задача
Реализирайте клас ``Rational``, който представлява рационални числа. Имплементирайте следните методи:
- ``Rational()`` - конструктор по подразбиране
- ``Rational(int, int)`` - конструктор с два параметра (числител и знаменател)
- ``Rational(int)`` - конструктор, приемащ цяло число
- селектори (getters)
    - за достъп
    - за извеждане на стандартния вход във формат "numerator/denominator"
    - за конвертиране към double
- мутатори (setters)
    - за смяна на член-данните
    - за въвеждане от стандартния вход
- методи за аритметични операции с рационални числа (събиране, изваждане, умножение и деление), които да връщат нов обект от тип ``Rational``
#### За съкращаване на дробите използвайте ``std::gcd``.
