//
//  simple.cpp
//  
//
//  Created by arvind sudarsanam on 2/12/15.
//
//

#include "simple.h"

using namespace std;

void swap(int &a, int &b)
{
    a = a + b;
    b = a - b;
    a = a - b;
    return;
}

int max(int a, int b)
{
    
}

int main(void)
{
    int a = 10;
    int b = 20;
    cout << "Enter a:";
    cin >> a;
    cout << "Enter b:";
    cin >> b;
    cout << "Original order = " << a << " and " << b << "\n";
    swap(a,b);
    cout << "New order = " << a << " and " << b << "\n";
    return 0;
}