#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

/* bubbleSort функция, чиито параметри са:
 *   указател към начало на масив;
 *   големина на масива
 *   функция, която сравнява две променливи от тип int (по подразбиране ги сравнява с <)
*/
void bubbleSort(int* arr, int n, std::function<bool(int, int)> comparator = [](int a, int b) -> bool { return a > b; }) // bool (*comparator)(int, int)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (comparator(arr[j], arr[j + 1]))
            {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void testBubbleSort()
{
    const int ARRAY_SIZE = 5;
    int* arr = new int[ARRAY_SIZE];

    srand(time(NULL));

    // на всички елементи присвояваме случайни числа
    for (int i = 0; i < ARRAY_SIZE; ++i)
    {
        arr[i] = rand();
    }

    // като трети аргумент подаваме функция, която сравнява две променливи от тип инт с <=
    // елементите ще се сортират в низходящ ред
    bubbleSort(arr, ARRAY_SIZE, [](int a, int b) { return a <= b; });

    for (int i = 0; i < ARRAY_SIZE; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << '\n';

    delete[] arr;
}

// std::for_each 
void testForEachIncrement()
{
    const int ARRAY_SIZE = 5;
    int arr[ARRAY_SIZE] = { 1, 2, 3, 4, 5 };

    // като трети аргумент подаваме фунцкия, която взима число по референция и го увеличава за 1
    std::for_each(arr, arr + ARRAY_SIZE, [](int &x) { x = x + 1; });

    for (int i = 0; i < ARRAY_SIZE; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << '\n';
}

/* filter функция, чиито параметри са: 
 *   оригиналният вектор; 
 *   вектор, в който се слагат елементите удовлетворяващи условието
 *   функция, която проверява дали елемент удовлетворява условие
*/ 
 void filter(const std::vector<int>& original, std::vector<int>& filtered, std::function<bool(int)> filter)
{
    std::for_each(original.begin(), original.end(), [&](int x) { if (filter(x)) filtered.push_back(x); });
}

void testForEachFilter()
{
    std::vector<int> original;
    original.push_back(1);
    original.push_back(2);
    original.push_back(3);
    original.push_back(4);
    original.push_back(5);
    original.push_back(6);

    std::vector<int> filtered;

    // като трети аргумент подаваме функция, която проверява дали число е четно
    filter(original, filtered, [](int x) -> bool { return x % 2 == 0; });

    for (int i = 0; i < filtered.size(); ++i)
    {
        std::cout << filtered[i] << " ";
    }
    std::cout << '\n';

}

// captures
void testCaptures()
{
    int a = 0;
    int b = 0;

    // []() mutable { std::cout << ++a << '\n'; } ();

    std::cout << "Capturing by copy:\n";
    [=]() mutable throw() { std::cout << "a: " << ++a << '\n'; } ();
    std::cout << "a: " << a << '\n';
    std::cout << "--------------------\n";

    std::cout << "Capturing by reference:\n";
    // only b => [&b]
    [&]() mutable { std::cout << "b: " << ++b << '\n'; } ();
    std::cout << "b: " << b << '\n';
    std::cout << "--------------------\n";

    std::cout << "Capturing 'a' by copy and 'b' by reference:\n";
    // [=,&b]
    [&, a]() mutable { std::cout << "a: " << ++a << "; b: " << ++b << '\n'; } ();
    std::cout << "a: " << a << "; b: " << b << '\n';
    std::cout << "--------------------\n";
}

int main()
{
    // testBubbleSort();
    // testForEachIncrement();
    // testForEachFilter();
    // testCaptures();

    return 0;
}
