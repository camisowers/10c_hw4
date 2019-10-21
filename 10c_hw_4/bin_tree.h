#pragma once
#include <vector>
#include <string>
#include <iostream>

/*
	Creates template class object less<T>.
	Stores no values, but allows the object to use the () operator to return a bool value.
	Will be used as as a default condition.
*/
template<typename T>
class less
{
public:
	bool operator() (const T& x, const T&y) const { return x < y; }			//returns true if x is less than y
};

/*
	Creates template class object more<T>.
	Similar to less<T>, but used for reverse ordering (greatest to least). 
*/
template<typename T>
class more
{
public:
	bool operator() (const T& x, const T&y) const {	return x > y; }			//returns true if x is more than y
};


/*
	The binary_search() function has been rewritten with templates so it can take a vector of any data type.
	@param: vector<T>, 3 template values of the same type T, default less<T>
	@return: int
*/
template<typename T, typename order = less<T>>
int binary_search(std::vector<T> v, const int from, const int to, T value, order smaller = order())
{
	if (from > to)			//checks valid index inputs
	{
		std::cout << "\nInvalid parameters.";
		return -1;
	}
	int mid = (from + to) / 2;				//middle value
	if (v[mid] == value)					//if value is in middle, return that index
		return mid;
	else if (smaller(v[mid], value))		//if middle value is < value we want to find, use the first half of the vector
		return binary_search(v, mid + 1, to, value, smaller);		//add smaller as parameter
	else									//if middle value is < value we want to find, use the second half of the vector
		return binary_search(v, from, mid - 1, value, smaller);
}
