#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* removeElements(ListNode* head, int val) {
		if (head == NULL)
			return head;

		ListNode *pre = head, *p = head;
		while (p)
		{
			//找到要删除的节点元素
			if (p->val == val)
			{
				//判断当前节点为头结点
				if (p == head)
				{
					head = p->next;
					ListNode *q = p;
					//更新头
					p = head;
					pre = head;
					delete q;
					q = NULL;
				}
				//删除尾节点
				else if (p->next == NULL)
				{
					pre->next = NULL;				
					delete p;
					p = NULL;
				}
				//删除链表中间节点
				else{
					pre->next = p->next;

					ListNode *q = p;
					p = p->next;
					delete q;
					q = NULL;
				}//else
			}//if
			else{
				pre = p;
				p = p->next;
			}
				
		}//while
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


	head = s.removeElements(head , 1);

	display(head);
	system("pause");
	return 0;

}