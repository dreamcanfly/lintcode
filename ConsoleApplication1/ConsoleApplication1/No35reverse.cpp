#include "stdafx.h"
using namespace std;

/**
* Definition of ListNode
**/
 class ListNode {
 public:
     int val;
     ListNode *next;

     ListNode(int val) {
         this->val = val;
         this->next = NULL;
     }
 };

class Solution {
public:
	/**
	* @param head: The first node of linked list.
	* @return: The new head of reversed linked list.
	*/
	ListNode *reverse(ListNode *head)
	{
		ListNode* pReversedHead = NULL;
		ListNode* pNode = head;
		ListNode* pPreNode = NULL;
		while (pNode)
		{
			ListNode* pNext = pNode->next;
			if (pNext == NULL)
				pReversedHead = pNode;
			pNode->next = pPreNode;
			pPreNode = pNode;
			pNode = pNext;
		}
		return pReversedHead;
	}
	ListNode *reverse1(ListNode *head) 
	{
		// write your code here
		
		ListNode* p1 = head;
		if (p1 == NULL)
			return NULL;
		ListNode* p2 = p1->next;
		if (p2 == NULL)
			return head;
		ListNode* p3 = p2->next;
		if (p3 == NULL)
		{
			p1->next = NULL;
			p2->next = p1;
			head = p2;
			return head;
		}
		while (p3 != NULL)
		{
			if (p1 == head)
				p1->next = NULL;
			p2->next = p1;
			p1 = p2;
			p2 = p3;
			p3 = p3->next;
		}
		p2->next = p1;
		head = p2;
		return head;
	}
};

