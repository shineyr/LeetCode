#include <iostream>
#include <cstdlib>

using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	//方法一：头插法
	ListNode* reverseList(ListNode* head) {
		if (head == NULL)
			return head;

		//反转，即将所有节点按照头插法重新插入一遍即可
		ListNode *p = head->next;
		head->next = NULL;
		while (p)
		{
			//保存p的后续节点
			ListNode *r = p->next;
			p->next = head;
			head = p;
			p = r;
		}
		return head;
	}

	//方法二：递归实现
	ListNode* reverseList2(ListNode* head) {
		if (head == NULL)
			return head;

		ListNode *p = head;

		//反转其余节点组成的链表，将头结点链接到尾部
		if (head->next)
		{
			head = reverseList(head->next);
			ListNode *r = head;
			while (r->next)
				r = r->next;
			r->next = p;
		}			
		p->next = NULL;
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
	head = insert(head, 6);
	head = insert(head, 3);
	head = insert(head, 4);
	head = insert(head, 5);
	head = insert(head, 6);
	display(head);


	head = s.reverseList2(head);

	display(head);
	system("pause");
	return 0;

}