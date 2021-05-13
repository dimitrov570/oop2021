#pragma once
#include "StoreItem.hpp"
#include "Fruit.hpp"
#include "Vegetable.hpp"
#include <vector>

class Shop
{
private:
    std::vector<StoreItem*> container;
public:
    void addProduct(StoreItem*);
    void removeProduct(unsigned int index);
    void changePrice(unsigned int index, double newPrice);
    void changeNameOfProduct(unsigned int index, const std::string& newName);
    void printAll() const;
    Fruit mostCaloricFruit() const;
};