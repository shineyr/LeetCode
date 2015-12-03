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
	bool isPalindrome(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return true;

		ListNode *fast = head, *slow = head;
		while (fast && fast->next)
		{
			fast = fast->next->next;
			slow = slow->next;
		}
		//若奇数个节点，跳过中间节点
		if (fast != NULL)
			fast = slow->next;
		else
			fast = slow;
		slow = head;
		
		//头插法反转后半部分节点
		ListNode *secHead = NULL;
		while (fast)
		{
			ListNode *r = fast->next;
			fast->next = secHead;
			secHead = fast;
			fast = r;
		}

		//比较两部分
		fast = secHead;
		while (fast)
		{
			if (fast->val != slow->val)
			{
				return false;
			}//if
			fast = fast->next;
			slow = slow->next;
		}//while
		return true;
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
	//head = insert(head, 2);
	head = insert(head, 5);
	head = insert(head, 3);
	display(head);


	cout << s.isPalindrome(head) << endl;

	system("pause");
	return 0;

}