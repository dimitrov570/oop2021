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


    Rational operator+(int x) const;
    Rational& operator++(); //prefix
    Rational operator++(int); //postfix

    //unary
    Rational operator-() const;

    //cast to double
    operator double() const;


    // TODO
    // operator- (binary)
    // operator*
    // operator/
    // operator+=
    // operator-=
    // operator*=
    // operator/=
    // operator-- (prefix/postfix)
    // operator<<
    // operator>>

private:
    void simplify();
};

//operator + with first argument int
Rational operator+(int x, const Rational& r);