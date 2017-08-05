#include "stdafx.h"
using namespace std;


class Solution {
public:
	/**
	* @param A, B: Two string.
	* @return: the length of the longest common substring.
	*/
	int longestCommonSubstring(string &A, string &B) 
	{
		// write your code here
		int ALen = A.length();
		int BLen = B.length();
		if (ALen <= 0 || BLen <= 0) return 0;
		int maxSubLen = 0;
		int pA = 0, pB = 0;
		while (pB < BLen)
		{
			int tempSubLen = 0;
			while (pA < ALen)
			{
				if (pA + tempSubLen >= ALen || pB + tempSubLen >= BLen)
				{
					maxSubLen = maxSubLen > tempSubLen ? maxSubLen : tempSubLen;
					break;
				}
				if (B[pB + tempSubLen] == A[pA + tempSubLen])
				{
					tempSubLen++;
				}
				else
				{
					pA++;
					maxSubLen = maxSubLen > tempSubLen ? maxSubLen : tempSubLen;
					tempSubLen = 0;
				}
			}
			pB++;
			pA = 0;
		}
		return maxSubLen;
	}

	int longestCommonSubstring2(string &A, string &B)
	{
		int ALen = A.length();
		int BLen = B.length();
		if (ALen <= 0 || BLen <= 0) return 0;
		int maxSubLen = 0;
		int **c = new int*[BLen + 1];
		for (int i = 0; i < BLen + 1; i++)
		{
			c[i] = new int[ALen + 1];
		}
		for (int i = 0; i < BLen + 1; i++)
		{
			for (int j = 0; j < ALen + 1; j++)
			{
				if (i == 0 || j == 0)
					c[i][j] = 0;
				else if(B[i - 1] == A[j - 1])
				{
					c[i][j] = c[i - 1][j - 1] + 1;
					maxSubLen = maxSubLen > c[i][j] ? maxSubLen : c[i][j];
				}
				else
				{
					c[i][j] = 0;
				}
			}
		}
		return maxSubLen;
	}
};


//int main()
//{
//	Solution s;
//	string A = "abcd";
//	string B = "ac";
//	cout << s.longestCommonSubstring2(A, B);
//	return 0;
//}