#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch2.hpp"
#include "functions.hpp"
#include <iostream>

TEST_CASE("Testing add with small number")
{
    //ARRANGE
    int a = 3;
    int b = 4;
    int expected = 7;

    //ACT
    int result = add(a, b);

    //ASSERT
    REQUIRE(result == expected);
}

TEST_CASE("Testing add with big numbers")
{
    //ARRANGE
    int a = 2147483647;
    int b = 4;
    long expected = 2147483651;

    //ACT
    int result = add(a, b);

    //ASSERT
    REQUIRE(result == expected);
}


TEST_CASE("Testing multiply with small number")
{
    //ARRANGE
    int a = 3;
    int b = 4;
    int expected = 12;

    //ACT
    int result = multiply(a, b);

    //ASSERT
    REQUIRE(result == expected);
}

TEST_CASE("Testing multiply with 0")
{
    //ARRANGE
    int a = 3;
    int b = 0;
    int expected = 0;

    //ACT
    int result = multiply(a, b);

    //ASSERT
    REQUIRE(result == expected);
}