#include "stdafx.h"
using namespace std;

class Solution {
public:
	/**
	*@param n: Given a decimal number that is passed in as a string
	*@return: A string
	*/
	string binaryRepresentation(string n) 
	{
		// wirte your code here
		int size = n.size();
		if (size <= 0) return "";
		int pointPos = n.find_first_of('.');
		int integerPos = pointPos - 1;
		int decimalPos = pointPos + 1;
		string binaryStr;
		int i = 0;
		if (n[i] == '+' || n[i] == '-')
		{
			binaryStr += n[i];
			i++;
		}
		int integerNum = 0;
		while (i <= integerPos)
		{
			integerNum = integerNum * 10 + (n[i] - '0');
			i++;
		}
		string integerStr = GetBinaryStr(integerNum);
		if (integerStr == "")
			binaryStr += "0";
		else
		{
			binaryStr += integerStr;
		}
		double decimalNum = 0.0;
		int j = size - 1;
		while (j >= decimalPos)
		{
			decimalNum = (decimalNum + (n[j] - '0')) / 10;
			j--;
		}
		string decimalStr = GetBinaryStr(decimalNum);
		if (decimalStr == "ERROR")
			binaryStr = decimalStr;
		else if(decimalStr != "")
		{
			binaryStr += '.';
			binaryStr += decimalStr;
		}
		return binaryStr;
	}

	string GetBinaryStr(int num)
	{
		vector<int> binaryExpress;
		while (num > 0)
		{
			int temp = num % 2;
			num = num / 2;
			binaryExpress.push_back(temp);
		}
		string res = "";
		for(int i = binaryExpress.size() - 1; i >= 0; i--)
		{
			res += (binaryExpress[i] + '0');
		}
		return res;
	}

	string GetBinaryStr(double num)
	{
		string res = "";
		int count = 0;
		while (num != 0.0 && count < 32)
		{
			num *= 2;
			if (num < 1) res += '0';
			else if (num >= 1)
			{
				res += '1';
				num -= 1;
			}
			count++;
		}	
		if (count >= 32 && num != 0.0)
			res = "ERROR";
		return res;
	}
};


//int main()
//{
//	string n = "4096.6435546875";
//	Solution s;
//	cout << s.binaryRepresentation(n);
//	return 0;
//}