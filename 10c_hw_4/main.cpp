#include "bin_tree.h"
/*
	HW #4
	Cameron Sowers
	UID: 404766299
	
	Honesty Pledge: "I pledge that I have neither given nor received unauthorized assistance on this assignment."
*/

/*
	 The main function creates vectors of three different types: int, double, string.
	 The vector of doubles is ordered from greatest to least, and must be specified as different from the default ordering.
	 It calls binary_search() which outputs the index location of the specified value.
*/
int main()
{
	std::vector<int> vi = { 1,3,5,10,19 };
	std::vector<double> vd = { 3.14,2.7,2.54,0.19 };
	more<double> dd;									//template class object
	std::vector<std::string> vs = { "one","two", "zero" };
	std::string two = "two";

	std::cout << binary_search(vi, 0, vi.size(), 10);			//outputs index where 10 is located
	std::cout << binary_search(vd, 0, vd.size(), 2.7, dd);		//outputs index where 2.7 is located
	std::cout << binary_search(vs, 0, vs.size(), two);			//outputs index where "two" is located

	//this code should output: 311

	return 0;
}