#include "stdafx.h"
using namespace std;

class Solution {
public:
	/**
	* @param A: Array of integers.
	* return: The single number.
	*/
	int singleNumber(vector<int> &A) 
	{
		// write your code here
		int ans = 0;
		for(int i = 0; i < A.size();i++)
		{
			ans ^= A[i];
		}
		return ans;
	}
};

class Solution2 {
public:
	/**
	* @param A: Array of integers.
	* return: The single number.
	*/
	int singleNumber(vector<int> &A)
	{
		// write your code here
		vector<int> ans(32,0);
		for(int i = 0; i < A.size(); i++)
		{
			for(int j = 0; j < 32; j++)
			{
				ans[j] = (ans[j] + ((A[i] >> j) & 1)) % 2;
			}
		}
		int base = 1;
		int ret = 0;
		for(int i = 0; i < 32; i++)
		{
			ret += ans[i] << i;
		}
		return ret;
	}
};


//int main()
//{
//	vector<int> A = { 1,2,3,4,1,2,3 };
//	Solution2 s;
//	cout << s.singleNumber(A);
//	return 0;
//}