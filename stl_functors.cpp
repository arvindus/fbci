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
	int operator() () { return rand() % (max-min+1) + min; }
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

// Create a new vector to hold 100 strings. Use another Generator that you write to fill it with 100 random alphabetic strings of random lengths between 5 and 15 characters inclusive.
// Sort the vector you've made using the version of sort that applies operator< to the vector. Display this sorted vector in a similar fashion to the way you displayed exercise 1's result.
// Then, re-sort the vector by length of string (ascending). You'll want to use a comparator that conforms to the Strict Weak Ordering model. Output your re-sorted vector to stdout.

class my_random_string_generator
{
public:
    my_random_string_generator(int a, int b) : minlength(a), maxlength(b) {}
    string operator() ()
    {
        int randlength = rand() % (maxlength-minlength+1) + minlength;
        string str;
        for (int i = 0; i < randlength; i++)
            str += rand() % ('z' - 'a' + 1) + 'a';
        return str;
    }
private:
    int minlength;
    int maxlength;
};

class my_less
{
public:
    bool operator() (string s1, string s2) { return s1.length() < s2.length(); }
};


int func3(void)
{
    vector<string> strlist(10);
    my_random_string_generator mrsg(5,15);
    my_less ml;
    generate(strlist.begin(), strlist.end(), mrsg);
    cout << "AFTER GENERATION:\n";
    copy(strlist.begin(), strlist.end(), ostream_iterator<string>(cout, "\n"));
    sort(strlist.begin(), strlist.end());
    cout << "AFTER FIRST SORT:\n";
    copy(strlist.begin(), strlist.end(), ostream_iterator<string>(cout, "\n"));
    sort(strlist.begin(), strlist.end(), ml);
    cout << "AFTER SECOND SORT:\n";
    copy(strlist.begin(), strlist.end(), ostream_iterator<string>(cout, "\n"));
    return 0;
}

int main(void)
{
	//func1();
	//func2();
    func3();
	return 0;
}