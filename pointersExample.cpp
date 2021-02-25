#include <iostream>
using namespace std;


int main(){

    int arr[2] = {55, 66};

    int *ptr = arr;
    int *ptr1 = &arr[0];
    int *ptr2 = &arr[1];

    //какво е arr?

    //cout << *(arr + 1) << "\n"; 
    //cout << *(arr - 2) << "\n"; 
    //cout << *(arr + 4) << "\n";

    //cout << "Value of ptr: " << ptr << "\n";
    //cout << "Value of ptr1: " << ptr1 << "\n";
    //cout << "Value of ptr2: " << ptr2 << "\n";

    //cout << "Value of &arr[0]: " << &arr[0] << "\n";

    //cout<< "Value of arr: " << arr << "\n";
    //cout << "Value of *ptr1: " << *ptr1 << "\n";
    //cout << "Value of *ptr2: " << *ptr2 << "\n";


    return 0;