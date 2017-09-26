#include "stdafx.h"
using namespace std;

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
	/*
	* @param head: The first node of linked list.
	* @return: True if it has a cycle, or false
	*/
	bool hasCycle(ListNode * head) 
	{
		// write your code here
		if (head == NULL || head->next == NULL) return false;
		ListNode* first = head;
		ListNode* second = head;
		while (first->next != NULL)
		{
			first = first->next;
			if(first->next == NULL)
			{
				return false;
			}
			else first = first->next;
			second = second->next;
			if (first == second) return true;
		}
		return false;
	}
};

