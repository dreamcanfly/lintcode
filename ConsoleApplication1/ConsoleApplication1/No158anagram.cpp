// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <map>
using namespace std;

class Solution {
public:
	/**
	* @param s: The first string
	* @param b: The second string
	* @return true or false
	*/
	int GetCharNum(char myChar)
	{
		return 2 << (myChar - 'a');
	}

	bool anagram(string s, string t) 
	{
		// write your code here
		int s_len = s.length();
		int t_len = t.length();
		if (s_len != t_len)
		{
			return false;
		}
		int sNum = 0;
		int tNum = 0;
		for (int i = 0; i < s_len; i++)
		{

			sNum += GetCharNum(s[i]);
		}
		for (int i = 0; i < t_len; i++)
		{
			tNum += GetCharNum(t[i]);
		}
		if (sNum == tNum) return true;
		else
		{
			return false;
		}
	}
};

//int main()
//{
//	Solution s;
//	cout << s.anagram("abcd", "dcab") << endl;
//	cout << s.anagram("abcd", "ccab") << endl;
//    return 0;
//}

