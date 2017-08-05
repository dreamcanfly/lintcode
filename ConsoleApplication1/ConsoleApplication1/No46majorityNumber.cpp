#include "stdafx.h"
using namespace std;

class Solution2 {
public:
	/**
	* @param nums: A list of integers
	* @return: The majority number
	*/
	int majorityNumber(vector<int> nums) 
	{
		// write your code here
		int size = nums.size();
		//judge
		int result = nums[0];
		int times = 1;
		for(int i = 1; i < size; i++)
		{
			if(times == 0)
			{
				result = nums[i];
				times++;
			}
			else
			{
				if (result == nums[i])
					times++;
				else
				{
					times--;
				}
			}
		}
		return result;
	}
};

//方法可以理解但是不太适用
class Solution {
public:
	/**
	* @param nums: A list of integers
	* @return: The majority number
	*/
	int majorityNumber(vector<int> nums)
	{
		// write your code here
		int size = nums.size();
		//judge
		int midPos = size >> 1;
		int start = 0;
		int end = size - 1;
		int index = partition(nums, start, end);
		while (index != midPos)
		{
			if(index > midPos)
			{
				end = index - 1;
				index = partition(nums, start, end);
			}
			else if(index < midPos)
			{
				start = index + 1;
				index = partition(nums, start, end);
			}
		}
		int result = nums[midPos];
		return result;
	}

	int partition(vector<int> &nums,int left, int right)
	{
		int size = nums.size();
		if (size == 1) return 0;
		if (left >= right) return left;
		int num = nums[left];
		int startpos = left;
		left++;
		while (left < right)
		{
			while (left < right && nums[left] < num)
			{
				left++;
			}
			while (left < right && nums[right] >= num)
			{
				right--;
			}
			if(left < right)
				Swap(nums, left, right);
		}
		
		if(nums[left] < num)
		{
			Swap(nums, startpos, left);
		}
		return left;
	}

	void Swap(vector<int> &nums,int left, int right)
	{
		int temp = nums[left];
		nums[left] = nums[right];
		nums[right] = temp;
	}
};
//int main()
//{
//	vector<int> nums = { 10,49,10,56,39,93,7,3,87,48,42,10,70,10,10,32,25,10,27,10,10,10,4,10,16,10,11,61,67,17,10,91,6,10,66,99,38,72,16,96,10,10,6,10,27,10,10,10,10,47,56,51,68,43,10,10,46,10,77,21,24,37,10,10,45,45,10,65,31,10,10,59,61,58,18,10,61,10,10,10,39,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10 };//{ 2,2,2,1 };//{ 1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,3,4 };
//	Solution s;
//	cout << s.majorityNumber(nums);
//	return 0;
//}