#include "stdafx.h"
#include <algorithm>
using namespace std;

//http://blog.csdn.net/u012850192/article/details/51802086
//关于动态规划与贪心方法的解释

class Solution2 {
public:
	/**
	* @param A: A list of integers
	* @return: The boolean answer
	*/
	//DP
	bool canJump(vector<int> A) 
	{
		// write you code here
		vector<int> res;
		int size = A.size();
		if (size <= 0) return true;
		res.push_back(A[0]);
		for(int i = 1; i < A.size(); i++)
		{
			if (res[i - 1] >= i)
				res.push_back(max(A[i] + i, res[i - 1]));
			else
				res.push_back(0);
		}
		return res.back() >= size - 1;
	}
};

class Solution {
public:
	/**
	* @param A: A list of integers
	* @return: The boolean answer
	*/
	//DP
	bool canJump(vector<int> A) 
	{
		// write you code here
		int size = A.size();
		if (size <= 0) return true;
		int maxGap = 0;
		int cur = 0;
		while (maxGap >= cur)
		{
			maxGap = max(maxGap, A[cur] + cur);
			cur++;
			if (maxGap >= size - 1) return true;
		}
		return false;
	}
};


//int main()
//{
//	vector<int> A = { 2,3,1,1,4 };//{3,2,1,0,4};
//	Solution s;
//	cout << s.canJump(A);
//	return 0;
//}