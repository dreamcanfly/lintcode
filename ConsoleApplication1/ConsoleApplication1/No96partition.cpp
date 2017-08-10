#include "stdafx.h"
#include <math.h>
#include <math.h>
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
	* @param x: an integer
	* @return: a ListNode
	*/
	ListNode *partition(ListNode *head, int x) 
	{
		if (head == NULL)
			return NULL;
		// write your code here
		ListNode* listptr = head;
		ListNode* pless = NULL;
		ListNode* phead = head;
		int count = 0;
		if (head->val < x)
			pless = head;
		while (listptr->next != NULL)
		{
			if(listptr->next->val < x)
			{
				if(count == 0 && pless == NULL)
				{
					pless = listptr->next;
					listptr->next = listptr->next->next;
					pless->next = head;
					phead = pless;
					count++;
					continue;
				}
				if(listptr->val < x)
				{
					pless = pless->next;
					listptr = listptr->next;
					continue;
				}
				ListNode* temp = pless->next;
				pless->next = listptr->next;
				listptr->next = listptr->next->next;
				pless->next->next = temp;
				pless = pless->next;
			}
			else
			{
				listptr = listptr->next;
			}
		}
		return phead;
	}
};

