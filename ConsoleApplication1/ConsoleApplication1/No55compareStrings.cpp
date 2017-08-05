#include "stdafx.h"
#include <map>
using namespace std;

class Solution {
public:
	/**
	* @param A: A string includes Upper Case letters
	* @param B: A string includes Upper Case letter
	* @return:  if string A contains all of the characters in B return true
	*           else return false
	*/
	bool compareStrings(string A, string B) 
	{
		// write your code here
		int ALen = A.length();
		int BLen = B.length();
		if (BLen > ALen) return false;
		static map<char, int> myMap;
		for (int i = 0; i < BLen; i++)
		{
			if (myMap.find(B[i]) == myMap.end())
				myMap[B[i]] = 1;
			else
			{
				myMap[B[i]]++;
			}
		}
		for (int i = 0; i < ALen; i++)
		{
			if (myMap.find(A[i]) != myMap.end())
			{
				myMap[A[i]]--;
			}
		}
		for (map<char, int>::iterator iter = myMap.begin(); iter != myMap.end(); iter++)
		{
			if (iter->second > 0) return false;
		}
		return true;
	}
};

//int main()
//{
//	Solution s;
//	cout << s.compareStrings("ABD", "ACD");
//	return 0;
//}