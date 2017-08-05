#include "stdafx.h"
using namespace std;

class Solution1 {
public:
	/**
	* @param A: An integers array.
	* @return: return any of peek positions.
	*/
	int findPeak(vector<int> A) 
	{
		// write your code here
		int size = A.size();
		if (size <= 0) return 0;
		int left = 1;
		int right = size - 2;
		while (left <= right)
		{
			int mid = (left + right) / 2;
			if (A[mid] > A[mid - 1] && A[mid] > A[mid + 1])
			{
				return mid;
			}
			else if (A[mid] > A[mid - 1] && A[mid] < A[mid + 1])
			{
				left = mid + 1;
			}
			else if (A[mid] < A[mid - 1] && A[mid] > A[mid + 1])
			{
				right = mid - 1;
			}
			else
				left = mid + 1;
		}
		return 0;
	}
};

//判断当前是上坡还是下坡，如果是上坡，那么峰值肯定在自己之后，如果是下坡，峰值肯定在自己或者自己之前。
class Solution {
public:
	/**
	* @param A: An integers array.
	* @return: return any of peek positions.
	*/
	int findPeak(vector<int> A)
	{
		// write your code here
		int size = A.size();
		if (size <= 0) return 0;
		int left = 1;
		int right = size - 2;
		while (left < right)
		{
			int mid = (left + right) / 2;
			if (A[mid] < A[mid + 1])
				left = mid + 1;
			else
				right = mid;
		}
		return right;
	}
};
//int main()
//{
//	vector<int> nums = { 1, 2, 1, 3, 4, 5, 7, 6 };
//	Solution s;
//	cout << s.findPeak(nums);
//	return 0;
//}