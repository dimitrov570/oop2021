#include "Fruit.hpp"

Fruit::Fruit(const std::string innitName, unsigned int initCalories, double initPrice, const std::string initColor) : 
StoreItem(TypeOfItem::FRUIT, innitName, initCalories, initPrice), color(initColor) {}


void Fruit::setColor(std::string newColor)
{
    color = newColor;
}

bool Fruit::operator>(const Fruit& other) const
{
    return calories > other.calories;
}

void Fruit::print() const
{
    StoreItem::print();
    std::cout<<" Type: FRUIT"<<" Color: "<<color<<std::endl;
}