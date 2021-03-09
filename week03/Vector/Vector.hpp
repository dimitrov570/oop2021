#pragma once

class Vector
{
private:
	int* data;
	int size;
	int lastIndex;

public:
	/*
	* Constructors
	*/
	Vector();
	Vector(int);
	Vector(const Vector& other);
	~Vector();

	/*
	* Getters
	*/
	int getSize() const;

	int getAt(int) const;
	int first() const;
	int last() const;

	/*
	* Setters
	*/
	bool setAt(int, int);
	bool push_back(int);
	
	int pop_back();

private:
	void shrink();
	void expand();
};
