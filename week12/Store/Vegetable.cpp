#include "Vegetable.hpp"

Vegetable::Vegetable(const std::string& initName, unsigned int initCalories, double initPrice, const std::string& initSort) :
StoreItem(TypeOfItem::VEGETABLE, initName, initCalories, initPrice), sort(initSort) {}

void Vegetable::setSort(const std::string& newSort)
{
    sort = newSort;
}

bool Vegetable::operator==(const Vegetable& other) const
{
    return sort == other.sort;
}

void Vegetable::print() const
{
    StoreItem::print();
    std::cout<<" Type: VEGETABLE"<<" Sort: "<<sort<<std::endl;
}