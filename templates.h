#ifndef _TEMPLATES_H
#define _TEMPLATES_H

#include <vector>
#include <iostream>

#define BADVALUE -1

using namespace std;
template <class T>
class stack 
{
public:
	void push(T val);
	T pop();
	bool isEmpty();
private:
	vector<T> mStack;
};

// explicit specialization


template <>
bool stack<int>::isEmpty(void)
{
	if (mStack.empty())
		cout << "Stack is empty" << endl;
	else 
		cout << "Stack is not empty" << endl;
	return mStack.empty();
}

template <>
void stack<int>::push(int val)
{
	cout << "Pushing " << val << endl;
	mStack.push_back(val);
}

template <>
int stack<int>::pop(void)
{
	if (isEmpty())
		return BADVALUE;
	int val = mStack.back();
	mStack.pop_back();
	cout << "Popping " << val << endl;
	return val;
}


#endif