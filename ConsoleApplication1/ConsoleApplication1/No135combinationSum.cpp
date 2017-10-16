#include "stdafx.h"
#include <algorithm>
using namespace std;

class Solution {
public:
	/*
	* @param candidates: A list of integers
	* @param target: An integer
	* @return: A list of lists of integers
	*/
	vector<vector<int>> combinationSum(vector<int> &candidates, int target) 
	{
		// write your code here
		vector<vector<int>> result;
		if (candidates.size() <= 0 || candidates[0] > target) return result;
		sort(candidates.begin(), candidates.end());
		vector<int> temp;
		CombinationHelp(candidates, target, result, temp, 0);
		return result;
	}

	void CombinationHelp(vector<int> &candidates, int target, vector<vector<int>> &result, vector<int> &temp, int start)
	{
		if(target == 0)
		{
			result.push_back(temp);
			return;
		}

		for(int i = start; i < candidates.size(); ++i)
		{
			if(candidates[i] > target)
			{
				return;
			}
			temp.push_back(candidates[i]);
			CombinationHelp(candidates, target - candidates[i], result, temp, start);
			temp.pop_back();
		}
	}
};