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
	* @return: You should return the head of the sorted linked list, using constant space complexity.
	*/
	//思路：要求时间复杂度O(nlogn)，所以只能选择堆排序、归并排序、希尔排序，根据算法，选择归并排序
	ListNode * sortList(ListNode * head) {
		// write your code here
		if (head == NULL || head->next == NULL) return head;
		ListNode* fast = head->next;
		ListNode* slow = head;
		while (fast != NULL && fast->next != NULL)
		{
			fast = fast->next->next;
			slow = slow->next;
		}
		ListNode* newHead = slow->next;
		slow->next = NULL;
		ListNode* list1 = sortList(head);
		ListNode* list2 = sortList(newHead);
		ListNode* sorted = merge(list1, list2);
		return sorted;
	}

	ListNode* merge(ListNode* list1, ListNode* list2)
	{
		if (list1 == NULL) return list2;
		if (list2 == NULL) return list1;

		ListNode* head;
		ListNode* temp;

		if(list1->val < list2->val)
		{
			head = list1;
			list1 = list1->next;
		}
		else
		{
			head = list2;
			list2 = list2->next;
		}
		temp = head;

		while (list1 != NULL && list2 != NULL)
		{
			if(list1->val < list2->val)
			{
				temp->next = list1;
				temp = list1;
				list1 = list1->next;
			}
			else
			{
				temp->next = list2;
				temp = list2;
				list2 = list2->next;
			}
		}
		if (list1 != NULL) temp->next = list1;
		if (list2 != NULL) temp->next = list2;
		return head;
	}
};