#include "stdafx.h"
using namespace std;

class Solution {
public:
	/*
	* @param n: Given the range of numbers
	* @param k: Given the numbers of combinations
	* @return: All the combinations of k numbers out of 1..n
	*/
	vector<vector<int>> combine(int n, int k) 
	{
		// write your code here
		vector<vector<int>> result;
		if (n <= 0 || k <= 0 || n < k) return result;
		vector<int> temp;
		CombineHelper(result, temp, k, n, 1);
		return result;
	}

	void CombineHelper(vector<vector<int>> & result, vector<int> &temp, int k, int n, int start)
	{
		if(temp.size() == k)
		{
			result.push_back(temp);
			return;
		}

		for(int i = start; i <= n; i++)
		{
			temp.push_back(i);
			CombineHelper(result, temp, k, n, i + 1);
			temp.pop_back();
		}
	}
};

//int main()
//{
//	int n, k;
//	cin >> n >> k;
//	Solution s;
//	auto res = s.combine(n, k);
//	for(int i = 0; i < res.size(); i++)
//	{
//		for(int j = 0; j < res[i].size(); j++)
//		{
//			cout << res[i][j] << " ";
//		}
//		cout << endl;
//	}
//	return 0;
//}