#include "stdafx.h"
using namespace std;

class Solution {
public:
	/**
	* @param matrix: A list of lists of integers
	* @param target: An integer you want to search in matrix
	* @return: An integer indicate the total occurrence of target in the given matrix
	*/
	int searchMatrix(vector<vector<int> > &matrix, int target)
	{
		// write your code here
		int rowNum = matrix.size();
		if ( rowNum <= 0 ) return 0;
		int columnNum = matrix[0].size();
		if (columnNum <= 0) return 0;
		int row_i = 0;
		int column_i = columnNum - 1;
		int count = 0;
		while (row_i < rowNum && column_i >= 0)
		{
			if (matrix[row_i][column_i] == target)
			{
				count++;
				row_i++;
				column_i--;
			}
			else if(matrix[row_i][column_i] < target)
			{
				row_i++;
			}
			else
			{
				column_i--;
			}
		}
		return count;
	}
};

//int main()
//{
//	vector<vector<int>> nums = { {1,3,5,7},{2,4,7,8},{3,5,9,10} };
//	Solution s;
//	cout << s.searchMatrix(nums, 3);
//	return 0;
//}