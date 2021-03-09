#include "Vector.hpp"
#include <iostream>

const int INITIAL_SIZE = 2;

//delegate constructor, we're basically telling the default constructor to call the int-constructor with the default parameter
//we've chosen this strategy because virtually, a Vector will always need some size to start with in order to allocate the dynamic memory
Vector::Vector() : Vector::Vector(INITIAL_SIZE) {}

Vector::Vector(int Size) : size(Size), lastIndex(-1)
{
	allocateResourceMemory();
}

Vector::Vector(const Vector& other) : size(other.size), lastIndex(other.lastIndex)
{
	allocateResourceMemory();

	for (int i = 0; i < size; i++)
	{
		data[i] = other.data[i];
	}
}

Vector::~Vector()
{
	delete[] data;
}

int Vector::getSize() const
{
	return size;
}

int Vector::getAt(int index) const
{
	if (0 < index || index >= lastIndex)
	{
		std::cerr << "Invalid index" << index << " passed! Biggest possible index is " << lastIndex << '\n';
		return -1;
	}

	return data[index];
}

int Vector::first() const
{
	return 0;
}

int Vector::last() const
{
	return 0;
}

bool Vector::setAt(int, int)
{
	return false;
}

bool Vector::push_back(int)
{
	return false;
}

int Vector::pop_back()
{
	return 0;
}

void Vector::allocateResourceMemory()
{
	data = new int[size];
}

void Vector::shrink()
{
}

void Vector::expand()
{
}
