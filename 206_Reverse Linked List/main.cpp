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


	head = s.reverseList(head);

	display(head);
	system("pause");
	return 0;

}