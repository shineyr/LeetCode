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
	vector<int> postorderTraversal(TreeNode* root) {
		if (!root)
			return vector<int>();
		if (root->left)
			postorderTraversal(root->left);
		if (root->right)
			postorderTraversal(root->right);
		postOrder.push_back(root->val);

		return postOrder;
	}

private:
	vector<int> postOrder;
};