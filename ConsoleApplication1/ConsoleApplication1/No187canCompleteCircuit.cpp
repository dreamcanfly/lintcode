#include "stdafx.h"
using namespace std;

class Solution {
public:
	/**
	* @param gas: a vector of integers
	* @param cost: a vector of integers
	* @return: an integer
	*/
	int canCompleteCircuit(vector<int> &gas, vector<int> &cost) 
	{
		// write your code here
		int size = gas.size();
		if (size <= 0) return -1;
		int sum = 0;
		int sumTemp = 0;
		int startPos = 0;
		for(int i = 0; i < size; i++)
		{
			int leftGas = gas[i] - cost[i];
			if (leftGas >= 0 && sumTemp < 0)
			{
				startPos = i;
				sumTemp = 0;
			}
			sumTemp += leftGas;
			sum += leftGas;
		}
		if (sum < 0) startPos = -1;
		return startPos;
	}
};

//网上的思路，其实和我的方法异曲同工
class Solution2 {
public:
	/**
	* @param gas: a vector of integers
	* @param cost: a vector of integers
	* @return: an integer
	*/
	int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
		// write your code here
		int cur = 0;
		int totalGas = 0;
		int totalCost = 0;
		int start = 0;
		for (int i = 0; i<gas.size(); i++)
		{
			cur += gas[i];
			cur -= cost[i];
			totalGas += gas[i];
			totalCost += cost[i];
			if (cur<0)
			{
				start = i + 1;
				cur = 0;
			}
		}
		if (totalGas >= totalCost)
			return start;
		return -1;
	}
};


//int main()
//{
//	vector<int> gas = { 1,1,3,1 };
//	vector<int> cost = { 2,2,1,1 };
//	Solution s;
//	cout << s.canCompleteCircuit(gas, cost);
//	return 0;
//}