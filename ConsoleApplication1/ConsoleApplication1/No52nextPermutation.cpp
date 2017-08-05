#include "stdafx.h"
using namespace std;

class Solution {
public:
	/**
	* @param nums: An array of integers
	* @return: An array of integers that's next permuation
	*/
	vector<int> nextPermutation(vector<int> &nums) 
	{
		// write your code here
		int size = nums.size();
		int i = 0;
		for(i = size - 1; i > 0 ; --i)
		{
			if(nums[i] > nums[i - 1])
			{
				break;
			}

		}
		if (i == 0)
		{
			reverse(nums.begin(), nums.end());
			return nums;
		}
		--i;
		int j = 0;
		for(j = size - 1; j > i; --j)
		{
			if(nums[j] > nums[i])
				break;
		}
		swap(nums[i], nums[j]);
		reverse(nums.begin() + i + 1, nums.end());
		return nums;
	}
};

//int main()
//{
//	vector<int> nums = { 1,3,2,3 };
//	Solution s;
//	vector<int> results = s.nextPermutation(nums);
//	for(int i = 0; i < results.size(); i++)
//	{
//		cout << results[i] << " ";
//	}
//	return 0;
//}