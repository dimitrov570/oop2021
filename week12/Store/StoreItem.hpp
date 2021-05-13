#pragma once 
#include <iostream>
#include <string>

enum class TypeOfItem
{
    FRUIT,
    VEGETABLE,
    DEFAULT
};

class StoreItem
{
protected:
    std::string name;
    TypeOfItem type;
    unsigned int calories;
    double price;
public:
    StoreItem(TypeOfItem = TypeOfItem::DEFAULT, const std::string& = "", unsigned int = 0, double = 0);
    virtual ~StoreItem() = 0;
    TypeOfItem getType() const;
    unsigned int getCalories() const;
    double getPrice() const;
    void setType(TypeOfItem);
    void setCalories(unsigned int);
    void setPrice(double);
    virtual void print() const;
    std::string getName() const;
    void setName(const std::string&);
};