#include "stdafx.h"
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
public:
	/*
	* @param start: a string
	* @param end: a string
	* @param dict: a set of string
	* @return: An integer
	*/

	static struct status
	{
		string s;
		int len;
	};

	int ladderLength(string &start, string &end, unordered_set<string> &dict)
	{
		// write your code here
		queue<status> Q;
		if (start.size() != end.size()) return 0;
		if (start.empty() || end.empty() || dict.empty()) return 0;
		if (start == end) return 1;
		status s0;
		s0.s = start;
		s0.len = 1;
		Q.push(s0);
		dict.erase(s0.s);
		dict.insert(end);

		while (dict.size() > 0 && Q.size() > 0)
		{
			status stemp = Q.front();
			Q.pop();
			
			for (int i = 0; i < stemp.s.length(); i++)
			{
				for (char ch = 'a'; ch <= 'z'; ch++)
				{
					status ss = stemp;
					if(ss.s[i] == ch) continue;
					ss.s[i] = ch;
					if (dict.find(ss.s) != dict.end())
					{
						ss.len++;
						Q.push(ss);
						dict.erase(ss.s);
					}
					if(ss.s == end)
					{
						return ss.len;
					}
				}
			}
		}
		return 0;
	}
};

//int main()
//{
//	unordered_set<string> sets = { "hot","dot","dog","lot","log" };
//	string a1 = "hit";
//	string a2 = "cog";
//	Solution s;
//	cout << s.ladderLength(a1, a2, sets);
//	return 0;
//}