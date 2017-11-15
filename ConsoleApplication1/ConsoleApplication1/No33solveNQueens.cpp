#include "stdafx.h"
using namespace std;

class Solution {
public:
	/*
	* @param n: The number of queens
	* @return: All distinct solutions
	*/
	vector<vector<string>> solveNQueens(int n) 
	{
		// write your code here
		vector<string> chess(n, string(n,'.'));
		vector<vector<string>> result;
		if (n < 1) return result;
		GetSolutions(chess, n, 0, result);
		return result;
	}

	void GetSolutions(vector<string> &chess, int n,int row, vector<vector<string>> &result)
	{
		for(int i = 0; i < n; i++)
		{
			if(check(row, i, chess))
			{
				chess[row][i] = 'Q';
				if (row == n - 1)
				{
					result.push_back(chess);
				}
				else 
					GetSolutions(chess, n, row + 1, result);
				chess[row][i] = '.';
			}
		}
	}

	bool check(int row, int col, vector<string> &chess)
	{
		int size = chess.size();
		for(int i = 0; i <= row; i++)
		{
			for(int j = 0; j < size; j++)
			{
				if(chess[i][j] == 'Q')
				{
					if(i == row || j == col || (abs(row - i) == abs(col - j)))
					{
						return false;
					}
				}
			}
		}
		return true;
	}
};

//int main()
//{
//	int n = 4;
//	Solution s;
//	vector<vector<string>> res = s.solveNQueens(n);
//	for(int i = 0; i < res.size(); i++)
//	{
//		for(int j = 0; j < res[0].size(); j++)
//		{
//			cout << res[i][j] << endl;
//		}
//		cout << endl;
//	}
//	return 0;
//}