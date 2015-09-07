#include <iostream>
#include <cstdlib>

using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(NULL){}
};

class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		if (head == NULL)
			return head;

		ListNode *p = head;
		
		//求链表的长度
		int len = 0;
		while (p)
		{
			len++;
			p = p->next;
		}
		 
		k %= len;

		//k<=0时，原链表不旋转
		if (k <= 0)
			return head;

		int index = 1;		
		//寻找右旋k位置后，链表的首结点
		p = head;
		while (index < (len - k) && p->next != NULL)
		{
			index++;
			p = p->next;
		}

		ListNode *ret = p->next, *q = p;

		//原链表寻找尾结点，将其链接到head
		while (p->next)
			p = p->next;
		p->next = head;

		//前部分尾结点设为NULL
		q->next = NULL;
		return ret;

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
	for (int i = 1; i < 6; i++)
	{
		head = insert(head, i);
	}
	display(head);

	Solution s;
	
	
	head = s.rotateRight(head, 6);
	display(head);

	

	system("pause");
	return 0;

}