#include "stdafx.h"
#include <algorithm>
using namespace std;

class Solution {
public:
	/**
	* @param nums: A list of integers
	* @return: A list of integers includes the index of the first number
	*          and the index of the last number
	*/

	//解题思路：因为是子数组的和，所以计算出以第一个元素开头的所有子数组，然后计算他们的差值，差值最小的表明
	//这两组和之间的元素相加最接近0
	

	class Nsum
	{
	public:
		int pos;
		int sum;
		Nsum()
		{
			pos = 0;
			sum = 0;
		}
	};

	bool static cmp(const Nsum &a1, const Nsum &a2)
	{
		return a1.sum > a2.sum;
	}

	vector<int> subarraySumClosest(vector<int> nums) 
	{
		// write your code here
		vector<int> result(2);
		int size = nums.size();
		if (size <= 0) return result;
		if (size == 1) return vector<int>{0, 0};
		vector<Nsum> NSums(size);
		NSums[0].sum = nums[0];
		NSums[0].pos = 0;
		for(int i = 1; i < size; i++)
		{
			NSums[i].sum = NSums[i - 1].sum + nums[i];
			NSums[i].pos = i;
		}

		sort(NSums.begin(), NSums.end(),cmp);
		int closest = INT_MAX;
		for(int i = 1; i < size; i++)
		{
			if(closest > abs(NSums[i].sum - NSums[i - 1].sum))
			{
				closest = abs(NSums[i].sum - NSums[i - 1].sum);
				result[0] = NSums[i].pos;
				result[1] = NSums[i - 1].pos;
				sort(result.begin(), result.end());
				result[0]++;
			}
		}
		return result;
	}
};


//int main()
//{
//	vector<int> nums = { 101,33,44,55,67,78,-101,33,-44,55,-67,78,-100,200,-1000,22,100,200,1000,22 };
//	vector<int> res;
//	Solution s;
//	res = s.subarraySumClosest(nums);
//
//	for(int i = 0; i < res.size();i++)
//	{
//		cout << res[i] << " ";
//	}
//	return 0;	
//}