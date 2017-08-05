#include "stdafx.h"
using namespace std;

class Solution1 {
public:
	/**
	* @param nums: a rotated sorted array
	* @return: the minimum number in the array
	*/
	int findMin(vector<int> &nums) 
	{
		// write your code here
		int size = nums.size();
		if (size <= 0) return 0;
		int left = 0;
		int right = size - 1;
		if (nums[right] >= nums[left]) return nums[left];
		while (left < right)
		{
			int mid = (left + right) / 2;
			if (nums[mid] > nums[left])
			{
				if (nums[mid] > nums[mid + 1])
					return nums[mid + 1];
				left = mid + 1;
			}
			else if (nums[mid] < nums[right])
			{
				if (nums[mid] < nums[mid - 1])
					return nums[mid];
				right = mid - 1;
			}
			else
				return nums[mid + 1];
		}
	}
};

class Solution {
public:
	/**
	* @param nums: a rotated sorted array
	* @return: the minimum number in the array
	*/
	int findMin(vector<int> &nums)
	{
		// write your code here
		int size = nums.size();
		if (size <= 0) return 0;
		int left = 0;
		int right = size - 1;
		if (nums[right] >= nums[left]) return nums[left];
		int mid = 0;
		while (left < right)
		{
			mid = (left + right) / 2;
			if (nums[mid] > nums[right])
			{
				left = mid + 1;
			}
			else 
			{
				right = mid;
			}
		}
		return nums[left];
	}
};
//int main()
//{
//	vector<int> nums = { 4,5,6,7,8,9,1,2,3 };
//	Solution s;
//	cout << s.findMin(nums);
//	return 0;
//}