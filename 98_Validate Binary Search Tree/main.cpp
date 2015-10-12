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
	/*
	 * 需要注意的是，左子树的所有节点都要比根节点小，
	 * 而非只是其左孩子比其小，右子树同样。
	 */
	bool isValidBST(TreeNode* root) {
		if (!root)
			return true;

		//二叉查找树的一个特点就是其中序遍历结果为一个递增序列，可作为用来判断
		InOrder(root);

		int size = ret.size();
		for (int i = 0; i < size - 1; ++i)
		{
			if (ret[i] >= ret[i + 1])
				return false;
		}//for
		return true;
	}

	//中序遍历二叉查找树
	void InOrder(TreeNode *root)
	{
		if (!root)
			return;

		InOrder(root->left);
		ret.push_back(root->val);
		InOrder(root->right);

	}

private:
	vector<int> ret;
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

	vector<int> v = { 1,0};

	TreeNode *root = generateTree(v);
	bool ret = s.isValidBST(root);

	cout << ret << endl;
	system("pause");
	return 0;
}