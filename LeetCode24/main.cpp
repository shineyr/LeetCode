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
	ListNode* swapPairs(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return head;

		ListNode   *p = head , *q = p->next;
		//首先交换头两个结点,同时保存q后结点
		ListNode *r = q->next;

		head = q;
		p->next = r;
		q->next = p;
		if (r && r->next)
		{
			ListNode *pre = p;
			p = p->next;
			q = p->next;
				
			while (q)
			{
				//保存q结点后结点
				ListNode *r = q->next;

				pre->next = q;
				p->next = r;
				q->next = p;
				if (r && r->next)
				{
					pre = p;
					p = r;
					q = p->next;
				}
				else{
					break;
				}
			}
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
	for (int i = 1; i <= 11; i += 1)
	{
		l1 = insert(l1, i);
	}
	display(l1);

	Solution *s = new Solution();

	rl = s->swapPairs(l1);
	display(rl);


	system("pause");
	return 0;

}