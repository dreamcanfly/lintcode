#include "stdafx.h"
#include <algorithm>
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



class Solution
{
public:
	/*
	* @param root: The root of binary tree.
	* @return: True if this Binary tree is Balanced, or false.
	*/
	bool isBalanced(TreeNode * root)
	{
		// write your code here
		if (root == NULL) return true;
		int leftDepth = maxDepth(root->left);
		int rightDepth = maxDepth(root->right);
		if(abs(leftDepth - rightDepth) > 1)
		{
			return false;
		}
		return isBalanced(root->left) && isBalanced(root->right);
	}

	int maxDepth(TreeNode *root)
	{
		// write your code here
		if (root == NULL) return 0;
		int leftDepth = maxDepth(root->left);
		int rightDepth = maxDepth(root->right);
		return max(leftDepth, rightDepth) + 1;
	}
};

class Solution2 {
public:
	/*
	* @param root: The root of binary tree.
	* @return: True if this Binary tree is Balanced, or false.
	*/
	//http://blog.csdn.net/zhaojinjia/article/details/11891523
	bool isBalanced(TreeNode * root)
	{
		// write your code here
		int depth = 0;
		return myBalance(root, depth);
	}

	bool myBalance(TreeNode* root, int &depth)
	{
		if(root == NULL)
		{
			depth = 0;
			return true;
		}

		int lDepth = 0;
		int rDepth = 0;
		bool lBalance = myBalance(root->left, lDepth);
		bool rBalance = myBalance(root->right, rDepth);

		if(lBalance && rBalance)
		{
			if(abs(lDepth - rDepth) <= 1)
			{
				depth = max(lDepth, rDepth) + 1;
				return true;
			}
		}
		return false;
	}
};