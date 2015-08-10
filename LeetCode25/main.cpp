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
	ListNode(int x) : val(x), next(NULL){}
};

class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		ListNode *p = head;
		int len = 0;
		while (p)
		{
			len++;
			p = p->next;
		}
		if (len < k || k == 1)
			return head;

		vector<ListNode *> vl;
		ListNode *h = head;

		while (len >= k)
		{
			//找到len/k个子链表，分别翻转
			ListNode *q = h;
			for (int i = 1; i < k; i++)
				q = q->next;

			//保存后续结点
			ListNode *r = q->next;

			q->next = NULL;

			vl.push_back(reverse(h));

			h = r;
			len -= k;
		}//while

		//将翻转的链表链接起来,保存剩余的小于k个的结点
		ListNode *re = h;
		if (vl.size() != 1)
		{
			
			for (int i = 0; i < vl.size() - 1; i++)
			{
				p = LastNode(vl[i]);
				p->next = vl[i + 1];
			}//for
			p->next = vl[vl.size() - 1];
		}
		
		if (re)
			LastNode(vl[vl.size() - 1])->next = re;

		head = vl[0];
		return head;

	}

	ListNode *LastNode(ListNode *head)
	{
		while (head && head->next)
			head = head->next;
		return head;
	}

	ListNode* reverse(ListNode* head)
	{
		if (head == NULL || head->next == NULL)
			return head;

		ListNode *ret = head , *p = head->next;
		ret->next = NULL;

		while (p)
		{
			//保存下一个结点
			ListNode *q = p->next;

			p->next = ret;
			ret = p;
			p = q;
		}
		return ret;
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
	for (int i = 1; i < 4; i += 1)
	{
		l1 = insert(l1, i);
	}
	display(l1);

	Solution *s = new Solution();

	rl = s->reverseKGroup(l1, 2);
	display(rl);


	system("pause");
	return 0;

}