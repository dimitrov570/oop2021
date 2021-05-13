#pragma once
#include "StoreItem.hpp"
#include <string>

class Fruit : public StoreItem
{
private:
    std::string color;
public:
    Fruit( const std::string innitName = "", unsigned int initCalories = 0, double initPrice = 0, const std::string initColor = "");
    void setColor(std::string);
    bool operator>(const Fruit&) const;
    void print() const override;
};