/*
You are given a set of unique characters and a string. 
Find the smallest substring of the string containing all the characters in the set. 
ex: 
Set : [a, b, c] 
String : "abbcbcba" 
Result: "cba"
*/

#include <iostream>
#include <set>
#include <map>
#include <string>

using namespace std;

const int max_int = 100000;
const int min_int = -1;
bool findSmallestSubString(const set<char> &setChar, const string &str, string &substring)
{
	int min_length = max_int;
	map<char, bool> isCharPresent;
	for (auto elem : setChar)
		isCharPresent[elem] = false;
	int start_substr = 0;
	int index_substr = 0;
	int min_start_substr = 0;
	int index_str = start_substr + index_substr;
	while (index_str < str.length())
	{
		index_str = start_substr + index_substr;
		if (setChar.find(str[index_str]) != setChar.end())
		{
			isCharPresent[str[index_str]] = true;
			bool allCharsPresent = true;
			for (auto elem : isCharPresent)
				if (elem.second == false)
				{
					allCharsPresent = false;
					break;
				}
			if (allCharsPresent)
			{
				if (min_length > index_substr)
				{
					min_length = index_substr;
					min_start_substr = start_substr;
				}
				for (auto elem : setChar)
					isCharPresent[elem] = false;
				index_substr = 0;
				start_substr++;
			}
			else
			{
				index_substr++;
			}
		}
		else
		{
			index_substr++;
		}
	}
	if (min_length != max_int)
	{
		substring = str.substr(min_start_substr, min_length+1);
		return true;
	}
	else
		return false;
}

bool findLongestConsecutiveChar(const set<char> &setChar, const string &str, char &ch)
{
	int max_length = min_int;
	int index_str = 0;
	if (str.length() == 0)
		return false;
	if (str.length() == 1)
	{
		ch = str[0];
		return true;
	}
	int curr_seq_length = 1;
	
	while (index_str+1 < str.length())
	{
		if (setChar.find(str[index_str]) != setChar.end())
		{
			if (str[index_str] == str[index_str+1])
			{
				curr_seq_length++;
			}
			else
			{
				if (curr_seq_length > max_length)
				{
					max_length = curr_seq_length;
					ch = str[index_str];
				}
				curr_seq_length = 0;
			}
		}
		index_str++;
	}
	if (max_length != min_int)
		return true;
	return false;
}

int main(void)
{
	string input, substring;
	set<char> setChar;
	char ch;
	setChar.insert('a');
	setChar.insert('b');
	setChar.insert('c');
	cout << "Enter string:";
	cin >> input;
	if (findSmallestSubString(setChar, input, substring))
	{
		cout << "substr = " << substring << "\n";
	}
	else
		cout << "substr not found!!!\n";
	if (findLongestConsecutiveChar(setChar, input, ch))
	{
		cout << "ch = " << ch << "\n";
	}
	else
		cout << "char not found!!!\n";
	return 0;
}