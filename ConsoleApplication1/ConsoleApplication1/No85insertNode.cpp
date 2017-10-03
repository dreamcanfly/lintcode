#include "stdafx.h"
using namespace std;

//Definition of TreeNode:
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
	* @param root: The root of the binary search tree.
	* @param node: insert this node into the binary search tree
	* @return: The root of the new binary search tree.
	*/
	TreeNode * insertNode(TreeNode * root, TreeNode * node) 
	{
		// write your code here
		if (root == NULL) return node;
		TreeNode* cur = root;
		TreeNode* last = cur;
		while (cur != NULL)
		{
			if(node->val > cur->val)
			{
				last = cur;
				cur = cur->right;
			}
			else if(node->val < cur->val)
			{
				last = cur;
				cur = cur->left;
			}
			else
			{
				return root;
			}
		}
		if (node->val > last->val) last->right = node;
		else last->left = node;
		return root;
	}
};