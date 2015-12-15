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

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(NULL){}
};

class Solution {
public:
	/*方法一：采用合并排序的思路 复杂度为O(nlogk)*/
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		int len = lists.size();
		ListNode *head = NULL;
		if (len == 0)
			return head;
		else if (len == 1)
		{
			head = lists[0];
			return head;
		}
		else{
			int mid = (len - 1) / 2;
			vector<ListNode *> l1(lists.begin(), lists.begin() + mid + 1);
			vector<ListNode *> l2(lists.begin() + mid + 1, lists.end());
			ListNode *head1 = mergeKLists(l1);
			ListNode *head2 = mergeKLists(l2);

			return mergeTwoLists(head1, head2);
		}//else
	}

	/*方法二：暴力法 复杂度为O(nK) 出现超时*/
	ListNode* mergeKLists2(vector<ListNode*>& lists) {
		int len = lists.size();
		ListNode *head = NULL;
		if (len == 0)
			return head;
		else if (len == 1)
		{
			head = lists[0];
			return head;
		}
		else{
			head = mergeTwoLists(lists[0], lists[1]);
			for (int i = 2; i < len; i++)
				head = mergeTwoLists(head, lists[i]);
		}
		return head;
	}

	/*合并两个链表函数*/
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
			rl = rl->next;
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
	Solution s;
	vector<ListNode *> v;

	ListNode *head1 = NULL;
	for (int i = 1; i < 5; i += 2)
		head1 = insert(head1, i);
	v.push_back(head1);

	display(head1);

	ListNode *head2 = NULL;
	for (int i = 2; i < 6; i += 2)
		head2 = insert(head2, i);
	v.push_back(head2);
	
	display(head2);

	ListNode *head3 = NULL;
	for (int i = 3; i < 7; i += 2)
		head3 = insert(head3, i);
	v.push_back(head3);

	display(head3);

	ListNode *head = s.mergeKLists(v);

	display(head);

	system("pause");
	return 0;
}