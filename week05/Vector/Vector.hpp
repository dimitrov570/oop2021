#pragma once
#include <ostream>

class Vector
{
private:
	int* data;
	unsigned int size;
	int lastIndex;

public:
	
	Vector();
	Vector(unsigned int);
	Vector(const Vector& other);
	Vector& operator=(const Vector& rhs);
	~Vector();

	int getAt(int) const;
	int getLast() const;
	int getSize() const;
	unsigned int getNumberOfElements() const;
	bool isEmpty() const;
	bool isFull() const;

	bool setAt(int index, int value);
	void push_back(int);
	int pop_back();
	
	// by returning int& you can write directly to the data array like: vec[i] = 5;
	int& operator[](int) const;

	friend std::ostream& operator<<(std::ostream& o, const Vector& vector);

private:
	bool indexIsInRange(int);
	void shrink();
	void expand();
};