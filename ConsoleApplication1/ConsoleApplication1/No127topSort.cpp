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
		
		//�ҵ�ÿ���������
		for(auto e:graph)
		{
			for(auto item:e->neighbors)
			{
				++inDegree[item];
			}
		}
		
		//�����Ϊ0�Ľ��������
		for(auto e:graph)
		{
			if(inDegree[e] == 0)
			{
				inZero.push(e);
			}
		}
		
		//ѭ�����������Ϊ0�Ľ������ɾ����Ȼ�����̽�����ȼ�һ
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