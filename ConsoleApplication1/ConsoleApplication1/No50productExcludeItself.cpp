#include "stdafx.h"
using namespace std;

class Solution {
public:
	/**
	* @param A: Given an integers array A
	* @return: A long long array B and B[i]= A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]
	*/
	vector<long long> productExcludeItself(vector<int> &nums) 
	{
		// write your code here
		vector<long long> result;
		int size = nums.size();
		if (size <= 0) return result;
		static vector<long long> leftProcessValue(size);//l[i] presents A[1]*A[2]*...*A[i]
		static vector<long long> rightProcessValue(size);//r[i] presents A[size - 1]*A[size - 1 -1]*...*A[size - 1 - i]
		
		long long leftTemp = 1;
		long long rightTemp = 1;
		for (int i = 0; i < size; i++)
		{
			leftTemp *= nums[i];
			leftProcessValue[i] = leftTemp;
			rightTemp *= nums[size - 1 - i];
			rightProcessValue[size - 1 - i] = rightTemp;
		}

		for (int i = 0; i < size; i++)
		{
			int left = 0;
			int right = size - 1;
			if (i == 0 && i == (size - 1))
			{
				result.push_back(1);
				continue;
			}
			if (i == 0)
			{
				result.push_back(rightProcessValue[i + 1]);
				continue;
			}

			if (i == (size - 1)) 
			{
				result.push_back(leftProcessValue[i - 1]);
				continue;
			} 
			
			result.push_back(leftProcessValue[i - 1] * rightProcessValue[i + 1]);
		}

		return result;
	}
};

//int main()
//{
//	vector<int> nums = { 1,2,3 };
//	vector<long long> result;
//	Solution s;
//	result = s.productExcludeItself(nums);
//	for (int i = 0; i < result.size(); i++)
//	{
//		cout << result[i] << " ";
//	}
//	return 0;
//}