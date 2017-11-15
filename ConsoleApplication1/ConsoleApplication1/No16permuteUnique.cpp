#include "stdafx.h"
#include <algorithm>
using namespace std;

class Solution {
public:
	/*
	* @param :  A list of integers
	* @return: A list of unique permutations
	*/
	vector<vector<int>> permuteUnique(vector<int> &nums) 
	{
		// write your code here
		vector<vector<int>> result;
		int n = nums.size();
		if (n <= 0)
		{
			result.push_back(nums);
			return result;
		}
		sort(nums.begin(), nums.end()); //此处sort无法去除，出错案例[-1,2,-1,2,1,-1,2,1]
		GetPermute(nums, 0, n, result);
		return result;
	}

	void GetPermute(vector<int> &nums, int pos, int n, vector<vector<int>> &result)
	{
		if (pos == n - 1)
		{
			result.push_back(nums);
			return;
		}
		for (int i = pos; i < n; i++)
		{
			//此处为关键点，去重，首先去除第一个元素，避免数组越界，如果一个数与前面的数相等或者与开始处元素相同，则无需交换，究其根本就是循环的时候，重复的数字无需重复交换。
			if(i != pos && (nums[i - 1] == nums[i] || nums[pos] == nums[i])) continue; 
			int temp = nums[pos];
			nums[pos] = nums[i];
			nums[i] = temp;

			GetPermute(nums, pos + 1, n, result);

			temp = nums[pos];
			nums[pos] = nums[i];
			nums[i] = temp;
		}
	}
};

//int main()
//{
//	vector<int> arr = { 0,1,0,0,9 };
//	Solution s;
//	auto res = s.permuteUnique(arr);
//	for(int i = 0; i < res.size(); i++)
//	{
//		for(int j = 0; j < res[0].size(); j++)
//		{
//			cout << res[i][j] << " ";
//		}
//		cout << endl;
//	}
//	return 0;
//}