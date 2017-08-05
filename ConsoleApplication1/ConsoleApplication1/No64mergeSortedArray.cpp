#include "stdafx.h"
using namespace std;

class Solution {
public:
	/**
	* @param A: sorted integer array A which has m elements,
	*           but size of A is m+n
	* @param B: sorted integer array B which has n elements
	* @return: void
	*/
	void mergeSortedArray(int A[], int m, int B[], int n) 
	{
		// write your code here
		if (m == 0) 
		{
			for (int i = 0; i < n; i++)
			{
				A[i] = B[i];
			}
			return;
		}
		
		int *ACopy = new int[m];
		for (int i = 0; i < m; i++)
		{
			ACopy[i] = A[i];
		}

		int posInACp = 0;
		int posInB = 0;
		int posInA = 0;
		while (posInACp < m && posInB < n)
		{
			while(posInACp < m && posInB < n && ACopy[posInACp] <= B[posInB])
			{
				A[posInA] = ACopy[posInACp];
				posInACp++;
				posInA++;
			}
			while(posInACp < m && posInB < n && ACopy[posInACp] > B[posInB])
			{
				A[posInA] = B[posInB];
				posInB++;
				posInA++;
			}
			
		}
		while (posInACp < m)
		{
			A[posInA] = ACopy[posInACp];
			posInA++;
			posInACp++;
		}
		while (posInB < n)
		{
			A[posInA] = B[posInB];
			posInA++;
			posInB++;
		}
	}
};

//int main()
//{
//	int A[] = { 1,2,3,6,0,0 };
//	int B[] = { 4,5 };
//	int m = 4;
//	int n = 2;
//	Solution s;
//	s.mergeSortedArray(A, m, B, n);
//	for (int i = 0; i < m + n; i++)
//	{
//		cout << A[i] << " ";
//	}
//	return 0;
//}