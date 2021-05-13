#pragma once 
#include "PetrolCar.hpp"
#include "ElectricCar.hpp"

class HybridCar : public PetrolCar, public ElectricCar {
public:
    HybridCar(uint8_t = 0, std::string = "", unsigned = 0, unsigned = 0, unsigned = 0);

    void drive() override;
    void print() override;

    void printNonVirtual() override;
    void printNonVirtualLn() override;


};
