#pragma once

// Printing only non virtual members
class NonVirtualPrintable {
public:
    virtual void printNonVirtual() = 0;
    virtual void printNonVirtualLn() = 0;
};
