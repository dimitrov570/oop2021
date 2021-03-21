#include "Rational.hpp"
#include <numeric>

int a = 6;

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

Rational Rational::operator+(int x) const
{
        return Rational(numerator + denominator*x, denominator);
}

Rational& Rational::operator++()
{
    numerator += denominator;
    return *this;
}

Rational Rational::operator++(int)
{
    Rational r = *this; //запазва се старата стойност
    numerator += denominator; //променя се стойността
    return r; //връща се старата стойност
}

Rational::operator double() const 
{
         return (double)numerator / denominator;
}

Rational Rational::operator-() const
{
    return Rational(-numerator, denominator);
}

Rational operator+(int x, const Rational& r)
{
    return Rational(r.getNumerator() + r.getDenominator()*x, r.getDenominator());
}



void Rational::simplify()
{
    int gcd = std::gcd(numerator, denominator); //available from c++17 (#include <numeric>)
    numerator /= gcd;
    denominator /= gcd; 
}