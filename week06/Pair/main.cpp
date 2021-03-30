#include <iostream>
#include "Pair.hpp"

using namespace std;

int main()
{
    Pair<int, double> p(1, 2.5);
    cout << p << endl;

    bool isLess = p < Pair<int, double>(0, 2.);
    cout << isLess << endl;

    return 0;
}
