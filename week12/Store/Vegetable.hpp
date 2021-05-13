#pragma once
#include "StoreItem.hpp"
#include <string>

class Vegetable : public StoreItem
{
private:
    std::string sort;
public:
    Vegetable(const std::string& = "", unsigned int = 0, double = 0, const std::string& = "");
    void setSort(const std::string&);
    bool operator==(const Vegetable&) const;
    void print() const override;
};