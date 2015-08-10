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
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == NULL)
			return l2;
		if (l2 == NULL)
			return l1;

		//合并后链表初始化为空
		ListNode *rl = NULL;
	
		ListNode *p = l1, *q = l2;
		if (l1->val <= l2->val)
		{
			rl = l1;			
			p = l1->next;
		}
		else{
			rl = l2;
			q = l2->next;
		}
		rl->next = NULL;
		ListNode *head = rl;


		while (p && q)
		{
			if (p->val <= q->val)
			{
				rl->next = p;
				p = p->next;				
			}
			else{
				rl->next = q;
				q = q->next;
			}//else
			rl = rl ->next;
		}//while

		while (p)
		{
			rl->next = p;
			p = p->next;
			rl = rl->next;
		}
			
		while (q)
		{
			rl->next = q;
			q = q->next;
			rl = rl->next;
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
	ListNode *l1 = NULL, *l2 = NULL, *rl = NULL;
	for (int i = 1; i <= 20; i+=2)
	{
		l1 = insert(l1, i);
		l2 = insert(l2, i + 1);
	}
	display(l1);
	display(l2);

	Solution *s = new Solution();

	rl = s->mergeTwoLists(l2, l1);
	display(rl);


	system("pause");
	return 0;

}