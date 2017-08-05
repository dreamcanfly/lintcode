#include "stdafx.h"
using namespace std;

class Solution {
public:
	/**
	* @param num: the rotated sorted array
	* @return: the minimum number in the array
	*/
	int findMin(vector<int> &num) 
	{
		// write your code here
		int size = num.size();
		if (size <= 0) return 0;
		int left = 0;
		int right = size - 1;
		if (num[left] < num[right]) return num[left];
		while (left < right)
		{
			int mid = left + (right - left) / 2;
			if (num[mid] > num[right])
				left = mid + 1;
			else if(num[mid] < num[right])
			{
				right = mid;
			}
			else
			{
				while (left < right)
				{
					if (left == 0 && num[left] < num[left + 1])
						return num[left];
					if(num[left] < num[left + 1] && num[left] < num[left - 1])
					{
						return num[left];
					}
					left++;
				}
			}
		}
		return num[left];
	}
};

//int main()
//{
//	vector<int> num = { 999,999,1000,1000,10000,0,999,999,999 };
//	Solution s;
//	cout << s.findMin(num);
//	return 0;
//}