#include "stdafx.h"
#include <algorithm>
using namespace std;

class Solution {
	/**
	*@param A : an integer sorted array
	*@param target :  an integer to be inserted
	*return : a list of length 2, [index1, index2]
	*/
public:
	//��vector�Ķ��ֲ��ң�����ʹ��upper_bound�Լ�lower_bound�������У�����STL�⺯��
	vector<int> searchRange(vector<int> &A, int target) 
	{
		// write your code here
		int size = A.size();
		if (size <= 0) return vector<int>{-1, -1};
		int left = 0;
		int right = size - 1;
		while (left <= right)
		{
			int mid = left + (right - left) / 2;
			if(A[mid] == target)
			{
				left = right = mid;
				break;
			}
			else if(A[mid] < target)
			{
				left = mid + 1;
			}
			else
			{
				right = mid - 1;
			}
		}

		if(left == right)
		{
			while (left >= 0 && A[left] == target)
			{
					left--;
			}
			while (right < size && A[right] == target)
			{
					right++;
			}
			return vector<int>{left + 1, right - 1};
		}
		else
		{
			return vector<int>{-1, -1};
		}
	}
};

//int main()
//{
//	vector<int> nums = { 5, 7, 7, 8, 8, 10 };
//	int target = 6;
//	Solution s;
//	vector<int> result = s.searchRange(nums, target);
//	for(int i = 0; i < result.size();i++)
//	{
//		cout << result[i] << " ";
//	}
//	return 0;
//}