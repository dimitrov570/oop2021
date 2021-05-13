#pragma once 
#include "Vehicle.hpp"
#include <iostream>
#include "NonVirtualPrintable.hpp"

class PetrolCar : virtual public Vehicle, virtual public NonVirtualPrintable {
protected:
    unsigned engineCapacity;
public:
    PetrolCar(uint8_t = 0, std::string = "", unsigned = 0, unsigned = 0);    
    void drive() override;
    void print() override;
    void printNonVirtual() override;
    void printNonVirtualLn() override;
};
