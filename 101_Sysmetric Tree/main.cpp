#include <iostream>
#include <cstdlib>

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
	bool isSymmetric(TreeNode* root) {
		if (!root)
			return true;
		else
			//判断左右子树是否对称
			return isSymmetricTree(root->left, root->right);
	}

	bool isSymmetricTree(TreeNode* p, TreeNode* q) {
		//如果两个二叉树均为空，则返回true
		if (!p && !q)
		{
			return true;
		}
		//如果两者其一为空树，则返回false
		else if (!p || !q)
		{
			return false;
		}
		else{
			if (p->val != q->val)
				return false;
			else
				//p左子树应与q右子树对称，同理，p右子树应与q左子树对称
				return isSymmetricTree(p->left, q->right) && isSymmetricTree(p->right, q->left);
		}
	}
};

int main()
{

}