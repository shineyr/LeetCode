#include <iostream>
#include <cstdlib>
#include <stack>

using namespace std;

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(NULL){}
};

class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		if (head == NULL || m < 1 || n<1 || m >= n)
			return head;

		int len = 0;
		ListNode *p = head;
		//计算链表长度
		while (p)
		{
			len++;
			p = p->next;
		}
		//如果要反转的范围不符合要求则返回
		if (m > len || n > len)
			return head;

		//声明一个栈，用来保存要求反转的子序列所有节点
		stack<ListNode *> stk;
		
		if (m == 1)
		{
			//若从头节点反转，特殊处理
			ListNode *r = head;
			while (m <= n && r != NULL)
			{
				stk.push(r);
				r = r->next;
				++m;
			}
			//新的头结点
			head = stk.top();
			stk.pop();
			//链接剩下节点
			ListNode *q = head;
			while (!stk.empty())
			{
				q->next = stk.top();
				q = q->next;
				stk.pop();
			}
			//链接尾节点
			q->next = r;
			return head;
		}
		else{
			ListNode *pre = head;
			//找到要反转的第一个节点的前驱并保存
			int i = 1;
			while (i < m - 1)
			{
				pre = pre->next;
				++i;
			}

			//将所有反转节点入栈，并保存尾
			ListNode *r = pre->next;
			while (m <= n)
			{
				stk.push(r);
				r = r->next;
				++m;
			}//while

			//链接
			while (!stk.empty())
			{
				pre->next = stk.top();
				pre = pre->next;
				stk.pop();
			}
			pre->next = r;
			return head;
		}
		return head;
	}
};



ListNode * insert(ListNode *head, int val)
{
	ListNode *p = new ListNode(val);
	if (head == NULL)
	{
		head = p;
	}
	else{
		ListNode *q = head;
		while (q->next != NULL)
		{
			q = q->next;
		}
		q->next = p;
	}
	return head;
}

void display(ListNode *head)
{
	if (head == NULL)
		return;
	else if (head->next == NULL)
		cout << head->val << endl;
	else{
		ListNode *q = head;
		while (q->next)
		{
			cout << q->val << " -> ";
			q = q->next;
		}
		cout << q->val << endl;
	}
}

int main()
{
	Solution s;

	ListNode *head = NULL;

	head = insert(head, 1);
	head = insert(head, 2);
	head = insert(head, 3);
	head = insert(head, 4);
	head = insert(head, 5);
	display(head);


	head = s.reverseBetween(head , 3, 4);

	display(head);
	system("pause");
	return 0;

}