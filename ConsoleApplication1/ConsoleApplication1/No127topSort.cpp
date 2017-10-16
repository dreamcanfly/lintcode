#include "stdafx.h"
#include <map>
#include <queue>
using namespace	std;

//Definition for Directed graph.
struct DirectedGraphNode {
    int label;
    vector<DirectedGraphNode *> neighbors;
    DirectedGraphNode(int x) : label(x) {};
};


class Solution {
public:
	/*
	* @param graph: A list of Directed graph node
	* @return: Any topological order for the given graph.
	*/
	vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*>& graph) 
	{
		// write your code here
		vector<DirectedGraphNode*> result;
		int size = graph.size();
		if (size <= 0) return result;
		map<DirectedGraphNode*, int> inDegree;
		queue<DirectedGraphNode*> inZero;
		
		//找到每个结点的入度
		for(auto e:graph)
		{
			for(auto item:e->neighbors)
			{
				++inDegree[item];
			}
		}
		
		//将入度为0的结点放入队列
		for(auto e:graph)
		{
			if(inDegree[e] == 0)
			{
				inZero.push(e);
			}
		}
		
		//循环处理，将入度为0的结点依次删除，然后将其后继结点的入度减一
		while (!inZero.empty())
		{
			auto node = inZero.front();
			inZero.pop();
			result.push_back(node);
			for(auto item: node->neighbors)
			{
				if(--inDegree[item] == 0)
				{
					inZero.push(item);
				}
			}
		}
		return result;
	}


};