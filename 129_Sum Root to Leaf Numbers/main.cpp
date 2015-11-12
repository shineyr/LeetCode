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

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL){}
};

class Solution {
public:
	int sumNumbers(TreeNode* root) {
		int ret = 0;
		if (!root)
			return ret;
		else if (!root->left && !root->right)
		{
			ret = root->val;
			return ret;
		}
		else
			dfs(root, root->val , ret);

		return ret;
	}

	//深度优先遍历，得到所有根节点到叶子节点的路径和
	void dfs(TreeNode *root, int val, int &sum)
	{
		if (!root->left && !root->right)
			sum += val;
		if (root->left)
		{
			dfs(root->left, val * 10 + root->left->val, sum);
		}

		if (root->right)
		{
			dfs(root->right, val * 10 + root->right->val, sum);
		}
	}
};

const int flag = INT_MIN;
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

	vector<int> v = { 1, 2, 3 };
	
	TreeNode *root = generateTree(v);

	int ret = s.sumNumbers(root);

	cout << ret << endl;

	system("pause");
	return 0;
}