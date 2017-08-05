#include "stdafx.h"
#include <string>
using namespace std;

class Solution {
public:
	/**
	* @param strs: A list of strings
	* @return: The longest common prefix
	*/
	string longestCommonPrefix(vector<string> &strs) 
	{
		// write your code here
		int size = strs.size();
		if (size <= 0) return "";
		if (size == 1) return strs[0];
		int CPlen = 0;
		for (int i = 0; i < strs[0].length(); i++)
		{
			bool isSame = true;
			for (int j = 1; j < size; j++)
			{
				if (i >= strs[j].length() || strs[j][i] != strs[0][i])
				{
					isSame = false;
				}
			}
			if (isSame == true) CPlen++;
			else
			{
				return strs[0].substr(0, CPlen);
			}
		}
		return strs[0];
	}
};


//int main()
//{
//	Solution s;
//	vector<string> strs = { "ABCDEFG", "ABCEFG", "ABCEFA" };
//	cout << s.longestCommonPrefix(strs);
//	return 0;
//}