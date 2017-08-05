#include "stdafx.h"
#include <algorithm>
using namespace std;

class Solution {
public:
	/**
	* @param A: a vector of integers
	* @return: an integer
	*/
	int firstMissingPositive(vector<int> A) 
	{
		// write your code here
		int size = A.size();
		if (size <= 0) return 1;
		sort(A.begin(), A.end());
		int num = 1;
		for (int i = 0; i < size; i++)
		{
			if (A[i] <= 0)
				continue;
			else
			{
				if (i != 0 && A[i] == A[i - 1])
				{
					continue;
				}
				else if (num == A[i])
				{
					num++;
				}
				else
				{
					break;
				}
			}
		}
		return num;
	}

	int firstMissingPositive2(vector<int> A)
	{
		int size = A.size();
		if (size <= 0) return 1;
		for (int i = 0; i < size; i++)
		{
			if (A[i] > 0)
			{
				if (A[i] == i + 1)
					continue;
				while (A[i] > 0 && A[i] < i+1 && A[i] != A[A[i] - 1])
				{
					Swap(A, i, A[i] - 1);
				}
			}
		}

		for (int i = 0; i < size; i++)
		{
			if (A[i] != i + 1)
				return i + 1;
		}
		return size + 1;
	}

	void Swap(vector<int>&vec, int left, int right)
	{
		int temp = vec[left];
		vec[left] = vec[right];
		vec[right] = temp;
	}
};

//int main()
//{
//	vector<int> A = { -1,4,2,1,9,10 };
//	Solution s;
//	cout << s.firstMissingPositive2(A);
//	return 0;
//}