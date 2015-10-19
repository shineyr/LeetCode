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

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL){}
};

class Solution {
public:
	void flatten(TreeNode* root) {
		if (!root || (!root->left && !root->right))
			return;

		preTraverse(root);

		TreeNode *p = root;
		//节点个数
		int size = preT.size();

		for (int i = 1; i < size; ++i)
		{
			p->left = NULL;
			p->right = new TreeNode(preT[i]);
			p = p->right;
		}
	}

public:
	//先序遍历
	vector<int> preT;
	void preTraverse(TreeNode *root)
	{
		if (!root)
			return;
		preT.push_back(root->val);
		preTraverse(root->left);
		preTraverse(root->right);
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
	vector<int> v = { 1,flag,2,3 };
	TreeNode *root = generateTree(v);

	Solution s;

	s.flatten(root);

	system("pause");

	return 0;
}