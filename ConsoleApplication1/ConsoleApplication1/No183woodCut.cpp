#include "stdafx.h"
#include <algorithm>
using namespace std;

class Solution {
public:
	/**
	*@param L: Given n pieces of wood with length L[i]
	*@param k: An integer
	*return: The maximum length of the small pieces.
	*/

	//将二分法的判断标准进行修改，不再是与target直接比较大小，而是计算出可以获得的木材数目然后比较
	int GetNumofwood(vector<int>L, int lenOfEach)
	{
		int sum = 0;
		for(auto x:L)
		{
			sum += x / lenOfEach;
		}
		return sum;
	}

	int woodCut(vector<int> L, int k) 
	{
		// write your code here
		int size = L.size();
		if (size == 0) return 0;
		int max = L[0];
		for(auto x:L)
		{
			max = std::max(x, max);
		}
		int left = 1;
		int right = max;
		while (left <= right)
		{
			int mid = left + (right - left) / 2;
			if (GetNumofwood(L, mid) >= k)
				left = mid + 1;
			else
				right = mid - 1;
		}
		return right;
	}
};

//int main()
//{
//	vector<int> L = { 232,228,469 };
//	int k = 7;
//	Solution s;
//	cout << s.woodCut(L, k);
//	return 0;
//}