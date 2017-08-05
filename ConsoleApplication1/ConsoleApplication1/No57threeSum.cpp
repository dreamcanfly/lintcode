#include "stdafx.h"
#include <algorithm>
using namespace std;

class Solution {
public:
	/**
	* @param numbers : Give an array numbers of n integer
	* @return : Find all unique triplets in the array which gives the sum of zero.
	*/
	vector<vector<int> > threeSum(vector<int> &nums) 
	{
		// write your code here
		vector<vector<int>> result;
		int size = nums.size();
		if (size <= 2) return result;

		sort(nums.begin(), nums.end());

		for (int i = 0; i < size - 2; i++)
		{
			int left = i + 1;
			int right = size - 1;
			if (i != 0 && nums[i] == nums[i - 1])
				continue;
			int twoTarget = 0 - nums[i];
			while (left < right)
			{
				if (left != i + 1 && nums[left] == nums[left - 1])
				{
					left++;
					continue;
				}
				if (right != size - 1 && nums[right] == nums[right + 1])
				{
					right--;
					continue;
				}
				int twoSum = nums[left] + nums[right];
				if (twoSum == twoTarget)
				{
					result.push_back(vector<int>{nums[i], nums[left], nums[right]});
					left++;
					right--;
				}
				if (twoSum < twoTarget)
					left++;
				if (twoSum > twoTarget)
					right--;
			}
		}

		return result;
	}
};

//int main()
//{
//	vector<int> nums = { -1,0,1,2,-1,-4 };
//	vector<vector<int>> result;
//	Solution s;
//	result = s.threeSum(nums);
//	for (int i = 0; i < result.size(); i++)
//	{
//		for (int j = 0; j < result[i].size(); j++)
//		{
//			cout << result[i][j] << " ";
//		}
//		cout << endl;
//	}
//	return 0;
//}