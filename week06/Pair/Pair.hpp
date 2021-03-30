#pragma once
#include <ostream>

template <typename T1, typename T2>
struct Pair;

template<typename T1, typename T2>
std::ostream& operator<<(std::ostream& o, const Pair<T1, T2>& p);

template <typename T1 = int, typename T2 = int>
struct Pair
{
	T1 first;
	T2 second;

	Pair(T1 first, T2 second) : first(first), second(second) {}

	bool operator<(const Pair&) const;

	friend std::ostream& operator<< <> (std::ostream&, const Pair&);
};

template<typename T1, typename T2>
bool Pair<T1, T2>::operator<(const Pair& other) const
{
	return first < other.first && second < other.second;
}

template<typename T1, typename T2>
std::ostream& operator<<(std::ostream& o, const Pair<T1, T2>& p)
{
	return o << p.first << ": " << p.second;
}
