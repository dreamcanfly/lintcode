#include "stdafx.h"
using namespace std;

class Solution {
public:
	/**
	*@param a, b: Two integer
	*return: An integer
	*/
	//�����뷨�����Ƚ�2�������Ȼ���ټ�������1��λ��
	//�ҵ�һЩ�취���Լ���2������1�ĸ���

	//���ܼ��㸺������������
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

	//�������ƣ����Լ��㸺��,����ÿ�ζ�Ҫѭ��32λ,����ֻ����32λ����Ϊ��������ʹ�߼����ƣ��Ჹ1��
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

	//����һ�������ϱ���С1����������ʹ�����������һλ1����
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

	//�ڴ��������ʱ�򽫲�����ʽת��Ϊunsigned int
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
//	//��ʵ֤������һ�ַ������ܻ�ȡ������0�ĸ���
//}