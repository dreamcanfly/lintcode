#include "stdafx.h"
#include <map>
using namespace std;


//找出数组中和为0的子数组，能想到的暴力破解的方法就是双重循环检测，后来找到经典解法：
//i < j
//sum[i] = a[0] + ... + a[i];
//sum[j] = a[0] + ... + a[j];
//if(sum[i] == sum[j]) a[i+1] + ... + a[j] = 0

class Solution {
public:
	/**
	* @param nums: A list of integers
	* @return: A list of integers includes the index of the first number
	*          and the index of the last number
	*/
	vector<int> subarraySum(vector<int> nums) 
	{
		// write your code here
		int size = nums.size();
		vector<int> sums(size);
		map<int, int> myMap;//i,sum[i]
		vector<int> result;
		if (nums[0] == 0)
		{
			result.push_back(0);
			result.push_back(0);
		}
		sums[0] = nums[0];
		myMap[sums[0]] = 0;
		myMap[0] = -1;
		
		map<int, int>::iterator it;
		for (int i = 1; i < size; i++)
		{
			sums[i] = sums[i - 1] + nums[i];
			it = myMap.find(sums[i]);
			if (it != myMap.end())
			{
				result.push_back((*it).second + 1);
				result.push_back(i);
				break;
			}
			else
			{
				myMap[sums[i]] = i;
			}
		}
		return result;
	}
};

//int main()
//{
//	Solution s;
//	vector<int> nums = { 0 };
//	vector<int> res = s.subarraySum(nums);
//	for (int i = 0; i < res.size(); i++)
//	{
//		cout << res[i] << " ";
//	}
//
//	return 0;
//}