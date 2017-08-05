#include "stdafx.h"
#include <map>
using namespace std;

class Solution {
public:
	/**
	*@param A: A positive integer which has N digits, A is a string.
	*@param k: Remove k digits.
	*@return: A string
	*/
	string DeleteDigits(string A, int k) 
	{
		// wirte your code here
		int size = A.size();
		if (size <= k) return "";
		if (k == 0) return A;
		int numToDelete = k;
		while (k)
		{
			int newsize = size + k - numToDelete;
			if (newsize == 1) return "";
			if(newsize == 2)
			{
				A.erase(A[0] > A[1] ? 0 : 1, 1);
				k--;
			}
			else
			{
				if (A[0] > A[1])
				{
					A.erase(0, 1);
					k--;
				}
				else
				{
					int i = 1;
					for (; i < newsize - 1; i++)
					{
						if (A[i] >= A[i - 1] && A[i] > A[i + 1])
						{
							A.erase(i, 1);
							k--;
							break;
						}
					}
					if (i == newsize - 1)
					{
						A.erase(newsize - 1, 1);
						k--;
					}
				}
			}
		}
		int i = 0;
		while (A[0] == '0' && A.length() > 1)
		{
			A.erase(0,1);
		}
		return A;
	}
};


//int main()
//{
//	string a = "90249";
//	Solution s;
//	cout << s.DeleteDigits(a,2);
//	return 0;
//}