#include "Vehicle.hpp"

Vehicle::Vehicle(uint8_t initNumberOfTyres, std::string initModel, unsigned initMaxSpeed) :
    numberOfTyres(initNumberOfTyres), model(initModel), maxSpeed(initMaxSpeed) {}

void Vehicle::print() {
    std::cout << "Number of tyres: " << (int) numberOfTyres << "; Model: " << model << "; Max speed: " << maxSpeed;
}

void Vehicle::printLn() {
    print();
    std::cout << '\n';
}

Vehicle::~Vehicle() {
    std::cout << "Deleted!\n";
}
