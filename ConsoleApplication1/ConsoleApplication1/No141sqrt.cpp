#include "stdafx.h"
using namespace std;

class Solution {
public:
	/**
	* @param x: An integer
	* @return: The sqrt of x
	*/
	int sqrt(int x)
	{
		// write your code here
		int start = 1;
		int end = x - 1;
		while (start < end)
		{
			int mid = (start + end) / 2;
			if (x / mid == mid)
				return mid;
			if (x / mid > mid)
				start = mid + 1;
			if (x / mid < mid)
				end = mid - 1;
		}
		if (start * start > x)
			return start - 1;
		else
			return start;
	}
};

//int main()
//{
//	int num = 2147483647;
//	Solution s;
//	cout << s.sqrt(num);
//	return 0;
//}