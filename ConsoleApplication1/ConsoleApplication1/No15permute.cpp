#include "stdafx.h"
using namespace std;

class Solution {
public:
	/*
	* @param nums: A list of integers.
	* @return: A list of permutations.
	*/
	vector<vector<int>> permute(vector<int> &nums)
	{
		// write your code here
		vector<vector<int>> result;
		int n = nums.size();
		if (n <= 0)
		{
			result.push_back(nums);
			return result;
		}
		GetPermute(nums, 0, n, result);
		return result;
	}

	void GetPermute(vector<int> &nums, int pos, int n, vector<vector<int>> &result)
	{
		if(pos == n - 1)
		{
			result.push_back(nums);
			return;
		}
		for(int i = pos; i < n; i++)
		{
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
//	vector<int> arr = { 1,2,3 };
//	Solution s;
//	auto res = s.permute(arr);
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