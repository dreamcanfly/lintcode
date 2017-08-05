#include "stdafx.h"
using namespace std;

class Solution {
public:
	/*
	* @param a, b, n: 32bit integers
	* @return: An integer
	*/
	//a^n % b//问题,long数据大小与int一致，要使用long long才是真正的64位
	int fastPower(int a, int b, int n) 
	{
		// write your code here
		if (b == 0 || n < 0) return 0;
		if (b == 1) return 0;
		long long ans = 1;
		long long temp = a % b;
		while (n > 0)
		{
			if (n & 1)
			{
				ans = (ans * temp) % b;
			}
			n >>= 1;
			temp = (temp * temp) % b;
		}
		return ans;
	}
};

class Solution2 {
public:
	/*
	* @param a, b, n: 32bit integers
	* @return: An integer
	*/
	int fastPower(int a, int b, int n) {
		// write your code here
		if (b == 0 || n < 0) return 0;
		if (b == 1 && n == 0) return 0;
		long result = 1l, atem = a;
		while (n > 0)
		{
			if ((n & 1) == 1)
			{//n的最后一位为1
				result = (result * atem) % b;
			}
			atem = (atem % b) * (atem % b) % b;
			n >>= 1;
		}
		return (int)result;
	}
};

//int main()
//{
//	int a = -2;
//	int b = 2147483647;
//	int n = 2147483647;
//	Solution s;
//	cout << s.fastPower(a, b, n);
//	return 0;
//}