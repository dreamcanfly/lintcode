#include "stdafx.h"
#include <map>
using namespace std;

//Definition for singly-linked list with a random pointer.
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
	/**
	* @param head: The head of linked list with a random pointer.
	* @return: A new head of a deep copy of the list.
	*/
	//��ͳ�ⷨ������map�洢����������֮��Ķ�Ӧ��ϵ���ȿ�����������random��ֵ
	RandomListNode *copyRandomList(RandomListNode *head) 
	{
		// write your code here
		if (head == NULL)
			return NULL;
		RandomListNode* res = new RandomListNode(head->label);
		RandomListNode* node = res;
		RandomListNode* cur = head->next;
		map<RandomListNode*, RandomListNode*> mymap;
		mymap[head] = res;
		while (cur)
		{
			RandomListNode* temp = new RandomListNode(cur->label);
			node->next = temp;
			mymap[cur] = temp;
			node = node->next;
			cur = cur->next;
		}

		node = res;
		cur = head;
		while (node)
		{
			node->random = mymap[cur->random];
			node = node->next;
			cur = cur->next;
		}
		return res;
	}
	//����ⷨ����ÿ�����֮����һ����㣬Ȼ��randomָ��Ķ�ӦҲ�����һλ��ָ�룬������һ�����������Ϳ����ˣ�����map���Խ�ʡ�ռ俪��
	RandomListNode *copyRandomList2(RandomListNode *head)
	{
		// write your code here
		if (head == NULL)
			return NULL;
		RandomListNode* cur = head;
		while (cur)
		{
			RandomListNode* temp = new RandomListNode(cur->label);
			temp->next = cur->next;
			cur->next = temp;
			cur = temp->next;
		}

		cur = head;
		while (cur)
		{
			if(cur->random)
				cur->next->random = cur->random->next;
			cur = cur->next->next;
		}

		cur = head;
		RandomListNode* res = head->next;
		RandomListNode* node = res;
		while (cur)
		{
			cur->next = node->next;
			if(node->next)
				node->next = node->next->next;
			cur = cur->next;
			node = node->next;
		}
		return res;
	}
};