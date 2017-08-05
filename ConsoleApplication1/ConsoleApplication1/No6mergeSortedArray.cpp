#include "stdafx.h"
using namespace std;

class Solution {
public:
	/*
	* @param : sorted integer array A
	* @param : sorted integer array B
	* @return: A new sorted integer array
	*/
	vector<int> mergeSortedArray(vector<int> A, vector<int> B) 
	{
		// write your code here
		vector<int> result;
		int sizeA = A.size();
		int sizeB = B.size();
		int i = 0, j = 0;
		while (i < sizeA && j < sizeB)
		{
			if(A[i] <= B[j])
			{
				result.push_back(A[i]);
				i++;
			}
			else
			{
				result.push_back(B[j]);
				j++;
			}
		}
		while (i < sizeA)
		{
			result.push_back(A[i]);
			i++;
		}
		while (j < sizeB)
		{
			result.push_back(B[j]);
			j++;
		}

		return result;
	}
};

//int main()
//{
//	vector<int> nums1 = { 1,2,3,4 };
//	vector<int> nums2 = { 2,4,5,6 };
//	Solution s;
//	vector<int> result = s.mergeSortedArray(nums1, nums2);
//	for(int i = 0; i < result.size(); i++)
//	{
//		cout << result[i] << " ";
//	}
//	return 0;	
//}