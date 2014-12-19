#include <iostream>
#include "templates.h"

int main(void)
{
	stack<int> myStack;
	
	myStack.isEmpty();
	myStack.push(10);
	myStack.push(20);
	myStack.isEmpty();
	int val = myStack.pop();
	cout << "value = " << val << endl;
	myStack.isEmpty();
	val = myStack.pop();
	cout << "value = " << val << endl;
	myStack.isEmpty();
	return 0;
}