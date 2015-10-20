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
	
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		if (!root)
			return vector<vector<int>>();
		
		//存储所有满足条件的路径
		vector<vector<int> > paths;

		//存储当前遍历路径
		vector<int> tmp;

		getPaths(root, sum, paths, tmp);

		return paths;
		
	}

	void getPaths(TreeNode *root, int sum, vector<vector<int> > &paths, vector<int> tmp)
	{
		if (!root)
			return;

		tmp.push_back(root->val);
		if (!root->left && !root->right && sum == root->val)
			paths.push_back(tmp);
		
		if (root->left)
			getPaths(root->left, sum - root->val, paths, tmp);

		if (root->right)
			getPaths(root->right, sum - root->val, paths, tmp);
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
	vector<int> v = { 5, 4, 8, 11, flag, 13, 4, 7, 2, flag, flag, 5, 1 };
	TreeNode *root = generateTree(v);

	Solution s;

	vector<vector<int> > ret = s.pathSum(root, 22);

	int size = ret.size();
	for (int i = 0; i < size; ++i)
	{
		int len = ret[i].size();
		cout << "[";
		for (int j = 0; j < len; ++j)
		{
			cout << "\t" << ret[i][j] << "\t";
		}
		cout << "]" << endl;
	}

	system("pause");

	return 0;
}