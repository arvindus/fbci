//
//  leadingzeros.cpp
//  
//
//  Created by arvind sudarsanam on 2/12/15.
//
//

#include <iostream>

using namespace std;

long long int factorial(int n)
{
    long long int fact = 1;
    if (n < 0)
    {
        cout << "factorial not valid for negative numbers\n";
        return -1;
    }
    if ((n == 0) || (n == 1))
    {
        return 1;
    }
    return n*factorial(n-1);
}

int goldenLeadingZeros(int n)
{
    long long int fact = factorial(n);
    cout << "Factorial of " << n << " is " << fact << "\n";
    int numZeros = 0;
    while (fact >= 10)
    {
        if (fact % 10)
            break;
        numZeros++;
        fact = fact/10;
    }
    cout << "Golden numZeros of fact of " << n << " is " << numZeros << "\n";
    return numZeros;
}

int leadingZeros(int n)
{
    if (n < 0)
    {
        cout << "factorial not valid for negative numbers\n";
        return -1;
    }
    int powerOfFive = 5;
    int numZeros = 0;
    while (powerOfFive < n)
    {
        numZeros += n/powerOfFive;
        powerOfFive *= 5;
    }
    cout << "Computed numZeros of fact of " << n << " is " << numZeros << "\n";
    return numZeros;
}

int main(void)
{
    int n;
    cout << "Enter n:";
    cin >> n;
    int numZeros = leadingZeros(n);
    int GoldenNumZeros = goldenLeadingZeros(n);
    return 0;
}

