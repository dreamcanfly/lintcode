#include "stdafx.h"
#include <algorithm>
using namespace std;

class Solution {
public:
	/*
	* @param costs: n x 3 cost matrix
	* @return: An integer, the minimum cost to paint all houses
	*/
	int minCost(vector<vector<int>> &costs) 
	{
		// write your code here
		if (costs.size() <= 0 || costs[0].size() <= 0) return 0;
		for(int i = 1; i < costs.size(); i++)
		{
			costs[i][0] = costs[i][0] + min(costs[i - 1][1], costs[i - 1][2]);
			costs[i][1] = costs[i][1] + min(costs[i - 1][0], costs[i - 1][2]);
			costs[i][2] = costs[i][2] + min(costs[i - 1][0], costs[i - 1][1]);
		}
		return min(costs.back()[0], min(costs.back()[1], costs.back()[2]));
	}
};