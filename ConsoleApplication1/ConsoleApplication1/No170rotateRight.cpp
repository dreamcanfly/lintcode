#include "stdafx.h"
using namespace std;

/**
Definition for singly-linked list.*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	/**
	* @param head: the list
	* @param k: rotate to the right k places
	* @return: the list after rotation
	*/
	ListNode *rotateRight(ListNode *head, int k) 
	{
		// write your code here
		ListNode* preNode = head;
		ListNode* tailNode = head;
		if (head == NULL || head->next == NULL) return head;
		int len = 1;
		while (tailNode->next != NULL)
		{
			tailNode = tailNode->next;
			len++;
		}
		if (k >= len)
		{
			k = k % len;
		}
		if (k == 0) return head;
		int loopTime = len - k - 1;
		while (loopTime > 0)
		{
			preNode = preNode->next;
			loopTime--;
		}
		tailNode->next = head;
		head = preNode->next;
		preNode->next = NULL;
		/*preNode = tailNode = head;
		while (preNode->next != NULL)
		{
			preNode = preNode->next;
			if(k <= 0)
			{
				tailNode = tailNode->next;
			}
			else
			{
				k--;
			}
		}
		preNode->next = head;
		head = tailNode->next;
		tailNode->next = NULL;*/
		
		return head;
	}
};
