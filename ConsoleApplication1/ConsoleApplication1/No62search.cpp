#include "stdafx.h"
using namespace std;

class Solution {
	/**
	* param A : an integer ratated sorted array
	* param target :  an integer to be searched
	* return : an integer
	*/
public:
	int search(vector<int> &A, int target) 
	{
		// write your code here
		int size = A.size();
		if (size <= 0)
		{
			return -1;
		}
		int left = 0;
		int right = size - 1;
		while (left <= right)
		{
			int mid = left + (right - left) / 2;
			if (A[mid] == target)
				return mid;
			if(A[mid] > A[right])
			{
				if(target > A[right])
				{
					if (target > A[mid])
						left = mid + 1;
					else
					{
						right = mid - 1;
					}
				}
				else
				{
					left = mid + 1;
				}
			}
			else
			{
				if(target > A[right])
				{
					right = mid - 1;
				}
				else
				{
					if (target > A[mid])
						left = mid + 1;
					else
						right = mid - 1;
				}
			}
		}
		return -1;
	}
};

//int main()
//{
//	vector<int> nums = { 4,5,6,7,0,1,2 };
//	int target = -1;
//	Solution s;
//	cout << s.search(nums, target);
//	return 0;
//}