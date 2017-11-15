#include "stdafx.h"
#include <algorithm>
using namespace std;

class Solution {
public:
	/*
	* @param nums: A set of numbers.
	* @return: A list of lists. All valid subsets.
	*/

	vector<vector<int>> result;
	vector<int> base;
	int size;

	vector<vector<int>> subsetsWithDup(vector<int> &nums) 
	{
		// write your code here
		if (nums.empty()) return result;
		size = nums.size();
		sort(nums.begin(), nums.end());
		subsets(nums, 0);
		return result;
	}

	void subsets(vector<int> &nums, int pos)
	{
		result.push_back(base);
		for(int i = pos; i < size; i++)
		{
			if(i != pos && nums[i - 1] == nums[i])
				continue;
			base.push_back(nums[i]);
			subsets(nums, i+1);
			base.pop_back();
		}
	}
};