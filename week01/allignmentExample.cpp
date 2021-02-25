#include <iostream>
using namespace std;

struct Allignment1 {
    static int q; //декларация на статичната промелнива q
    uint8_t a;
    uint16_t b;
    uint32_t c;
    uint8_t d;
};

int Allignment1::p = 0; //дефинира се статичната променлива q извън класа, преди да се използва

struct Allignment2 {
    static int p; //декларация на статичната промелнива p
    uint8_t a;
    uint8_t d;
    uint16_t b;
    uint32_t c;
} x,y; //създават се два обекта x и y

int Allignment2::p = 0; //дефинира се статичната променлива p извън класа, преди да се използва

int main(){
    
    //статичните променливи можем да достъпим и без да има създадени обекти от този тип
    //забележете, че от Allignment1 не са създавани обекти
    cout << "Value of p: " << Allignment1::q << "\n";

    cout << "Size of Allignment1: " << sizeof(Allignment1) << "\n";
    cout << "Size of Allignment2: " << sizeof(Allignment2) << "\n";

    x.p = 3;
    cout << "Value of p in y: " << y.p << "\n";

    y.p = 4;
    cout << "Value of p in x: " << x.p << "\n";

    return 0;
}