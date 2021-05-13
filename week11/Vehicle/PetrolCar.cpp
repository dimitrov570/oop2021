#include "PetrolCar.hpp"

PetrolCar::PetrolCar(uint8_t initNumberOfTyres, std::string initModel,
    unsigned initMaxSpeed, unsigned initEngineCapacity) :
    Vehicle(initNumberOfTyres, initModel, initMaxSpeed), engineCapacity(initEngineCapacity) {}

void PetrolCar::drive() {
    std::cout << "Driving petrol car " << model << '\n'; 
}

void PetrolCar::print () {
    Vehicle::print();
    std::cout << "; EngineCapacity: " << engineCapacity << " cc";
}

void PetrolCar::printNonVirtual() {
    std::cout << "EngineCapacity: " << engineCapacity << " cc"; 
}

void PetrolCar::printNonVirtualLn() {
    printNonVirtual();
    std::cout << '\n';
}
