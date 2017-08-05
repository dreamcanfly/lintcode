#include "stdafx.h"
using namespace std;

class Solution {
public:
	/**
	*@param A: A list of integers
	*@param elem: An integer
	*@return: The new length after remove
	*/
	int removeElement(vector<int> &A, int elem) 
	{
		// write your code here
		int size = A.size();
		if (size <= 0) return 0;
		int left = 0;
		int right = size - 1;
		int NumOfElem = 0;
		while (left < right)
		{
			while (left < right && A[left] != elem)
			{
				left++;
			}
			while (left < right && A[right] == elem)
			{
				right--;
				NumOfElem++;
			}
			if (left < right)
			{
				Swap(A, left, right);
				left++;
				right--;
				NumOfElem++;
			}
		}
		if (left == right && A[left] == elem)
			NumOfElem++;
		A.erase((A.end() - NumOfElem), A.end());
		//A.resize(size - NumOfElem);
		return size - NumOfElem;
	}

	void Swap(vector<int> &A, int left, int right)
	{
		int temp = A[left];
		A[left] = A[right];
		A[right] = temp;
	}
};

//int main()
//{
//	Solution s;
//	vector<int> A = { 2,2,3 };//{ 0,0,0,4,2,4,5,6,4,4,3,0 };
//	cout << s.removeElement(A, 3) << endl;
//	for (int i = 0; i < A.size(); i++)
//	{
//		cout << A[i] << endl;
//	}
//	for (vector<int>::iterator iter = A.begin(); iter != A.end(); iter++)
//	{
//		cout << *iter << " ";
//	}
//	return 0;
//}