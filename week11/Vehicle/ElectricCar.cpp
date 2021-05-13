#include "ElectricCar.hpp"

ElectricCar::ElectricCar(uint8_t initNumberOfTyres, std::string initModel,
    unsigned initMaxSpeed, unsigned initBatteryCapacity) :
    Vehicle(initNumberOfTyres, initModel, initMaxSpeed), batteryCapacity(initBatteryCapacity) {}

void ElectricCar::drive() {
    std::cout << "Driving electric car: " << model << '\n';
}

void ElectricCar::print() {
    Vehicle::print();
    std::cout << "; BatteryCapacity " << batteryCapacity << " kWh";
}

void ElectricCar::printNonVirtual() {
    std::cout << "BatteryCapacity: " << batteryCapacity << " kWh"; 
}

void ElectricCar::printNonVirtualLn() {
    printNonVirtual();
    std::cout << '\n';
}
