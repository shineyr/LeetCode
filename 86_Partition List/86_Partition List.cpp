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
	ListNode* partition(ListNode* head, int x) {
		
		if (!head || !head->next)
			return head;

		ListNode *p = head;
		head = NULL;
		ListNode *r = head;
		
		//(1)寻找第一个不小于目标值的节点p，前n个小于x的节点逐个连接到head，保存尾结点r
		while (p && p->val < x)
		{
			if (!head)
			{
				head = p;
				r = head;
			}
			else{
				r->next = p;
				//保存新链表尾结点
				r = r->next;
			}			
			p = p->next;
			r->next = NULL;
			
		}//while

		//如果此时p为空，已经没有其余节点，返回新链表head
		if (!p)
			return head;

		//（2）p节点大于x，从下一个结点开始遍历，将小于x的结点连接到head中，原链表删除该结点
		ListNode *pre = p , *q = p->next;
		while (q)
		{
			if (q->val < x)
			{

				if (!head)
				{
					head = q;
					r = head;
				}
				else{
					r->next = q;
					//保存新链表尾结点
					r = r->next;
				}
				
				pre->next = q->next;
				q = q->next;

				r->next = NULL;
			}//if
			else{
				pre = q;
				q = q->next;
			}//else
		}//while

		//如果此时，原链表还剩余结点，直接连接到r后面即可
		if (p)
		{
			if (!head)
				return p;
			else
			r->next = p;
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
	head = insert(head, 4);
	head = insert(head, 3);
	head = insert(head, 2);
	head = insert(head, 5);
	head = insert(head, 2);

	display(head);

	head = s.partition(head, 0);

	display(head);

	system("pause");
	return 0;

}