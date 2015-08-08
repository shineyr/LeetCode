#include <iostream>
#include <cstdlib>

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
	ListNode(int x) : val(x), next(NULL){}
};

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		if (head == NULL || n == 0 )
			return head;

		//计算链表中的结点个数
		int count = 0;
		ListNode *p = head;
		while (p)
		{
			count++;
			p = p->next;
		}

		//链表中的结点个数小于要删除的倒数第n个
		if (count < n)
		{
			return head;
		}
		else if (count == n)
		{
			ListNode *tem = head;
			head = head->next;
			delete tem;
		}
		else{
			ListNode *p = head, *q = p->next;
			int i = 1;
			while (i < (count - n) && q->next!=NULL)
			{
				p = p->next;
				q = q->next;
				i++;
			}
			p->next = q->next;
			delete q;
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
	ListNode *head = NULL;
	for (int i = 1; i <= 10; i++)
	{
		head = insert(head, i);	
	}
	display(head);

	Solution *s = new Solution();
	for (int i = 0; i <= 11; i++)
	{
		head = s->removeNthFromEnd(head, i);
		display(head);
	}


	system("pause");
	return 0;
	
}