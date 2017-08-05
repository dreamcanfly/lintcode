#include "stdafx.h"
using namespace std;

class Solution {
public:
	/*
	* @param n: An integer
	* @return: True or false
	*/
	bool checkPowerOf2(int n)
	{
		// write your code here
		if (n <= 0) return false;
		if ((n & (n - 1)) == 0)
			return true;
		else
			return false;
	}
};

//int main()
//{
//	int n = 8;
//	Solution s;
//	cout << s.checkPowerOf2(n);
//	return 0;
//}