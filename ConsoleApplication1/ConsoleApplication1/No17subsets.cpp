#include "stdafx.h"
using namespace std;

class Solution {
public:
	/*
	* @param nums: A set of numbers
	* @return: A list of lists
	*/

	vector<vector<int>> result;
	vector<int> base;
	int size;

	vector<vector<int>> subsets(vector<int> &nums) 
	{
		// write your code here
		if (nums.empty()) return result;
		size = nums.size();
		subset(nums, 0);
		return result;
	}

	void subset(vector<int> &nums, int pos)
	{
		result.push_back(base);
		for(int i = pos; i < size; i++)
		{
			base.push_back(nums[i]);
			subset(nums, i + 1);
			base.pop_back();
		}
	}
};