#include "stdafx.h"
using namespace std;


//小于k的数放左边，大于等于k的数放右边，全部小于k，返回数组长度
class Solution {
public:
	static int partitionArray(vector<int> &nums, int k) 
	{
		// write your code here
		if (nums.size() <= 0) return 0;
		int left = 0; 
		int right = nums.size() - 1;
		while (left < right)
		{
			while (nums[left] < k && left < right)
			{
				left++;
			}
			while (nums[right] >= k && left < right)
			{
				right--;
			}
			Swap(nums, left, right);
		}
		if (left == nums.size() - 1)
			left = nums.size();
		return left;
	}

	static void Swap(vector<int> &nums,int left,int right)
	{
		int temp = nums[left];
		nums[left] = nums[right];
		nums[right] = temp;
	}
};

//int main()
//{
//	vector<int> nums = { 3,2,2,1 };
//	int k = 2;
//	
//	cout << Solution::partitionArray(nums, k);
//	return 0;
//}