// Solving http://courses.cms.caltech.edu/cs11/material/advcpp/lab1/index.html
// First implementation using STL, and function objects

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;
class my_functor
{
public:
	void operator() (string s) { cout << "my_functor says: " << s << endl; }
};

int func1(void)
{
	my_functor f;
	f("hello world");
	return 0;
}

// Create a vector of 100 ints. 
// Fill it with 100 small, random integers between 1 and 100, inclusive, by using the appropriate mutating algorithm. 
// Generate these numbers by passing the mutating algorithm a function object (or perhaps a simple function) that models a Generator. 
// Your function object should use rand() and the modulo operator, at least.
// Since it would be nice to verify your code is working, 
// use the copy algorithm to write your vector to cout via an ostream_iterator parameterized on ints.

class my_random_number_generator
{
public:
	my_random_number_generator(int a, int b) : min(a), max(b) {}
	int operator() () { return rand() % max + min; }
private:
	int min;
	int max;
};

int func2(void)
{
	my_random_number_generator mrng(1,10);
	vector<int> v(10);
	cout << "size of v = " << v.size() << endl;
	
	generate(v.begin(), v.end(), mrng);
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, "\n"));
	return 0;
}

int main(void)
{
	func1();
	func2();
	return 0;
}