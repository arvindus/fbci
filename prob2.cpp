/*
First they did ask to find pattern of this
'this is a test sentence' => [t, h, i, s, i, s, a, t, e, s, t, s, e, n, t, e, n, c, e]
'thiis iss a teest seentennce' => [i, s, e, e, n]
'thiiis iss aa teeest seentennnce' => [i, e, n]
'thiiiis iss a teeest seeentennncccce' => [i, c]
after i have to do body of function
getLongestConsecutiveChar
*/

#include <iostream>
#include <set>
#include <map>
#include <string>

using namespace std;

const int max_int = 100000;
const int min_int = -1;

bool findLongestConsecutiveChar(const string &str, set<char> &setChar)
{
	int max_length = min_int;
	int index_str = 0;
	if (str.length() == 0)
		return false;
	if (str.length() == 1)
	{
		setChar.insert(str[0]);
		return true;
	}
	int curr_seq_length = 1;
	
	while (index_str+1 < str.length())
	{
		if (str[index_str] == ' ')
		{
			index_str++;
			continue;
		}
		if (str[index_str] == str[index_str+1])
		{
			curr_seq_length++;
		}
		else
		{
			if (curr_seq_length > max_length)
			{
				max_length = curr_seq_length;
				setChar.clear();
				setChar.insert(str[index_str]);
			}
			if (curr_seq_length == max_length)
			{
				max_length = curr_seq_length;
				setChar.insert(str[index_str]);
			}
			curr_seq_length = 1;
		}
		index_str++;
	}
	if (curr_seq_length > max_length)
	{
		max_length = curr_seq_length;
		setChar.clear();
		setChar.insert(str[index_str]);
	}
	if (curr_seq_length == max_length)
	{
		max_length = curr_seq_length;
		setChar.insert(str[index_str]);
	}
	if (max_length != min_int)
		return true;
	return false;
}

int main(void)
{
	set<char> setChar;
	string input;
	cout << "Enter string:";
	getline(cin,input);
	if (findLongestConsecutiveChar(input,setChar))
	{
		cout << "chars = [";
		for (auto elem : setChar)
			cout << elem << ",";
		cout << "]\n";
	}
	else
		cout << "char not found!!!\n";
	return 0;
}