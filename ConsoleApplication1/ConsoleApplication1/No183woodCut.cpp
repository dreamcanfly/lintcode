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

	//�����ַ����жϱ�׼�����޸ģ���������targetֱ�ӱȽϴ�С�����Ǽ�������Ի�õ�ľ����ĿȻ��Ƚ�
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