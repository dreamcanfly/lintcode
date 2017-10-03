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
	* @param value: Remove the node with given value.
	* @return: The root of the binary search tree after removal.
	*/
	TreeNode * removeNode(TreeNode * root, int value) 
	{
		// write your code here
		if (root == NULL) return NULL;
		if (root->val > value)
			root->left = removeNode(root->left, value);
		else if (root->val < value)
			root->right = removeNode(root->right, value);
		else
		{
			if(root->left == NULL || root->right == NULL)
			{
				root = (root->left != NULL) ? root->left : root->right;
			}
			else
			{
				TreeNode* cur = root->right;
				while (cur->left)
				{
					cur = cur->left;
				}
				root->val = cur->val;
				root->right = removeNode(root->right, cur->val);
			}
		}
		return root;
	}

	TreeNode* SearchTree(TreeNode* root, int value, TreeNode * parent)
	{
		if (root == NULL) return NULL;
		if (root->val == value)
			return root;
		parent = root;
		if (root->val > value)
			return SearchTree(root->left, value, parent);
		if (root->val < value)
			return SearchTree(root->right, value, parent);
	}
};