#include <iostream>
using namespace std;

struct Alignment1 {
    static int q; //декларация на статичната промелнива q
    uint8_t a;
    uint16_t b;
    uint32_t c;
    uint8_t d;
};

int Alignment1::q = 0; //дефинира се статичната променлива q извън класа, преди да се използва

struct Alignment2 {
    static int p; //декларация на статичната промелнива p
    uint8_t a;
    uint8_t d;
    uint16_t b;
    uint32_t c;
} x,y; //създават се два обекта x и y

int Alignment2::p = 0; //дефинира се статичната променлива p извън класа, преди да се използва

int main(){
    
    //статичните променливи можем да достъпим и без да има създадени обекти от този тип
    //забележете, че от Alignment1 не са създавани обекти
    cout << "Value of q: " << Alignment1::q << "\n";

    cout << "Size of Alignment1: " << sizeof(Alignment1) << "\n";
    cout << "Size of Alignment2: " << sizeof(Alignment2) << "\n";

    x.p = 3;
    cout << "Value of p in y: " << y.p << "\n";

    y.p = 4;
    cout << "Value of p in x: " << x.p << "\n";

    return 0;
}