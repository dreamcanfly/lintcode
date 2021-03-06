#include "stdafx.h"
using namespace std;

class Solution {
public:
	/**
	* @param A: a list of integers sorted
	* @return : return an integer
	*/
	int removeDuplicates(vector<int> &nums) 
	{
		// write your code here
		int size = nums.size();
		if (size <= 0) return 0;
		vector<int>::iterator iter = nums.begin();
		while ((iter - (nums.end() - 1)) < 0)
		{
			if((*iter) == *(iter + 1))
			{
				nums.erase(iter + 1);
			}
			else
			{
				iter++;
			}
		}
		return nums.size();
	}
};

//int main()
//{
//	vector<int> nums = { -14,-14,-13,-13,-13,-13,-13,-13,-13,-12,-12,-12,-12,-11,-10,-9,-9,-9,-8,-7,-5,-5,-5,-5,-4,-3,-3,-2,-2,-2,-2,-1,-1,-1,-1,-1,0,1,1,1,1,2,2,2,3,3,3,4,4,4,4,5,5,5,6,6,6,6,7,8,8,8,9,9,9,10,10,10,11,11,11,12,12,12,13,14,14,14,14,15,16,16,16,18,18,18,19,19,19,19,20,20,20,21,21,21,21,21,21,22,22,22,22,22,23,23,24,25,25 };
//	Solution s;
//	cout << s.removeDuplicates(nums);
//	for (int i = 0; i < nums.size(); i++)
//	{
//		cout << nums[i] << " ";
//	}
//	return 0;
//}