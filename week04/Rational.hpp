#pragma once
#include <iostream>

class Rational
{
private:
    int numerator;
    int denominator;

public:
    Rational(int n = 0, int d = 1);

    int getNumerator() const;
    int getDenominator() const;
    double toDouble() const;
    void print() const;

    bool setNumerator(int);
    bool setDenominator(int);

    /* TODO
    operator+ 
    operator- (unary/binary)
    operator*
    operator/
    operator+=
    operator-=
    operator*=
    operator/=
    operator++ (prefix/postfix)
    operator-- (prefix/postfix)
    operator<<
    operator>>
    */

private:
    void simplify();
};