// Solving http://courses.cms.caltech.edu/cs11/material/advcpp/lab1/index.html
// First implementation using STL, and function objects

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <iterator>
#include <functional>

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

// Generate a vector of 100 random integers between 1 and 100, as before,
// then write some code to count how many of these numbers are odd and how many are even, in a single pass over the integers.
// Do this by creating a simple function object that implements the unary_function model, and that maintains some internal state.
// You should then be able to apply it with the for_each algorithm and then extract the counts at the end.

class count_odd_even
{
public:
    count_odd_even() : count_odd(0), count_even(0) {}
    void operator() (int a)
    {
        count_odd = count_odd + (a % 2);
        count_even = count_even + ((a+1)%2);
    }
    int get_count_odd() { return count_odd; }
    int get_count_even() { return count_even; }
private:
    int count_odd;
    int count_even;
};

int func4(void)
{
    vector<int> v(10);
    my_random_number_generator mrng(1,10);
    count_odd_even coe;
    generate(v.begin(), v.end(), mrng);
    cout << "AFTER GENERATION\n";
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, "\n"));
    coe = for_each(v.begin(), v.end(), coe);
    cout << " count_odd = " << coe.get_count_odd() << "\ncount_even = " << coe.get_count_even() << "\n";
    return 0;
}

// what you think the author of this code intended it to do,
// why this code is broken (what does it do?),
// how you've fixed it.
// Of course, actually fix the code, compile, and verify that it works the way it was probably meant to work.
int func5(void)
{
    vector<int> v;
    v.push_back(1);
    v.push_back(4);
    v.push_back(2);
    v.push_back(8);
    v.push_back(5);
    v.push_back(7);
    
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    return 0;
}

// Now you can try your hand at writing a simple STL algorithm. You will create your own version of the reverse() algorithm in a file exercise5.cc. This algorithm must be implemented as a function template (which we will discuss in a future class), declared like this:

template <typename BidirectionalIterator>
void my_reverse(BidirectionalIterator first, BidirectionalIterator last)
{
    BidirectionalIterator it1 = first;
    BidirectionalIterator it2 = last;
    while (it1 < it2)
    {
        it2--;
        swap(*it1,*it2);
        it1++;
    }
}

int func6(int size)
{
    vector<int> v(size);
    my_random_number_generator mrng(1,100);
    generate(v.begin(), v.end(), mrng);
    cout << "AFTER GENERATE\n";
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << "\n";
    my_reverse(v.begin(), v.end());
    cout << "AFTER REVERSE\n";
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << "\n";
    return 0;
}

int main(void)
{
	//func1();
	//func2();
    //func3();
    //func4();
    //func5();
    func6(7);
	return 0;
}