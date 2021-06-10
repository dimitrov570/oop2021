#include "StoreItem.hpp"
#include <iostream>

StoreItem::StoreItem(const char* initColor, ProductType type, const char* initName, double initPrice) 
    : color(initColor), typeOfProduct(type), name(initName), price(initPrice) {}

std::string StoreItem::getColor() const
{
    return color;
}

ProductType StoreItem::getType() const
{
    return typeOfProduct;
}

std::string StoreItem::getName() const
{
    return name;
}

double StoreItem::getPrice() const
{
    return price;
}

void StoreItem::setColor(const char* newColor)
{
    color = newColor;
}

void StoreItem::setType(ProductType newType)
{
    typeOfProduct = newType;
}

void StoreItem::setName(const char* newName)
{
    name = newName;
}

void StoreItem::setPrice(double newPrice)
{
    price = newPrice;
}

void StoreItem::print() const
{
    std::cout << "Color: " << color << "; Name: " << name << "; Price: " << price;
}

StoreItem::~StoreItem()
{

}