#include "stdafx.h"
using namespace std;

class Solution {
	/**
	* param A : an integer sorted array
	* param target :  an integer to be inserted
	* return : an integer
	*/
public:
	int searchInsert(vector<int> &A, int target) 
	{
		// write your code here
		int size = A.size();
		if (size <= 1) return 0;
		int pos = BinarySearch(A, target);
		if (A[pos] < target)
			return pos + 1;
		return pos;
	}

	int BinarySearch(vector<int> &A,int target)
	{
		int left = 0;
		int right = A.size() - 1;
		while (left < right)
		{
			int mid = (left + right) / 2;
			if (A[mid] == target)
				return mid;
			if (A[mid] > target)
				right = mid - 1;
			else if (A[mid] < target)
				left = mid + 1;
		}
		return left;
	}
};

//int main()
//{
//	vector<int> nums = { -1,0,1,2 };
//	int target = 2;
//	Solution s;
//	cout << s.searchInsert(nums, target);
//	return 0;
//}