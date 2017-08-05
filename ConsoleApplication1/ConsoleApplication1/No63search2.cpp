#include "stdafx.h"
using namespace std;

//网上看到的方法
class Solution {
	/**
	* param A : an integer ratated sorted array and duplicates are allowed
	* param target :  an integer to be search
	* return : a boolean
	*/
public:
	bool search(vector<int> &A, int target)
	{
		// write your code here
		int size = A.size();
		if (size <= 0) return false;
		int left = 0;
		int right = size - 1;
		while (left <= right)
		{
			int mid = left + (right - left) / 2;
			if (A[mid] == target)
				return true;
			if(A[mid] > A[left])
			{
				if(A[mid] >= target && A[left] <= target)
				{
					right = mid - 1;
				}
				else
				{
					left = mid + 1;
				}
			}
			else if(A[mid] < A[left])
			{
				if(A[mid] >= target && target <= A[right])
				{
					right = mid - 1;
				}
				else
				{
					left = mid + 1;
				}
			}
			else
			{
				left++;
			}
		}
		return false;
	}
};

//int main()
//{
//	vector<int> nums = { 4,5,5,6,7,0,1,2 };
//	int target = 1;
//	Solution s;
//	cout << s.search(nums, target);
//	return 0;
//}