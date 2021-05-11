#include "HybridCar.hpp"

HybridCar::HybridCar(uint8_t initNumberOfTyres, std::string initModel,
    unsigned initMaxSpeed, unsigned initBatteryCapacity, unsigned initEngineCapacity) :
    Vehicle(initNumberOfTyres, initModel, initMaxSpeed),
    PetrolCar(initNumberOfTyres, initModel, initMaxSpeed, initEngineCapacity),
    ElectricCar(initNumberOfTyres, initModel, initMaxSpeed, initBatteryCapacity) {}

void HybridCar::print() {
    Vehicle::print();
    std::cout << "; ";
    ElectricCar :: printNonVirtual();
    std::cout << "; ";
    PetrolCar :: printNonVirtual();
    
}

void HybridCar::printNonVirtual() {

}

void HybridCar::printNonVirtualLn() {

}

void HybridCar::drive () {
    std::cout << "Driving hybrid car: " << model << '\n';
}