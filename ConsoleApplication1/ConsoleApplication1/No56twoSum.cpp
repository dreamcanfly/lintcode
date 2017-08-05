#include "stdafx.h"
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
	/*
	* @param numbers : An array of Integer
	* @param target : target = numbers[index1] + numbers[index2]
	* @return : [index1+1, index2+1] (index1 < index2)
	*/
	vector<int> twoSum(vector<int> &nums, int target) 
	{
		// write your code here
		vector<int> result;
		int size = nums.size();
		if (size <= 1) return result;
		map<int, int> mymap;
		for (int i = 0; i < size; i++)
		{
			if (mymap.count(nums[i]) != 0)
			{
				result.push_back(mymap[nums[i]] + 1);
				result.push_back(i + 1);
				break;
			}
			mymap[target - nums[i]] = i;
		}
		return result;
	}

};


//int main()
//{
//	vector<int> arr = { 1, 0, -1 };
//	int target = -1;
//	Solution s;
//	vector<int> res = s.twoSum(arr, target);
//	for (int i = 0; i < res.size(); i++)
//	{
//		cout << res[i] << " ";
//	}
//
//	return 0;
//}