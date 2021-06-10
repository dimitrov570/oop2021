#include "TShirt.hpp"
#include <iostream>

TShirt::TShirt(const char* initName, double initPrice, const char* initColor, const char* initSize)
    : StoreItem(initColor, ProductType::TShirt, initName, initPrice), size(initSize)
    {}

std::string TShirt::getSize() const
{
    return size;
}

void TShirt::setSize(const char* newSize)
{
    size = newSize;
}

bool TShirt::operator==(const TShirt& rhs) const
{
    if(color == rhs.color && size == rhs.size)
    {
        return true;
    }

    return false;
}

void TShirt::print() const
{
    std::cout << "T-shirt -> ";
    StoreItem::print();
    std::cout << "; Size: " << size;
}