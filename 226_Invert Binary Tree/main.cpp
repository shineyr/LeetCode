#include <iostream>
#include <cstdlib>
#include <queue>

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
	TreeNode(int x) :val(x), left(NULL), right(NULL){}
};

class Solution {
public:
	//递归实现
	TreeNode* invertTree(TreeNode* root) {
		if (!root)
			return root;

		TreeNode *tmp = root->left;
		root->left = invertTree(root->right);
		root->right = invertTree(tmp);

		return root;
	}

	//非递归实现
	TreeNode* invertTree2(TreeNode* root) {
		if (root == NULL)
			return root;
		queue<TreeNode*> tree_queue;
		tree_queue.push(root);

		while (!tree_queue.empty()){
			TreeNode * pNode = tree_queue.front();
			tree_queue.pop();

			TreeNode * pLeft = pNode->left;
			pNode->left = pNode->right;
			pNode->right = pLeft;

			if (pNode->left)
				tree_queue.push(pNode->left);
			if (pNode->right)
				tree_queue.push(pNode->right);
		}
		return root;
	}
};