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
	
	ListNode *deleteDuplicates(ListNode *head) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if (head == NULL || head->next == NULL)
			return head;

		ListNode * p = head;

		//查找第一个与前驱结点相异结点
		while (p->next != NULL && p->val == p->next->val)
		{
			p = p->next;
		}
		
		//保存相异结点
		ListNode *r = p->next;

		//如果头结点是重复的
		if (p != head){
			while (head != r)
			{
				ListNode * tmp = head;
				head = head->next;
				free(tmp);
			}
			return deleteDuplicates(head);
		}

		//否则递归处理接下来的结点
		head->next = deleteDuplicates(head->next);
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
	head = insert(head, 1);
	head = insert(head, 2);
	head = insert(head, 2);
	head = insert(head, 3);
	head = insert(head, 4);
	display(head);


	head = s.deleteDuplicates(head);

	display(head);
	system("pause");
	return 0;

}
