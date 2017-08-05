#include "stdafx.h"
#include <limits>
using namespace std;

class Solution {
public:
	/**
	* @param str: A string
	* @return An integer
	*/
	int atoi(string str) 
	{
		// write your code here
		int len = str.length();
		if (len <= 0) return 0;
		int s = str.find_first_not_of(" ");
		int e = str.find_last_not_of(" ");
		str = str.substr(s, e - s + 1);
		int RetInteger = 0;
		bool IsPosNum = true;
		int i = 0;

		if (str[0] == '-')
			IsPosNum = false;
		if (str[0] == '+' || str[0] == '-')
			i = 1;
		while (i < len)
		{
			if (str[i] >= '0' && str[i] <= '9')
			{
				if (IsPosNum && RetInteger > (INT_MAX - (str[i] - '0')) / 10) return INT_MAX;
				if (!IsPosNum && RetInteger > (INT_MAX - (str[i] - '0')) / 10) return INT_MIN;
				RetInteger = RetInteger * 10 + (str[i] - '0');
			}
			else
			{
				break;
			}
			i++;
		}
		if (!IsPosNum)
			RetInteger = -RetInteger;
		return RetInteger;
	}
};

//int main()
//{
//	Solution s;
//	cout << s.atoi("2147483649") << endl;
//	return 0;
//}