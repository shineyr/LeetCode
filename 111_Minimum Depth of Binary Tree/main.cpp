#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
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
	TreeNode(int x) :val(x), left(NULL), right(NULL){}
};

class Solution {
public:
	int minDepth(TreeNode* root) {
		if (!root)
			return 0;
		//独立的根节点
		else if (!root->left && !root->right)
			return 1;
		else{
			int left_depth, right_depth;
			if (root->left)
				left_depth = minDepth(root->left);
			else
				left_depth = INT_MAX;
			if (root->right)
				right_depth = minDepth(root->right);
			else
				right_depth = INT_MAX;
			return min(left_depth, right_depth) + 1;
		}

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
	for (int i = 1; i < size; i+=2)
	{
		//处理队首节点的左右子树
		TreeNode *tmp = que.front();
		TreeNode *left = NULL , *right = NULL;
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

	vector<int> v = { 3,9};

	TreeNode *root = generateTree(v);
	
	int minDep = s.minDepth(root);

	cout << minDep << endl;

	system("pause");
	return 0;
}