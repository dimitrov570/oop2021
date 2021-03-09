#include <iostream>
#include "Vector.hpp"

using namespace std;

int main()
{
	Vector vect(4);
	Vector copy = vect;

	cout << copy.getSize() << endl;

	return 0;
}