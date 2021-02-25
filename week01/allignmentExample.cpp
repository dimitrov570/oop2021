#include <iostream>
using namespace std;

struct Allignment1 {
    uint8_t a;
    uint16_t b;
    uint32_t c;
    uint8_t d;
};

struct Allignment2 {
    static int p;
    uint8_t a;
    uint8_t d;
    uint16_t b;
    uint32_t c;
} x,y; //създават се два обекта x и y

int Allignment2::p = 0; //декларира се статичната променлива p, преди да се използва

int main(){

    cout << "Size of Allignment1; " << sizeof(Allignment1) << "\n";
    cout << "Size of Allignment1; " << sizeof(Allignment1) << "\n";

    x.p = 3;
    cout << "Value of p in y: " << y.p << "\n";

    y.p = 4;
    cout << "Value of p in x: " << x.p << "\n";

    return 0;
}