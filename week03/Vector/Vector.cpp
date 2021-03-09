#include "Vector.hpp"
#include <iostream>

const int INITIAL_SIZE = 2;

Vector::Vector() : size(INITIAL_SIZE), lastIndex(-1) {
	data = new int[size];
}

Vector::Vector(int Size) : size(Size), lastIndex(-1)
{
	data = new int[size];
}

Vector::Vector(const Vector& other) : size(other.size), lastIndex(other.lastIndex)
{
	data = new int[size];

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
	//TODO
	return 0;
}

int Vector::last() const
{
	//TODO
	return 0;
}

bool Vector::setAt(int, int)
{
	//TODO
	return false;
}

bool Vector::push_back(int)
{
	//TODO
	return false;
}

int Vector::pop_back()
{
	//TODO
	return 0;
}

void Vector::shrink()
{
	//TODO
}

void Vector::expand()
{
	//TODO
}
