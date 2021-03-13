#include "Rational.hpp"
#include <numeric>

Rational::Rational(int n, int d) : numerator(n) 
{
    if (d != 0) 
    {
        denominator = d;
        simplify();
    }
    else
    {
        denominator = 1;
    }
}

int Rational::getNumerator() const
{
    return numerator;
}

int Rational::getDenominator() const 
{
    return denominator;
}

double Rational::toDouble() const
{
    return (double) numerator / denominator;
}

void Rational::print() const
{
    std::cout << numerator << '/' << denominator;
}

bool Rational::setNumerator(int n) 
{
    numerator = n;
    simplify();
    return true;
}

bool Rational::setDenominator(int d)
{
    if (d != 0) 
    {
        denominator = d;
        simplify();
        return true;
    }
    return false;
}

void Rational::simplify()
{
    int gcd = std::gcd(numerator, denominator); //available from c++17 (#include <numeric>)
    numerator /= gcd;
    denominator /= gcd; 
}