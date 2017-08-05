#include "stdafx.h"
using namespace std;

class Solution {
public:
	/**
	* @param matrix, a list of lists of integers
	* @param target, an integer
	* @return a boolean, indicate whether matrix contains target
	*/
	bool searchMatrix(vector<vector<int> > &matrix, int target)
	{
		// write your code here
		int size = matrix.size();
		if (size <= 0) return false;
		for(int i = 0; i < size; i++)
		{
			if (matrix[i].size() <= 0) return false;
		}
		int leftRow = 0;
		int rightRow = size - 1;
		while (leftRow <= rightRow)
		{
			int midRow = (leftRow + rightRow) / 2;
			if (matrix[midRow][0] == target)
				return true;
			else if (matrix[midRow][0] > target)
				rightRow = midRow - 1; 
			else
				leftRow = midRow + 1;
		}
		if (rightRow < 0) return false;
		int columnCount = rightRow;
		int leftColumn = 0;
		int rightColumn = matrix[columnCount].size() - 1;
		while (leftColumn <= rightColumn)
		{
			int midColumn = (leftColumn + rightColumn) / 2;
			if (matrix[columnCount][midColumn] == target)
				return true;
			else if (matrix[columnCount][midColumn] > target)
				rightColumn = midColumn - 1;
			else
				leftColumn = midColumn + 1;
		}
		return false;
	}
};

//这个题需要考虑各种越界的情况
//int main()
//{
//	vector<vector<int>> nums = { {1,3,5,6},{10,11,16,20},{23,30,34,50} };
//	Solution s;
//	cout << s.searchMatrix(nums, 30);
//	return 0;
//}