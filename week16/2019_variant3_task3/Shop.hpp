#pragma once
#include "StoreItem.hpp"
#include "Shoes.hpp"
#include "TShirt.hpp"
#include <vector>

class Shop
{
    std::string name;
    std::vector<StoreItem*> container;

public:
    void addProduct(StoreItem* product);
    void changeName(const char* newName, size_t index);
    void changePrice(double newPrice, size_t index);
    void removeProduct(size_t index);

    void printAllProducts() const;

    ~Shop();
};
