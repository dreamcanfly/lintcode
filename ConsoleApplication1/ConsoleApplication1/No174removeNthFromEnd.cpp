#include "stdafx.h"
using namespace	std;


 //Definition of ListNode
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
	* @param n: An integer.
	* @return: The head of linked list.
	*/
	ListNode *removeNthFromEnd(ListNode *head, int n) 
	{
		// write your code here
		ListNode* pre = head;
		ListNode* back = head;
		while (pre)
		{
			pre = pre->next;
			if (n >= 0)
				n--;
			else
				back = back->next;
		}
		if (back == head) return head->next;
		back->next = back->next->next;
		return head;
	}
};


