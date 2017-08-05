#include "stdafx.h"
using namespace std;

class Solution {
public:
	/**
	* @paramn n: An integer
	* @return: An integer
	*/
	//f(n) = f(n-1)f(0) + f(n-2)f(1) + f(n-3)f(2) + ... f(1)f(n-2) + f(0)f(n -1)
	int numTrees(int n) 
	{
		// write your code here
		return f2(n);
	}

	int f(int n)//����ⲻ�����õݹ�ⷨ����Ϊ���ظ����㣬�ᵼ��ʱ�����ӣ���lintcode���԰�����26ms
	{
		if (n == 0) return 1;
		if (n == 1) return 1;
		if (n == 2) return 2;
		int sum = 0;
		if(n & 1 == 1)
		{
			for (int i = 0; i < (n - 1) / 2; i++)
			{
				sum += 2 * f(i) * f(n - 1 - i);
			}
			sum += f((n - 1) / 2) * f((n - 1) / 2);
		}
		else
		{
			for (int i = 0; i <= (n - 1) / 2; i++)
			{
				sum += 2 * f(i) * f(n - 1 - i);
			}
		}
		return sum;
	}

	int f2(int n) //DP�ⷨ��lintcode��ʱ��21ms���ڵݹ�ⷨ
	{
		vector<int> DP(n + 1);
		DP[0] = DP[1] = 1;
		for(int i = 2; i <= n; i++)
		{
			for(int j = 0; j < i; j++)
			{
				DP[i] += DP[j] * DP[i - 1 - j];
			}
		}
		return DP[n];
	}
};

//int main()
//{
//	int n = 5;
//	Solution s;
//	cout << s.numTrees(n);
//	return 0;
//}