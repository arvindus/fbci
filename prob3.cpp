/*
1.) Given an array, find the maximum difference between two array elements given the second element comes after the first. 
For example. 
array = [1,2,3,4,5,6,7] 
We can take the difference between 2 and 1 (2-1), but not the different between 1 and 2 (1-2).
*/

#include <iostream>
#include <vector>

using namespace std;

const int min_int = -1;
const int max_int = 10000000;
int findMaxDifference(const vector<int> &input)
{
	int maxDiff = min_int;
	for (int i = 0; i < input.size()-1; i++)
	{
		for (int j = i+1; j < input.size(); j++)
		{
			int diff = input[j] - input[i];
			if (diff > maxDiff)
			{
				maxDiff = diff;
			}
		}
	}
	return maxDiff;
}

int findMaxDifferenceFaster(const vector<int> &input)
{
	int maxDiff = min_int;
	int minVal = max_int;
	int maxVal = min_int;
	int minValIndex = 0;
	int maxValIndex = 0;
	if (input.size() < 1)
		return -1;
	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] <= minVal)
		{
			minVal = input[i];
			minValIndex = i;
		}
		if (input[i] >= maxVal)
		{
			maxVal = input[i];
			maxValIndex = i;
		}
		if ((input[i]-minVal) > maxDiff)
		{
			maxDiff = input[i] - minVal;
			maxVal = input[i];
			maxValIndex = i;
		}
		if (minValIndex < maxValIndex)
		{
			maxDiff = maxVal - minVal;
		}
		cout << "i = " << i << "and minVal = " << minVal << " and maxVal = ";
		cout << maxVal << "and minValIndex = " << minValIndex << " and maxValIndex = " << maxValIndex;
		cout << " and maxDiff = " << maxDiff << "\n";
	}
	return maxDiff;
}

int main(void)
{
	//vector<int> a {6,7,3,4,10,12,100,81,1,99};
	//vector<int> a = {2,3,10,6,4,8,1};
	vector<int> a = {10,3,6,8,9,4,3};
	cout << "Max difference (faster) = " << findMaxDifferenceFaster(a) << "\n";
	cout << "Max difference = " << findMaxDifference(a) << "\n";
	return 0;
}
