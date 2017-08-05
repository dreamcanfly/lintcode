#include "stdafx.h"
using namespace std;

class Solution {
public:
	/**
	*@param n, m: Two integer
	*@param i, j: Two bit positions
	*return: An integer
	*/
	int updateBits(int n, int m, int i, int j) 
	{
		// write your code here
		unsigned int mask = 0;
		for(int temp = i; temp <= j; temp++)
		{
			mask += pow(2, temp);
		}
		m = m << i;
		mask = ~mask;
		n = n & mask;
		int res = n | m;
		return res;
	}
};

//int main()
//{
//	int n = -11;
//	int m = -789;
//	int i = 0;
//	int j = 31;
//	Solution s;
//	cout << s.updateBits(n, m, i, j);
//	return 0;
//}