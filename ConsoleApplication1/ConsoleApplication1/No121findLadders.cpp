#include "stdafx.h"
#include <unordered_set>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
	/*
	* @param start: a string
	* @param end: a string
	* @param dict: a set of string
	* @return: a list of lists of string
	*/
/*
	static struct status
	{
		string curStr;
		vector<string> curPath;
		unordered_set<string> curSet;
		status(string str, unordered_set<string> &set)
		{
			curStr = str;
			curPath.push_back(str);
			curSet = set;
		}
	};

	static vector<vector<string>> findLadders(string &start, string &end, unordered_set<string> &dict)
	{
		// write your code here
		vector<vector<string>> result;
		queue<status> my_queue;
		if (dict.empty()) return result;
		if (dict.find(start) != dict.end()) dict.erase(start);
		my_queue.push(status(start,dict));
		bool finded = false;
		int minlen = dict.size() + 2;
		while (!my_queue.empty())
		{
			status now = my_queue.front();
			my_queue.pop();
			if(now.curPath.size() >= minlen)
			{
				if(finded == true) continue;
				else break;
			}
			status temp = now;
			for(int i = 0; i < now.curStr.length(); i++)
			{
				for(char ch = 'a'; ch <= 'z'; ch++)
				{
					temp.curStr = now.curStr;
					temp.curPath = now.curPath;
					if(temp.curStr[i] == ch) continue;
					temp.curStr[i] = ch;
					if(temp.curStr == end)
					{
						temp.curPath.push_back(temp.curStr);
						minlen = temp.curPath.size();
						result.push_back(temp.curPath);
						finded = true;
						continue;
					}

					if( temp.curSet.find(temp.curStr) != temp.curSet.end() && !finded)
					{
						temp.curPath.push_back(temp.curStr);
						temp.curSet.erase(temp.curStr);
						my_queue.push(temp);
					}
				}
			}
		}
		return result;
	}*/
	vector<vector<string>> ans;
	vector<vector<string>> findLadders(string &start, string &end, unordered_set<string> &dict)
	{
		dict.insert(end);
		int dsize = dict.size();
		int len = start.length();
		unordered_map<string, vector<string>> next;
		unordered_map<string, int> steps;
		queue<string> que;
		vector<string> path;
		ans.clear();
		que.push(start);
		steps[start] = 0;
		while (!que.empty())
		{
			string s = que.front();
			que.pop();
			if(s == end) break;
			int step = steps[s];
			vector<string> snext;
			for(int i = 0; i < len; i++)
			{
				string news = s;
				for(char c = 'a'; c < 'z'; c++)
				{
					news[i] = c;
					if(c == s[i] || dict.find(news) == dict.end()) continue;
					if(steps.find(news) == steps.end())
					{
						que.push(news);
						steps[news] = step + 1;
					}
					snext.push_back(news);
				}
			}
			next[s] = snext;
		}
		path.push_back(start);
		dfsPath(path, next, steps, start, end);
		return ans;
	}

	void dfsPath(vector<string> &path, unordered_map<string, vector<string>> &next, unordered_map<string, int> &steps, string now, string end)
	{
		if (now == end)
			ans.push_back(path);
		else
		{
			auto vec = next[now];
			int stepn = steps[now];
			for(int i = 0; i < vec.size(); i++)
			{
				if(steps[vec[i]] != stepn + 1) continue;
				path.push_back(vec[i]);
				dfsPath(path, next, steps, vec[i], end);
				path.pop_back();
			}
		}
	}
};

	


//int main()
//{
//	unordered_set<string> myset = { "si","go","se","cm","so","ph","mt","db","mb","sb","kr","ln","tm","le","av","sm","ar","ci","ca","br","ti","ba","to","ra","fa","yo","ow","sn","ya","cr","po","fe","ho","ma","re","or","rn","au","ur","rh","sr","tc","lt","lo","as","fr","nb","yb","if","pb","ge","th","pm","rb","sh","co","ga","li","ha","hz","no","bi","di","hi","qa","pi","os","uh","wm","an","me","mo","na","la","st","er","sc","ne","mn","mi","am","ex","pt","io","be","fm","ta","tb","ni","mr","pa","he","lr","sq","ye" };
//	string start = "qa";
//	string end = "sq";
//	Solution s;
//	auto res = s.findLadders(start, end, myset);
//	for(int i = 0; i < res.size(); i++)
//	{
//		for(int j = 0; j < res[0].size(); j++)
//		{
//			cout << res[i][j] << " ";
//		}
//		cout << endl;
//	}
//	return 0;
//}