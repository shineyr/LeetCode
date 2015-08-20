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
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return head;

		ListNode *p = head, *q = p->next;
		while (p && q)
		{
			if (p->val == q->val)
			{
				ListNode *t = q;
				p->next = q->next;
				q = q->next;
				//释放要删除的结点空间
				delete t;
			}
			else{
				p = p->next;
				q = q->next;
			}//elif
		}//while
		return head;
	}
};

ListNode* insert(ListNode *head, int val)
{
	ListNode *p = new ListNode(val);
	if (head == NULL)
		head = p;
	else
	{
		ListNode *q = head;
		while (q->next)
			q = q->next;
		q->next = p;
	}
	return head;
}

void display(ListNode *head)
{
	ListNode *p = head;
	while (p)
	{
		cout << p->val << "\t";
		p = p->next;
	}
	cout << endl;
	delete p;
}

int main()
{
	ListNode *head = NULL;

	for (int i = 0; i < 5; i++)
	{
		head = insert(head, i);
		head = insert(head, i);
		head = insert(head, i + 1);
	}

	display(head);

	Solution s;
	s.deleteDuplicates(head);
	display(head);

	system("pause");
	return 0;

}