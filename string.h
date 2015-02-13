//
//  string.h
//  
//
//  Created by arvind sudarsanam on 12/26/14.
//
//

#ifndef ____string__
#define ____string__

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class comparestring
{
public:
    bool operator() (string a, string b)
    {
        if (a.size() < b.size())
            return true;
        else
            return false;
    }
};

class stringlist
{
private:
    vector<string> slist;
    comparestring mycompare;
public:
    void insert(string s)
    {
        slist.push_back(s);
    }
    string operator[](int i) { return slist[i]; }
    
    
    void mysort()
    {
        sort(slist.begin(), slist.end());
    }
    void print()
    {
        cout << "list of strings\n";
        copy(slist.begin(), slist.end(), ostream_iterator<string>(cout, "\n"));
        cout << "**************\n";
    }
};


#endif /* defined(____string__) */
