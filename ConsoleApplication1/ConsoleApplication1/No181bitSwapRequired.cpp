#include "stdafx.h"
using namespace std;

class Solution {
public:
	/**
	*@param a, b: Two integer
	*return: An integer
	*/
	//初步想法就是先将2个数异或，然后再计算结果中1的位数
	//找到一些办法可以计算2个数中1的个数

	//不能计算负数，基础方法
	int countOneBits(int num)
	{
		int count = 0;
		while (num != 0)
		{
			if (num % 2 == 1)
				count++;
			num /= 2;
		}
		return count;
	}

	//运用右移，可以计算负数,但是每次都要循环32位,而且只能是32位，因为负数右移使逻辑右移，会补1的
	int countOneBits2(int num)
	{
		int count = 0;
		for(int i = 0; i < 32; i++)
		{
			if (num & 1 == 1)
				count++;
			num = num >> 1;
		}
		return count;
	}

	//利用一个数与上比其小1的数，可以使二进制中最后一位1消除
	int countOneBits3(int num)
	{
		int count = 0;
		while (num != 0)
		{
			count++;
			num = num & (num - 1);
		}
		return count;
	}

	//在传入参数的时候将参数隐式转换为unsigned int
	int countOneBits4(unsigned int num)
	{
		int count = 0;
		while (num != 0)
		{
			if (num % 2 == 1)
				count++;
			num /= 2;
		}
		return count;
	}

	int bitSwapRequired(int a, int b) 
	{
		// write your code here
		int c = a ^ b;
		return countOneBits2(c);
	}
};

//int main()
//{
//	int va = -1;
//	int vb = 14;
//	Solution s;
//	cout << s.bitSwapRequired(va, vb);
//	cout << (va >> 1);
//	return 0;
//	//事实证明，第一种方法不能获取负数的0的个数
//}