#include "stdafx.h"
#include <regex>
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
	/**
	* This method will be invoked first, you should design your own algorithm
	* to serialize a binary tree which denote by a root node to a string which
	* can be easily deserialized by your own "deserialize" method later.
	*/
	string serialize(TreeNode * root) {
		// write your code here
		string res;
		SerializeCur(root, res);
		return res;
	}

	void SerializeCur(TreeNode* root, string & result)
	{
		if(root == NULL)
		{
			result += "$,";
			return;
		}
		result += (to_string(root->val) + ",");
		SerializeCur(root->left, result);
		SerializeCur(root->right, result);
	}

	/**
	* This method will be invoked second, the argument data is what exactly
	* you serialized at method "serialize", that means the data is not given by
	* system, it's given by your own serialize method. So the format of data is
	* designed by yourself, and deserialize it here as you serialize it in
	* "serialize" method.
	*/
	TreeNode * deserialize(string &data) 
	{
		// write your code here
		int pos = 0;
		TreeNode* root = Deserial(data, pos);
		return root;
	}

	TreeNode* Deserial(string &data, int &pos)
	{
		if (pos == data.size())
		{
			return NULL;
		}
		string num = "";
		if (data[pos] == '$')
		{
			pos += 1;
			return NULL;
		}
		while (data[pos] >= '0' && data[pos] <= '9' && pos < data.size())
		{
			num += data[pos];
			pos++;
		}
		if (pos == data.size()) return NULL;
		if (data[pos] != ',') return NULL;
		TreeNode* root = new TreeNode(stoi(num));
		root->left = Deserial(data, ++pos);
		root->right = Deserial(data, ++pos);
		return root;
	}
};

//int main()
//{
//	TreeNode* root = new TreeNode(1);
//	root->right = new TreeNode(2);
//	Solution s;
//	string ss = s.serialize(root);
//	cout << ss;
//	TreeNode* myroot = NULL;
//	myroot = s.deserialize(ss);
//	cout << myroot->val << endl;
//	return 0;
//}