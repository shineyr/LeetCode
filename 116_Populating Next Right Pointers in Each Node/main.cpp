#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>

using namespace std;

const int flag = INT_MIN;


/**
* Definition for binary tree with next pointer.
* struct TreeLinkNode {
*  int val;
*  TreeLinkNode *left, *right, *next;
*  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
* };
*/

struct TreeLinkNode{
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
	void connect(TreeLinkNode *root) {
		if (!root)
			return;

		//定义两个队列，一个存储父节点
		queue<TreeLinkNode *> parent;
		parent.push(root);
		root->next = NULL;
		while (!parent.empty())
		{
			//定义队列存储当前子层
			queue<TreeLinkNode*> curLevel;
			while (!parent.empty())
			{
				TreeLinkNode *tmp = parent.front();
				parent.pop();
				if (tmp->left)
					curLevel.push(tmp->left);
				if (tmp->right)
					curLevel.push(tmp->right);

			}//while
			parent = curLevel;

			while (!curLevel.empty())
			{
				TreeLinkNode *p = curLevel.front();
				curLevel.pop();
				if (!curLevel.empty())
					p->next = curLevel.front();
				else
					p->next = NULL;
			}//while
		}//while
	}
};

TreeLinkNode *generateTree(vector<int> &nums)
{
	if (nums.empty())
		return NULL;

	TreeLinkNode *root = new TreeLinkNode(nums[0]);
	queue<TreeLinkNode *> que;
	que.push(root);
	//求出所给元素个数，对应二叉查找树节点个数
	int size = nums.size();
	for (int i = 1; i < size; i += 2)
	{
		//处理队首节点的左右子树
		TreeLinkNode *tmp = que.front();
		TreeLinkNode *left = NULL, *right = NULL;
		//定义非空左子树
		if (nums[i] != flag)
		{
			left = new TreeLinkNode(nums[i]);
			que.push(left);
		}

		//定义非空右子树
		if (i + 1 < size && nums[i + 1] != flag)
		{
			right = new TreeLinkNode(nums[i + 1]);
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
	vector<int> v = { 1, 2, 3, 4, 5, 6, 7 };
	TreeLinkNode *root = generateTree(v);

	Solution s;
	s.connect(root);

	system("pause");
	return 0;
}