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
	* @param root: The root of binary tree.
	* @return: True if the binary tree is BST, or false
	*/

	//����2���������������Ȼ���ж��Ƿ�Ϊ�������顣
	//�Ե�ǰ�����Լ�����ҽ��������ޣ��ݹ��ж�
	bool dfs(TreeNode* root, long min, long max)
	{
		if (root == NULL) return true;
		if (root->val >= max || root->val <= min) return false;
		return dfs(root->left, min, root->val) && dfs(root->right, root->val, max);
	}

	bool isValidBST(TreeNode * root)
	{
		// write your code here
		if (root == NULL) return true;
		return dfs(root, LONG_MIN, LONG_MAX);
	}
};