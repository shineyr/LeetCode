#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>

using namespace std;

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(NULL){}
};

struct  TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int val) : val(val), left(NULL), right(NULL) {}
};


class Solution {
public:
	TreeNode* sortedListToBST(ListNode* head) {
		if (head == NULL)
			return NULL;

		int size = 0;
		ListNode *p = head;
		while (p)
		{
			++size;
			p = p->next;
		}

		ListNode *l = head, *r = NULL;

		//查找中间节点，用于构造二叉树根节点
		ListNode *pre = head;
		p = head;

		int i = 0;
		while (p && i < size / 2)
		{
			pre = p;
			p = p->next;
			++i;
		}

		//p节点作为根节点
		TreeNode *root = new TreeNode(p->val);

		
		// 其余节点为右子树
		r = p->next;

		//之前节点为左子树
		if (pre->next == p)
			pre->next = NULL;
		else //当前树中只有一个节点，则左子树为空
			l = NULL;

		root->left = sortedListToBST(l);
		root->right = sortedListToBST(r);
		return root;
	}
};

ListNode *insert(ListNode *head, int val)
{
	if (head == NULL)
	{
		head = new ListNode(val);
		return head;
	}
	else{
		ListNode *tmp = new ListNode(val);

		ListNode *p = head;
		while (p->next)
		{
			p = p->next;
		}
		p->next = tmp;
		return head;
	}
}

int main()
{
	Solution s;

	ListNode *head = NULL;
	for (int i = 1; i < 5; ++i)
		head = insert(head, i);

	TreeNode *root = s.sortedListToBST(head);

	system("pause");
	return 0;
}