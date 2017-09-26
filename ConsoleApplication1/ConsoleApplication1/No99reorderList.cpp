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
	* @param head: The head of linked list.
	* @return: nothing
	*/
	//思想：先找到链表的中点，然后对后续链表进行反转，然后再合并。
	void reorderList(ListNode * head) 
	{
		// write your code here
		if(head == NULL || head->next == NULL) return;
		ListNode* slow = head;
		ListNode* fast = head->next;
		while (fast != NULL && fast->next != NULL)
		{
			fast = fast->next->next;
			slow = slow->next;
		}

		ListNode* mid = slow->next;
		slow->next = NULL;
		ListNode* newHead = NULL;
		while (mid != NULL)
		{
			ListNode* temp = mid->next;
			mid->next = newHead;
			newHead = mid;
			mid = temp;
		}

		ListNode* head1 = head;
		ListNode* head2 = newHead;
		int i = 0;
		
		while (head1 != NULL && head2 != NULL)
		{
			ListNode* head1Next = head1->next;
			ListNode* head2Next = head2->next;
			head1->next = head2;
			head2->next = head1Next;
			head1 = head1Next;
			head2 = head2Next;
		}
	}
};