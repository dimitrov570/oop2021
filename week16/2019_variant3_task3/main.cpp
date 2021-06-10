#include "TShirt.hpp"
#include "Shop.hpp"
#include <iostream>

int main()
{
    TShirt t1("teniska", 30, "black", "XL");
    TShirt t2 = t1;


    Shop s;
    s.addProduct(&t1);
    s.addProduct(&t2);
    s.changeName("tenisk11", 1);
    s.changePrice(20, 1);
    Shoes shoes1("obuvka", 70, "black", "detski");
    s.addProduct(&shoes1);

    s.printAllProducts();

    return 0;
}