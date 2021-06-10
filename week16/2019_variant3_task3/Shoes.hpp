#pragma once
#include "StoreItem.hpp"
#include <iostream>

class Shoes : public StoreItem
{  
    std::string shoeType;

public:
    Shoes(const char* initName, double initPrice, const char* initColor, std::string initShoeType);

    std::string getShoeType() const;

    void setShoeType(const char* newType);

    void print() const override;
};
