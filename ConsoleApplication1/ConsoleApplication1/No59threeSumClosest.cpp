#include "stdafx.h"
#include <map>
#include <algorithm>
#include <limits>
using namespace std;

class Solution {
public:
	/**
	* @param numbers: Give an array numbers of n integer
	* @param target: An integer
	* @return: return the sum of the three integers, the sum closest target.
	*/
	int threeSumClosest(vector<int> nums, int target) 
	{
		// write your code here
		int size = nums.size();
		if (size <= 2) return 0;
		sort(nums.begin(), nums.end());
		int result = 0;
		int minDiff = INT_MAX;
		for (int i = 0; i < size - 2; i++)
		{
			if (i != 0 && nums[i] == nums[i - 1])
			{
				continue;
			}
			int left = i + 1;
			int right = size - 1;
			int targetTwo = target - nums[i];
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
				int sumTwo = nums[left] + nums[right];
				int t = abs(sumTwo - targetTwo);
				if (t == 0)
				{
					return target;
				}
				if (t < minDiff)
				{
					result = sumTwo + nums[i];
					minDiff = t;
				}
				if (sumTwo < targetTwo) left++;
				else if (sumTwo > targetTwo) right--;
			}
		}
		return result;
	}
};


//int main()
//{
//	vector<int> nums = { 1,2,5,6,7,3,5,8,-33,-5,-72,12,-34,100,99,1,2,5,6,7,3,5,8,-33,-5,-72,12,-34,100,0,0,-2,2,-5,99,1,2,5,6,7,3,5,8,-33,-5,-72,12,-34,100,99,1,2,5,6,7,3,5,8,-33,-5,-72,12,-34,100,99,1,2,5,6,7,3,5,8,-33,-5,-72,12,-34,100,99,1,2,5,6,7,3,5,8,-33,-5,-72,12,-34,100,99,1,2,5,6,7,3,5,8,-33,-5,-72,12,-34,100,99,1,2,5,6,7,3,5,8,-33,-5,-72,12,-34,100,99,1,2,5,6,7,3,5,8,-33,-5,-72,12,-34,100,99,1,2,5,6,7,3,5,8,-33,-5,-72,12,-34,100,99,1,2,5,6,7,3,5,8,-33,-5,-72,12,-34,100,99,1,2,5,6,7,3,5,8,-33,-5,-72,12,-34,100,99,1,2,5,6,7,3,5,8,-33,-5,-72,12,-34,100,99,1,2,5,6,7,3,5,8,-33,-5,-72,12,-34,100,99,1,2,5,6,7,3,5,8,-33,-5,-72,12,-34,100,99,1,2,5,6,7,3,5,8,-33,-5,-72,12,-34,100,99,1,2,5,6,7,3,5,8,-33,-5,-72,12,-34,100,99,1,2,5,6,7,3,5,8,-33,-5,-72,12,-34,100,99,1,2,5,6,7,3,5,8,-33,-5,-72,12,-34,100,99,1,2,5,6,7,3,5,8,-33,-5,-72,12,-34,100,99 };
//	Solution s;
//	cout << s.threeSumClosest(nums, 25);
//	return 0;
//}