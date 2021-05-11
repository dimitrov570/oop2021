#pragma once
#include <cinttypes>
#include <iostream>
#include <string>
#include "Driveable.hpp"
#include "Printable.hpp"

class Vehicle : public Driveable, public Printable {
protected:
    uint8_t numberOfTyres;
    std::string model;
    unsigned maxSpeed;
public:
    Vehicle(uint8_t = 0, std::string = "", unsigned = 0);
    void print() override;
    void printLn() override;
    virtual ~Vehicle();
};