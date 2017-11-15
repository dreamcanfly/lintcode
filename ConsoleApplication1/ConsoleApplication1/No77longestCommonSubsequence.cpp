#include "stdafx.h"
#include <algorithm>
using namespace std;

class Solution {
public:
	/*
	* @param A: A string
	* @param B: A string
	* @return: The length of longest common subsequence of A and B
	*/
	int longestCommonSubsequence(string &A, string &B) 
	{
		// write your code here
		int n = A.size();
		int m = B.size();
		if (n <= 0 || m <= 0) return 0;
		vector<vector<int>> DP(n, vector<int>(m));
		int temp = 0;
		for (int i = 0; i < m; i++)
		{
			if (A[0] == B[i])
				temp = 1;
			DP[0][i] = temp;
		}
		temp = 0;
		for (int i = 0; i < n; i++)
		{
			if (A[i] == B[0])
				temp = 1;
			DP[i][0] = temp;
		}
		int res = 0;
		for (int i = 1; i < n; i++)
		{
			for (int j = 1; j < m; j++)
			{
				if (A[i] == B[j])
					DP[i][j] = DP[i - 1][j - 1] + 1;
				else
					DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
				res = res > DP[i][j] ? res : DP[i][j];
			}
		}
		return res;
	}
};
//int main()
//{
//	string A = "zynnqufc";
//	string B = "ddbauhkw";
//	Solution s;
//	cout << s.longestCommonSubsequence(A, B);
//	return 0;
//}