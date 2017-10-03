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
	/**
	*@param preorder : A list of integers that preorder traversal of a tree
	*@param inorder : A list of integers that inorder traversal of a tree
	*@return : Root of a tree
	*/
public:
	TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
	{
		// write your code here
		int size = preorder.size();
		if (size != inorder.size()) return NULL;
		if (size <= 0) return NULL;
		return BuildTreeRecurrnce(preorder, inorder, 0, 0, size);
	}

	TreeNode* BuildTreeRecurrnce(vector<int>& pre, vector<int> &in, int prePos, int inPos, int len)
	{
		if (len <= 0) return NULL;
		if (prePos > pre.size()) return NULL;
		if (inPos > in.size()) return NULL;
		TreeNode* root = new TreeNode(pre[prePos]);
		int i = inPos;
		for(; i < inPos + len; i++)
		{
			if(in[i] == pre[prePos])
			{
				break;
			}
		}
		if(i == inPos + len) //判断如果没有找到根节点，说明数组有问题
		{
			return NULL;
		}
		int leftLen = i - inPos;
		int rightLen = len - leftLen - 1;
		root->left = BuildTreeRecurrnce(pre, in, prePos + 1, inPos, leftLen);
		root->right = BuildTreeRecurrnce(pre, in, prePos + leftLen + 1, i + 1, rightLen);
		return root;
	}
};

//int main()
//{
//	vector<int> pre = { 1,2 };
//	vector<int> in = { 2,1 };
//	Solution s;
//	s.buildTree(pre, in);
//	return 0;
//}