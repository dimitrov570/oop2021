#include "Vector.hpp"
#include <iostream>
#include <string>

const int INITIAL_SIZE = 2;

// when vector is full increase size EXPAND_COEFFICIENT times
const int EXPAND_COEFFICIENT = 2; 

// when condition for shrink is true decrease size SHRINK_COEFFICIENT times
const int SHRINK_COEFFICIENT = 2; 

const std::string EMPTY_VECTOR_MESSAGE = "Vector is empty! Returning 0.";

Vector::Vector() : size(INITIAL_SIZE), lastIndex(-1) {
	data = new int[size];
}

Vector::Vector(unsigned int _size) : lastIndex(-1)
{
	if (_size == 0)
	{
		std::cerr << "Size must be positive integer value! Setting size to: " << INITIAL_SIZE << '\n';
		size = INITIAL_SIZE;
	}
	else
	{
		size = _size;
	}

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

int Vector::getAt(int index) const
{
	if (0 < index || index > lastIndex)
	{
		std::cerr << "Index: " << index << " is out of range! Possible range: [" << 0 << "-" << lastIndex << "]\n";
		return -1;
	}

	return data[index];
}

int Vector::getLast() const
{
	if (isEmpty())
	{
		std::cerr << EMPTY_VECTOR_MESSAGE << '\n';
		return 0;
	}
	return data[lastIndex];
}

int Vector::getSize() const
{
	return size;
}

bool Vector::isEmpty() const
{
	return size == 0;
}

unsigned int Vector::getNumberOfElements() const
{
	return lastIndex + 1;
}

bool Vector::isFull() const
{
	return lastIndex == size - 1;
}

bool Vector::setAt(int index, int value)
{
	if (indexIsInRange(index))
	{
		data[index] = value;
		return true;
	}

	return false;
}

void Vector::push_back(int value)
{
	if (isFull()) // if there is no space left to add, increase vector size
	{
		expand();
	}

	data[++lastIndex] = value;
}

int Vector::pop_back()
{
	if (isEmpty())
	{
		std::cerr << EMPTY_VECTOR_MESSAGE << '\n';
		return 0;
	}

	
	// if vector size decreased to 1/4 of the maximum size (lastIndex <= size/4)
	// then shrink it to half size 	
	
	if(lastIndex < size / (SHRINK_COEFFICIENT * SHRINK_COEFFICIENT))
	{
		shrink();
	}

	return data[lastIndex--]; //return value stored at lastIndex, and then decrement lastIndex (postfix)
}

bool Vector::indexIsInRange(int index)
{
	return index >= 0 && index <= lastIndex;
}

void Vector::shrink()
{
	int newSize = size / SHRINK_COEFFICIENT;

	int *newDataArray = new int[newSize]; //create new array to store values
	
	// copy values in new array
	for (int i = 0; i <= lastIndex; ++i)
	{
		newDataArray[i] = data[i];
	}

	// free memory allocated for old (larger) data array
	delete[] data;
	size = newSize;

	// set data pointer to point to new array with values
	data = newDataArray;
}

void Vector::expand()
{
	int newSize = size * EXPAND_COEFFICIENT;

	int *newDataArray = new int[newSize];

	// copy values in new array
	for (int i = 0; i <= lastIndex; ++i)
	{
		newDataArray[i] = data[i];
	}

	// free memory allocated for old (smaller) data array
	delete[] data;

	size = newSize;

	// set data pointer to point to new array with values
	data = newDataArray;
}


std::ostream& operator<<(std::ostream& o, const Vector& vector)
{
	if (vector.isEmpty())
	{
		return o << "Vector is empty!";
	}

	for (int i = 0; i <= vector.lastIndex; ++i)
	{
		o << i << ": " << vector.data[i] << '\n';
	}

	return o;
}