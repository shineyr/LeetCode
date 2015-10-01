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
	bool isSameTree(TreeNode* p, TreeNode* q) {
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
				return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
		}
	}
};

//int main()
//{
//	Solution s;
//
//
//}