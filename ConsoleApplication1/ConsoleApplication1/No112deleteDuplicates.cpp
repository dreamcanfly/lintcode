#include "stdafx.h"
using namespace std;

/**
* Definition of ListNode*/
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
	* @return: head node
	*/
	ListNode *deleteDuplicates(ListNode *head) 
	{
		// write your code here
		if (head == NULL)
			return NULL;
		if (head->next == NULL)
			return head;

		ListNode* pList = head;
		while (pList->next != NULL)
		{
			ListNode* pListNext = pList->next;
			if(pList->val == pList->next->val)
			{
				pList->next = pListNext->next;
				delete pListNext;
			}
			else
			{
				pList = pListNext;
			}
		}
		return head;
	}
};