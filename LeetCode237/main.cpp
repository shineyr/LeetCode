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
	void deleteNode(ListNode* node) {
		if (node == NULL)
			return;
		else if(node->next != NULL){ 
			//只给出一个要删除的结点，转移思维，改成拷贝目标结点后结点的值，然后删除目标结点的后一结点
			node->val = node->next->val;
			node->next = node->next->next;
		}
		else{
			return;
		}
	}
};

ListNode * insert(ListNode *head, ListNode *p)
{
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
	ListNode *head = NULL;
	for (int i = 1; i <= 10; i++)
	{
		ListNode *p = new ListNode(i);
		head = insert(head, p);
	}
	display(head);

	Solution s;

	s.deleteNode(head->next);

	display(head);

	system("pause");
	return 0;

}