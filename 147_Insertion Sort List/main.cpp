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
	ListNode* insertionSortList(ListNode* head) {
		if (head == NULL || !head->next)
			return head;

		ListNode *p = head->next;
		head->next = NULL;
		//从头结点的下一节点开始，遍历插入排序
		while (p)
		{
			//保存p节点的后续节点
			ListNode *r = p->next;

			//判断是否应插入到头结点
			if (p->val < head->val)
			{
				p->next = head;
				head = p;
			}
			else{
				//寻找p节点应插入位置的前驱
				ListNode *pre = head;
				while (pre->next && pre->next->val <= p->val)
				{
					pre = pre->next;
				}
				p->next = pre->next;
				pre->next = p;
			}
			//循环下一节点的插入
			p = r;
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

	head = insert(head, 3);
	head = insert(head, 5);
	head = insert(head, 2);
	head = insert(head, 1);
	head = insert(head, 6);
	display(head);


	head = s.insertionSortList(head);

	display(head);
	system("pause");
	return 0;

}