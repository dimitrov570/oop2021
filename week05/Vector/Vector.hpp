#pragma once
#include <ostream>

class Vector
{
private:
	int* data;
	unsigned int size;
	int lastIndex;

public:
	
	// Constructors
	Vector();
	Vector(unsigned int);
	Vector(const Vector& other);
	~Vector();

	int getAt(int) const;
	int getLast() const;
	int getSize() const;
	unsigned int getNumberOfElements() const;
	bool isEmpty() const;
	bool isFull() const;


	bool setAt(int index, int value);
	bool push_back(int);
	
	// by returning int& you can write directly to the data array like: vec[i] = 5;
	int& operator[](int) const;

	int pop_back();
	void push_back();

	friend std::ostream& operator<<(std::ostream& o, const Vector& vector);

private:
	bool indexIsInRange(int);
	void shrink();
	void expand();
};