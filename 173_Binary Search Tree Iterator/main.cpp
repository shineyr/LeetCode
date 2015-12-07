#include <iostream>
#include <cstdlib>
#include <queue>

using namespace std;

/**
* Definition for binary tree
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

class BSTIterator {
public:
	BSTIterator(TreeNode *root) {	
		//中序遍历该二叉查找树，得到有序序列
		inOrder(root, inOrderNodes);
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		if (!inOrderNodes.empty())
			return true;
		return false;
	}

	/** @return the next smallest number */
	int next() {
		TreeNode *node = inOrderNodes.front();
		inOrderNodes.pop();
		return node->val;
	}
private:
	queue<TreeNode *> inOrderNodes;

	void inOrder(TreeNode *root, queue<TreeNode *> &inOrderNodes)
	{
		if (!root)
			return;
		if (root->left)
			inOrder(root->left, inOrderNodes);

		inOrderNodes.push(root);

		if (root->right)
			inOrder(root->right, inOrderNodes);
	}
};

/**
* Your BSTIterator will be called like this:
* BSTIterator i = BSTIterator(root);
* while (i.hasNext()) cout << i.next();
*/