#include <iostream>
#include <cstdlib>
#include <vector>
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

const int flag = INT_MIN;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

class Solution {
public:
	
	//节点p,q为两个逆序节点 ， pre为遍历当前root节点的前驱
	TreeNode *p = NULL, *q = NULL, *pre = NULL;

	void recoverTree(TreeNode* root) {
		if (!root)
			return;
		//中序遍历二叉树，查找需要逆序节点
		InOrder(root);

		if (p && q)
		{
			int tmp = p->val;
			p->val = q->val;
			q->val = tmp;
		}//if
	}

	//中序遍历二叉树root，同时查找树中逆序节点p , q
	void InOrder(TreeNode *root)
	{
		if (!root)
			return;
		if (root->left)
			InOrder(root->left);
		if (pre != NULL && pre->val > root->val)
		{
			if (!p)
				p = pre;

			q = root;
		}//if
		pre = root;
		if (root->right)
			InOrder(root->right);
	}

};

TreeNode *generateTree(vector<int> &nums)
{
	if (nums.empty())
		return NULL;

	TreeNode *root = new TreeNode(nums[0]);
	queue<TreeNode *> que;
	que.push(root);
	//求出所给元素个数，对应二叉查找树节点个数
	int size = nums.size();
	for (int i = 1; i < size; i += 2)
	{
		//处理队首节点的左右子树
		TreeNode *tmp = que.front();
		TreeNode *left = NULL, *right = NULL;
		//定义非空左子树
		if (nums[i] != flag)
		{
			left = new TreeNode(nums[i]);
			que.push(left);
		}

		//定义非空右子树
		if (i + 1 < size && nums[i + 1] != flag)
		{
			right = new TreeNode(nums[i + 1]);
			que.push(right);
		}

		tmp->left = left;
		tmp->right = right;
		//弹出当前处理的节点
		que.pop();
	}
	return root;
}


int main()
{
	Solution s;
	vector<int> v = { 4, 2, 5, 3, 1 };

	TreeNode *root = generateTree(v);

	s.recoverTree(root);

	system("pause");

	return 0;
}