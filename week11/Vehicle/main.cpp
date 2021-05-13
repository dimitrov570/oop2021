#include <iostream>
#include "HybridCar.hpp"
#include <vector>

void test() {
    PetrolCar bmw(4, "BMW 3 Series", 250, 6000);
    bmw.drive();
    ElectricCar tesla(4, "Tesla Model S", 243, 600);
    tesla.drive();
    bmw.printLn();
    tesla.printLn();
    
    HybridCar prius(4, "Toyota Prius", 200, 400, 5300);
    prius.printLn();
    prius.drive();
    std::cout << "\n"; 
}

void polymorphismTest() {
    std::vector <Vehicle*> vehicleVector;
    vehicleVector.push_back(new PetrolCar(4, "BMW 3 Series", 250, 6000));
    vehicleVector.push_back(new ElectricCar(4, "Tesla Model S", 243, 600));
    vehicleVector.push_back(new HybridCar(4, "Toyota Prius", 200, 400, 5300));
    for (auto x : vehicleVector) {
        x->printLn();
    }
}

void nonPolymorphicTest() {
    std::vector <Vehicle*> vehicleVector;
    vehicleVector.push_back(new PetrolCar(4, "BMW 3 Series", 250, 6000));
    vehicleVector.push_back(new ElectricCar(4, "Tesla Model S", 243, 600));
    vehicleVector.push_back(new HybridCar(4, "Toyota Prius", 200, 400, 5300));
    for (auto x : vehicleVector) {
        PetrolCar* pPointer = dynamic_cast<PetrolCar*>(x);
        if (pPointer != nullptr) {
            pPointer -> drive();  
        }     
    }
}
template<typename T, typename V>
bool compare() {
    return typeid(T) == typeid(V);
} 
int main() {
    nonPolymorphicTest();
    PetrolCar a;
    
    std::cout << typeid(int).name() << '\n';

    std::cout << compare<int, int>();
    return 0;
}
