#include <iostream>
#include <cstdlib>
#include <queue>

using namespace std;

/**
* Definition for binary tree with next pointer.
* struct TreeLinkNode {
*  int val;
*  TreeLinkNode *left, *right, *next;
*  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
* };
*/

struct TreeLinkNode 
{
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL){}
};

class Solution {
public:
	//方法一：利用层次遍历的思想
	void connect1(TreeLinkNode *root) {
		if (!root)
			return;
		else if (!root->left && !root->right)
		{
			root->next = NULL;
			return;
		}

		queue<TreeLinkNode *> qt;
		qt.push(root);
		while (!qt.empty())
		{
			queue<TreeLinkNode *> tmp;
			TreeLinkNode *p = qt.front();
			//把 当前节点的 左右子节点压入临时队列
			if (p->left)
				tmp.push(p->left);
			if (p->right)
				tmp.push(p->right);

			qt.pop();

			while (!qt.empty())
			{
				TreeLinkNode *q = qt.front();
				p->next = q;

				p = q;

				//把 当前节点的 左右子节点压入临时队列
				if (q->left)
					tmp.push(q->left);
				if (q->right)
					tmp.push(q->right);

				qt.pop();
			}
			p->next = NULL;

			qt = tmp;
		}//while
		return;
	}
	//方法二：直接操作二叉树节点
	void connect(TreeLinkNode *root) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if (root == NULL)
			return;

		TreeLinkNode *p = root;
		TreeLinkNode *q = NULL;
		TreeLinkNode *nextNode = NULL;

		while (p)
		{
			if (p->left)
			{
				if (q)
					q->next = p->left;
				q = p->left;
				if (nextNode == NULL)
					nextNode = q;
			}

			if (p->right)
			{
				if (q)
					q->next = p->right;
				q = p->right;
				if (nextNode == NULL)
					nextNode = q;
			}

			p = p->next;
		}

		connect(nextNode);
	}
};

const int flag = INT_MIN;
TreeLinkNode *generateTree(vector<int> &nums)
{
	if (nums.empty())
		return NULL;

	TreeLinkNode *root = new TreeLinkNode(nums[0]);
	queue<TreeLinkNode *> que;
	que.push(root);
	//求出所给元素个数，对应二叉查找树节点个数
	int size = nums.size();
	for (int i = 1; i < size; i+=2)
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
	Solution s;

	vector<int> v = { 1, 2, 3, 4, 5, flag, 7 };
	
	TreeLinkNode *root = generateTree(v);

	s.connect(root);

	system("pause");
	return 0;
}