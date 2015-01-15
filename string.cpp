//
//  string.cpp
//  
//
//  Created by arvind sudarsanam on 12/26/14.
//
//

#include "string.h"

/*
 Problem
 Given a test string t and pattern p. Find the first possible match of p in t
 */

/*
 Solution
 Use Knuth-Morris-Pratt algorithm
 */

int longestPrefixAsWellAsSuffix(string &s)
{
    for (int i = s.length() - 1; i > 0; i--)
    {
        string s1 = s.substr(0,i);
        string s2 = s.substr(s.length()-i,i);
        if (s1.compare(s2) == 0)
            return i;
    }
    return 0;
}

int findMatch(string &t, string &p)
{
    int match = -1;
    /* Compute partial value table for pattern */
    vector<int> pvt(p.length());
    
    for (auto elem : pvt)
    {
        elem = 0;
    }
    /*
     find all proper prefix and proper suffix of substring of t[0..i]
     pvt[i] = length of the longest string which is both a proper prefix and proper suffix
     */
    
    for (int i = 1; i <= p.length(); i++)
    {
        string s = p.substr(0,i);
        pvt[i-1] = longestPrefixAsWellAsSuffix(s);
    }
    /*
     during string parsing and matching, if mismatch occurs in ith character of pattern
     then advance by pvt[i-1] if pvt[i-1] > 1, otherwise advance by 1
     */
    string::size_type pos1 = 0;
    string::size_type pos2 = 0;
    while (pos1 != string::npos)
    {
        if (pos1 + p.length() > t.length())
            return -1;
        for (pos2 = 0; pos2 < p.length(); pos2++)
        {
            if (t[pos1+pos2] != p[pos2])
                break;
        }
        if (pos2 == p.length())
        {
            return pos1;
        }
        else
        {
            if (pvt[pos2-1] > 1)
            {
                pos1 = pos1 + pos2 - pvt[pos2-1];
            }
            else
            {
                pos1++;
            }
        }
    }
    return -1;
}

/*
 Problem: Given two strings, compute the minimum edit distance
 */

/*
 function: computeMinEditDistance
 input: strings s1 and s2
 output: med (int)
 */

int computeMinEditDistance(string &s1, string &s2)
{
    int **arr;
    /*
     for substrings s1[1..i] & s2[1..j]
     arr[i][j] holds the med value
     so, the answer we need is arr[s1.length()][s2.length()]
     */
    arr = (int **)(malloc(sizeof(int *)*(s1.length()+1)));
    for (int i = 0; i < s1.length()+1; i++)
    {
        arr[i] = (int *)malloc(sizeof(int)*(s2.length()+1));
    }
    
    /* init arr[0][j] and arr[i][0] with i and j respectively */
    for (int i = 0; i <= s1.length(); i++)
        arr[i][0] = i;
    for (int i = 0; i <= s2.length(); i++)
        arr[0][i] = i;
    
    /* Now iteratively compute arr[i][j]
     arr[i][j] = min(arr[i-1][j]+1, arr[i][j-1], (s1[i] == s2[j] ? arr[i-1][j-1] : arr[i-1][j-1] + 2;
     */
    
    for (int i = 1; i <= s1.length(); i++)
    {
        for (int j = 1; j <= s2.length(); j++)
        {
            int a1 = arr[i-1][j] + 1;
            int a2 = arr[i][j-1] + 1;
            int a3 = arr[i-1][j-1];
            if (s1[i-1] != s2[j-1])
                a3 += 2;
            if ((a1 <= a2) && (a1 <= a3))
                arr[i][j] = a1;
            else
            {
                if (a2 <= a3)
                    arr[i][j] = a2;
                else
                    arr[i][j] = a3;
            }
        }
        
    }
    return arr[s1.length()][s2.length()];
}

int lcs(string &s1, string &s2, int x, int y)
{
    if ((x == 0) || (y == 0))
        return 0;
    if (s1[x-1] == s2[y-1])
        return lcs(s1,s2,x-1,y-1)+1;
    int a1 = lcs(s1,s2,x-1,y);
    int a2 = lcs(s1,s2,x,y-1);
    if (a1 > a2)
        return a1;
    else
        return a2;
}

#include <string>

using std::string;

string longestCommonSubstring(const string& str1, const string& str2)
{
    if(str1.empty() || str2.empty())
    {
        return "";
    }
    string longest("");
    
    for(int i = 0; i<str1.size(); ++i)
    {
        for (int j = 1; j <= str1.size()-i; j++)
        {
            string t1 = str1.substr(i,j);
            for(int k = 0; k<str2.size(); ++k)
            {
                for (int l = 1; l <= str2.size()-k; l++)
                {
                    string t2 = str2.substr(k,l);
                    if (t1.compare(t2) == 0)
                        if (longest.length() < t1.length())
                            longest = t1;
                }
            }
        }
    }
    return longest;
}

bool isAnAlphabet(const char c)
{
    if ((c >= 'a') && (c <= 'z'))
        return true;
    else
        return false;
}

char toLower(const char c)
{
    if (c < 'a')
        return c + 32;
    else
        return c;
}

bool isAPalindrome(string str, int start, int end)
{
    if (start >= end)
        return true;
    char c1,c2;
    do
    {
        c1 = toLower(str[start]);
        start++;
    }
    while (!isAnAlphabet(c1) && (start < str.size()));
    
    do
    {
        c2 = toLower(str[end]);
        end--;
    }
    while (!isAnAlphabet(c2) && (end > 0));
    if (c1 == c2)
        return isAPalindrome(str,start,end);
    else
        return false;
}

int main()
{
    /*stringlist mylist;
    mylist.insert("Arvind");
    mylist.insert("Vaidehi");
    mylist.insert("aaa");
    mylist.insert("bbbbbbbbbbbb");
    mylist.print();
    mylist.mysort();
    mylist.print();*/
    string s2("ababx");
    string s1("aabacababacc");
    
    cout << findMatch(s1,s2) << "\n";
    
    string s3("vaindeh");
    string s4("arvindexx");
    //cout << computeMinEditDistance(s3,s4) << "\n";
    
    cout << lcs(s3,s4,7,6) << "\n";
    cout << longestCommonSubstring(s3,s4) << "\n";
    
    string s5("waterbottle");
    string s6("terbottlewa");
    string s7 = longestCommonSubstring(s5,s6);
    s5.replace(s5.find(s7),s7.length(),"");
    s6.replace(s6.find(s7),s7.length(),"");
    if (s5.compare(s6) == 0)
        cout << "is a rotated value\n";
    
    string s8("racEcAr!!!!");
    
    cout << isAPalindrome(s8,0,s8.size()-1) << "\n";
    return 0;
}