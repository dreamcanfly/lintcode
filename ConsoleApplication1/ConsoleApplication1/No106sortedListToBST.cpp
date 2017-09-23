#include "stdafx.h"
using namespace std;

/**
 Definition of ListNode*/
class ListNode {
public:
	int val;
	ListNode *next;
	ListNode(int val) {
		this->val = val;
		this->next = NULL;
	}
};
// Definition of TreeNode:
class TreeNode {
public:
	int val;
	TreeNode *left, *right;
	TreeNode(int val) {
		this->val = val;
		this->left = this->right = NULL;
	}
};



class Solution {
public:
	/*
	* @param head: The first node of linked list.
	* @return: a tree node
	*/
	TreeNode * sortedListToBST(ListNode * head) {
		// write your code here
		vector<int> arr = ListToArr(head);
		return GetRoot(arr, 0, arr.size() - 1);
	}

	vector<int> ListToArr(ListNode* head)
	{
		vector<int> arr;
		ListNode* ptr = head;
		while (ptr != NULL)
		{
			arr.push_back(ptr->val);
			ptr = ptr->next;
		}
		return arr;
	}

	//想获得链表的中间结点，其实可以设置两个指针，一个比另一个跑的慢一步就好。
	TreeNode* GetRoot(vector<int> arr, int start, int end)
	{
		int size = arr.size();
		if (size == 0)
		{
			return NULL;
		}
		TreeNode* root = new TreeNode(0);
		if(start == end)
		{
			root->val = arr[start];
			return root;
		}
		int mid = start + (end - start) / 2;
		root->val = arr[mid];
		if(mid > 0 && mid - 1 >= start)
			root->left = GetRoot(arr, start, mid - 1);
		if(mid < size - 1 && mid + 1 <= end)
			root->right = GetRoot(arr, mid + 1, end);
		return root;
	}
};

ListNode* ArrToList(vector<int> arr)
{
	ListNode* root = new ListNode(arr[0]);
	ListNode* tmp = root;
	int size = arr.size();
	for(int i = 1; i < size; i++)
	{
		tmp->next = new ListNode(arr[i]);
		tmp = tmp->next;
	}
	return root;
}

//int main()
//{
//	vector<int> Arr = { -1,0,1,3 };
//	ListNode* root = ArrToList(Arr);
//	Solution s;
//	s.sortedListToBST(root);
//	return 0;
//}