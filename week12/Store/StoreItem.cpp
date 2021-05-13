#include "StoreItem.hpp"
#include <iostream>

StoreItem::StoreItem(TypeOfItem initType, const std::string& initName, unsigned int initCalories, double initPrice) : 
type(initType), name(initName), calories(initCalories), price(initPrice) {}

StoreItem::~StoreItem()
{

}

TypeOfItem StoreItem::getType() const
{
    return type;
}

unsigned int StoreItem::getCalories() const
{
    return calories;
}

double StoreItem::getPrice() const
{
    return price;
}

void StoreItem::setType(TypeOfItem newType)
{
    type = newType;
}

void StoreItem::setCalories(unsigned int newCalories)
{
    calories = newCalories; 
}

void StoreItem::setPrice(double newPrice)
{
    price = newPrice;
}

void StoreItem::print() const
{
    std::cout<<"Name: "<<name<<" Calories: "<<calories<<" Price: "<<price;
}

std::string StoreItem::getName() const
{
    return name;
}

void StoreItem::setName(const std::string& newName)
{
    name = newName;
}