//
//  trial.cpp
//  
//
//  Created by arvind sudarsanam on 1/10/15.
//
//

#include <iostream>
#include <vector>

using namespace std;

void calcSequence(vector<int> &curr, vector<int> &next)
{
    int count = 1;
    for (int i = 0; i < curr.size(); i++)
    {
        //cout << i << "\n";
        if (curr[i] == curr[i+1])
        {
            count++;
        }
        else
        {
            next.push_back(count);
            next.push_back(curr[i]);
            count = 1;
        }
    }
    return;
}

int main(void)
{
    vector<int> curr,next;
    int num;
    cout << "Enter number:";
    cin >> num;
    if (num <= 0)
    {
        cout << "Invalid input\n";
        return 1;
    }
    curr.push_back(1);
    for (int i = 2; i <= num; i++)
    {
        calcSequence(curr, next);
        curr.resize(next.size());
        copy(next.begin(), next.end(), curr.begin());
        next.clear();
    }
    copy(curr.begin(),curr.end(),ostream_iterator<int>(cout, ","));
    cout << "\n";
    return 0;
}
