#include "stdafx.h"
using namespace std;

class Solution {
public:
	/**
	* @param nums: The integer array.
	* @param target: Target number to find.
	* @return: The first position of target. Position starts from 0.
	*/
	int binarySearch(vector<int> &array, int target) 
	{
		// write your code here
		int size = array.size();
		if (size <= 0) return -1;
		int left = 0; 
		int right = size - 1;
		int mid = 0;
		while (left <= right)
		{
			mid = (left + right) / 2;
			if (array[mid] == target)
			{
				while (mid > 0 && array[mid] == array[mid - 1])
				{
					mid--;
				}
				return mid;
			}
			else if (array[mid] > target)
				right = mid - 1;
			else
				left = mid + 1;
		}
		
		return -1;
	}
};

//int main()
//{
//	vector<int> nums = { 3,4,5,8,8,8,8,10,13,14 };
//	int target = 8;
//	Solution s;
//	cout << s.binarySearch(nums,target);
//	return 0;
//}