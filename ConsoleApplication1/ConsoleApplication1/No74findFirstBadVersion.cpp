#include "stdafx.h"
using namespace std;


class SVNRepo {
    public:
    static bool isBadVersion(int k);
};
//you can use SVNRepo::isBadVersion(k) to judge whether
//the kth code version is bad or not.

class Solution {
public:
	/**
	* @param n: An integers.
	* @return: An integer which is the first bad version.
	*/
	int findFirstBadVersion(int n) 
	{
		// write your code here
		if (n <= 0) return 0;
		int left = 1;
		int right = n;
		while (left <= right)
		{
			int mid = left + ((right - left) >> 1);
			if (SVNRepo::isBadVersion(mid))
				right = mid - 1;
			else
				left = mid + 1;
		}
		return left;
	}
};
