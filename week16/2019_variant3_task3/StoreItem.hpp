#pragma once
#include <string>

enum class ProductType
{
    TShirt,
    Shoes
};

class StoreItem
{
protected:
    std::string color;
    ProductType typeOfProduct;
    std::string name;
    double price;

public:
    StoreItem(const char* initColor, ProductType type, const char* initName, double initPrice);
  
    std::string getColor() const;
    ProductType getType() const;
    std::string getName() const;
    double getPrice() const;


    void setColor(const char* newColor);
    void setType(ProductType newType);
    void setName(const char* newName);
    void setPrice(double price);

    virtual ~StoreItem() = 0;

    virtual void print() const;
};

