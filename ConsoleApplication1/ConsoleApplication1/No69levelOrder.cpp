#include "stdafx.h"
#include <queue>
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
	* @return: Level order a list of lists of integer
	*/
	vector<vector<int>> levelOrder(TreeNode * root) 
	{
		vector<vector<int>> result;
		if (root == NULL) return result;
		// write your code here
		vector<TreeNode*> curLevel;
		curLevel.push_back(root);
		while (curLevel.size() != 0)
		{
			vector<int> level;
			vector<TreeNode*> nextLevel;
			for(int i = 0; i < curLevel.size(); ++i)
			{
				level.push_back(curLevel[i]->val);
				if (curLevel[i]->left != NULL)
					nextLevel.push_back(curLevel[i]->left);
				if (curLevel[i]->right != NULL)
					nextLevel.push_back(curLevel[i]->right);
			}
			result.push_back(level);
			curLevel.assign(nextLevel.begin(), nextLevel.end());
		}
		return result;
	}
};