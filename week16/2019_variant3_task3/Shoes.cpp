#include "Shoes.hpp"

Shoes::Shoes(const char* initName, double initPrice, const char* initColor, std::string initShoeType)
    : StoreItem(initColor, ProductType::TShirt, initName, initPrice), shoeType(initShoeType)
    {}

std::string Shoes::getShoeType() const
{
    return shoeType;
}

void Shoes::setShoeType(const char* newType)
{
    shoeType = newType;
}

void Shoes::print() const
{
    std::cout << "Shoes -> ";
    StoreItem::print();
    std::cout << "; ShoeType: " << shoeType;
}