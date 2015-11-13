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
	ListNode(int x) :val(x), next(NULL){}
};

class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		if (!headA || !headB)
			return NULL;

		ListNode *p = headA, *q = headB;
		
		//求出输入两个链表的长度
		int lenA = 0, lenB = 0;
		while (p)
		{
			++lenA;
			p = p->next;
		}//while

		while (q)
		{
			++lenB;
			q = q->next;
		}//while

		//让长的链表先移动多出的节点
		p = headA;
		q = headB;
		if (lenA > lenB)
		{
			int i = 0;
			while (p && i < lenA - lenB)
			{
				p = p->next;
				++i;
			}//while
		}
		else{
			int j = 0;
			while (q && j < lenB - lenA)
			{
				q = q->next;
				++j;
			}//while
		}

		while (p && q && p->val != q->val)
		{
			p = p->next;
			q = q->next;
		}//while

		return p;
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

	ListNode *head1 = NULL , *head2 = NULL;

	head1 = insert(head1, 1);
	head1 = insert(head1, 2);
	head1 = insert(head1, 1);
	head1 = insert(head1, 2);
	head1 = insert(head1, 3);
	display(head1);
	head2 = insert(head2, 1);
	head2 = insert(head2, 2);
	head2 = insert(head2, 3);
	head2 = insert(head2, 1);
	head2 = insert(head2, 2);
	head2 = insert(head2, 3);
	display(head2);


	ListNode *ret = s.getIntersectionNode(head1, head2);
	
	system("pause");
	return 0;

}