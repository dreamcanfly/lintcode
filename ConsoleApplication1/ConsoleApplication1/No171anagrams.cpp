#include "stdafx.h"
#include <map>
#include <string>
using namespace std;

class Solution {
public:
	/**
	* @param strs: A list of strings
	* @return: A list of strings
	*/
	vector<string> anagrams(vector<string> &strs) 
	{
		// write your code here
		int size = strs.size();
		vector<string> vec;
		if (size <= 1) return vec;
		map<string, vector<string>> myMap;
		for (int i = 0; i < size; i++)
		{
			myMap[GetCharNum(strs[i])].push_back(strs[i]);
		}
		for (map<string, vector<string>>::iterator iter = myMap.begin(); iter != myMap.end(); iter++)
		{
			if (iter->second.size() > 1)
			{
				for (int i = 0; i < iter->second.size(); i++)
				{
					vec.push_back(iter->second[i]);
				}
			}
		}
		return vec;
	}
	string GetCharNum(string str)
	{
		map<char, int> myMap;
		for (int i = 0; i < str.size(); i++)
		{
			myMap[str[i]]++;
		}
		string result;
		for (map<char, int>::iterator iter = myMap.begin(); iter != myMap.end(); iter++)
		{
			result += iter->first;
			result += (iter->second + '0');
		}
		return result;
	}
};


//int main()
//{
//	Solution s;
//	vector<string> strs = { "tea","","eat","","tea","" };
//	vector<string> result = s.anagrams(strs);
//	for (vector<string>::iterator iter = result.begin(); iter != result.end(); iter++)
//	{
//		cout << (*iter) << ",";
//	}
//	return 0;
//}