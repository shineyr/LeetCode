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
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		//层次遍历，分层存储
		if (!root)
			return vector<vector<int> >();

		vector<vector<int> > ret;

		//定义两个队列，一个存储所有的父节点,另一个存储他们的子节点也就是子层
		queue<TreeNode *> parents;

		parents.push(root);

		while (!parents.empty())
		{
			//存储当前层的遍历结果
			vector<int> tmp;
			//定义队列存储他们的子节点也就是子层
			queue<TreeNode *> childs;
			while (!parents.empty())
			{
				TreeNode *node = parents.front();
				tmp.push_back(node->val);
				//弹出当前父节点
				parents.pop();

				if (node->left)
					childs.push(node->left);

				if (node->right)
					childs.push(node->right);
			}
			//存储当前层的遍历结果
			ret.push_back(tmp);
			//遍历下一层
			parents = childs;
		}
		//反转遍历结果 由下向上存储
		reverse(ret.begin(), ret.end());
		return ret;
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

	vector<int> v = { 3,9,20,flag,flag,15,7};

	TreeNode *root = generateTree(v);
	
	vector<vector<int>> ret = s.levelOrderBottom(root);

	for (size_t i = 0; i < ret.size(); ++i)
	{
		for (size_t j = 0; j < ret[i].size(); ++j)
		{
			cout << ret[i][j] << '\t';
		}
		cout << endl;
	}//for
	system("pause");
	return 0;
}