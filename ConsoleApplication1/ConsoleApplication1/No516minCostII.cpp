#include "stdafx.h"
#include <algorithm>
using namespace std;

class Solution {
public:
	/*
	* @param costs: n x k cost matrix
	* @return: an integer, the minimum cost to paint all houses
	*/
	int minCostII(vector<vector<int>> &costs) 
	{
		// write your code here
		if (costs.size() <= 0 || costs[0].size() <= 0) return 0;
		int preMin = 0;
		int preMinpos = -1;
		int preSecMin = 0;
		for (int i = 0; i < costs.size(); i++)
		{
			int curMin = INT_MAX, curMinPos = -1, curSecMin = INT_MAX;
			for(int j = 0; j < costs[0].size(); j++)
			{
				costs[i][j] = costs[i][j] + (j == preMinpos ? preSecMin : preMin);

				if(costs[i][j] < curMin)
				{
					curSecMin = curMin;
					curMin = costs[i][j];
					curMinPos = j;
				}
				else if(costs[i][j] < curSecMin)
				{
					curSecMin = costs[i][j];
				}
			}
			preMin = curMin;
			preMinpos = curMinPos;
			preSecMin = curSecMin;
		}
		return preMin;
	}
};


//int main()
//{
//	vector<vector<int>> cost = { {14,2,11},{11,14,5},{14,3,10} };
//	Solution s;
//	cout << s.minCostII(cost) << endl;
//	return 0;
//}