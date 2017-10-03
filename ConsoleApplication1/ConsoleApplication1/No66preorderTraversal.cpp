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
	* @param root: A Tree
	* @return: Preorder in ArrayList which contains node values.
	*/
	vector<int> preorderTraversal(TreeNode * root) 
	{
		// write your code here
		if (root == NULL) return vector<int>();
		vector<int> res(1,root->val);
		vector<int> left = preorderTraversal(root->left);
		vector<int> right = preorderTraversal(root->right);
		
		if(left.size() > 0)
			res.insert(res.end(), left.begin(), left.end());
		if(right.size() > 0)
			res.insert(res.end(), right.begin(), right.end());
		return res;
	}
};