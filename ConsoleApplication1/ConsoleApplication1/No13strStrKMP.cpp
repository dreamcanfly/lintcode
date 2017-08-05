#include "stdafx.h"
using namespace std;

class Solution {
public:
	/**
	* Returns a index to the first occurrence of target in source,
	* or -1  if target is not part of source.
	* @param source string to be scanned.
	* @param target string containing the sequence of characters to match.
	*/
	int strStr(const char *source, const char *target) 
	{
		// write your code here
		if (source == nullptr || target == nullptr) return -1;
		int sLen = strlen(source);
		int tLen = strlen(target);
		if (sLen < 0 || tLen < 0) return -1;
		if (tLen == 0) return 0;
		vector<int> next;
		if (!GetNext(target, next)) return -1;
		int i = -1, j = -1;
		while (i < sLen && j < tLen)
		{
			if (j == -1 || source[i] == target[j])
			{
				i++;
				j++;
			}
			else
			{
				j = next[j];
			}
		}
		if (j == tLen) return i - tLen;
		else
			return -1;
	}

	bool GetNext(const char* target, vector<int> &next)
	{
		int len = strlen(target);
		if (len <= 0) return false;
		next.resize(len);
		next[0] = -1;
		if (len == 1) return true;
		int i = 0, j = -1;
		while (i < len - 1)
		{
			if (j == -1 || target[i] == target[j])
			{
				i++;
				j++;
				if (target[i] != target[j])
					next[i] = j;
				else
					next[i] = next[j];
			}
			else
			{
				j = next[j];
			}
		}
		return true;
	}
};

//int main()
//{
//	Solution s;
//	cout << s.strStr("abcdabcdefg", "bcd");
//	return 0;
//}