#pragma once
#include "StoreItem.hpp"

class TShirt : public StoreItem
{
    std::string size;
public:
    TShirt(const char* initName, double initPrice, const char* color, const char* size);

    std::string getSize() const;
    void setSize(const char* newSize);

    bool operator==(const TShirt&) const;

    void print() const override;
};