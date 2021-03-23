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

    //binary
    Rational operator-(const Rational& rhs) const;

    // operator*=
    Rational& operator*=(const Rational& rhs);

    //cast to double
    operator double() const;

    // operator<<
    friend std::ostream& operator<<(std::ostream& o, const Rational& obj);

    // operator>>
    friend std::istream& operator>>(std::istream& i, Rational& obj);
    
    
    //operator + with first argument int
    friend Rational operator+(int x, const Rational& r);

    // TODO
    
    // operator*
    // operator/
    // operator+=
    // operator-=
    // operator/=
    // operator-- (prefix/postfix)    

private:
    void simplify();
};

