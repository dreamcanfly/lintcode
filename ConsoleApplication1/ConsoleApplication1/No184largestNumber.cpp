#include "stdafx.h"
#include <bitset>
#include <algorithm>
using namespace std;

class Solution {
public:
	/**
	*@param num: A list of non negative integers
	*@return: A string
	*/
	string largestNumber(vector<int> &num)
	{
		// write your code here
		int size = num.size();
		if (size <= 0) return "";
		if (size == 1) return to_string(num[0]);
		vector<string> numStr;
		ChangeNumsToStrs(num, numStr);
		sort(numStr.begin(), numStr.end(), cmp);
		string result = numStr[0];
		for(int i = 1; i < size; i++)
		{
			if(numStr[i] == numStr[i - 1] && numStr[i] == "0")
				continue;
			result += numStr[i];
		}
		return result;
	}
	
	static bool cmp(string a1, string a2)
	{
		if (a1 == a2) return false;
		auto len1 = a1.length();
		auto len2 = a2.length();
		auto len = len1 > len2 ? len2 : len1;
		auto i = 0;
		for(; i < len; i++)
		{
			if (a1[i] > a2[i])
				return true;
			if (a1[i] < a2[i])
				return false;
		}
		if(i == len1)
		{
			if (a2[i] >= a2[0])
				return false;
			return true;
		}
		
		if(i == len2)
		{
			if (a1[i] > a1[0])
				return true;
			return false;
		}

		return false;
	}

	void ChangeNumsToStrs(vector<int> &num, vector<string> &numStr)
	{
		int size = num.size();
		if (size <= 0) return;
		for(auto i : num)
		{
			//string temp = ChangeNumToStr(i);
			//if (temp != "")
			//	numStr.push_back(temp);
			numStr.push_back(to_string(i));
		}
	}

	string ChangeNumToStr(int num)
	{
		if (num == 0) return "0";
		string str = "";
		while (num > 0)
		{
			str = (char(num % 10 + '0') + str);
			num /= 10;
		}
		return str;
	}
};

//int main()
//{
//	vector<int> nums ={0, 0};
//	Solution s;
//	cout << s.largestNumber(nums);
//	return 0;
//}