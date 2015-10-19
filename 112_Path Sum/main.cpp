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
	bool hasPathSum(TreeNode* root, int sum) {
		//空树返回false
		if (root == NULL)
		{
			return false;
		}
		//若是叶子节点，判断返回
		else if (!root->left && !root->right)
		{
			if (root->val == sum)
				return true;
			else
				return false;
		}
		else
		{
			//否则，递归判断左右子树
			sum -= root->val;

			return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
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
	vector<int> v = { 5, 4, 8, 11,flag , 13, 4, 7, 2, flag, flag, flag, 1 };
	TreeNode *root = generateTree(v);

	Solution s;

	cout << s.hasPathSum(root, 22) << endl;

	system("pause");

	return 0;
}