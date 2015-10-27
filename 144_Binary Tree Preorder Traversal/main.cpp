#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		if (!root)
			return vector<int>();

		preOrder.push_back(root->val);
		if (root->left)
			preorderTraversal(root->left);
		if (root->right)
			preorderTraversal(root->right);

		return preOrder;
	}

private:
	vector<int> preOrder;
};