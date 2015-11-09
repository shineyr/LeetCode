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

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(NULL){}
};

class Solution {
public:
	//方法一，逐个交换
	void reorderList1(ListNode* head) {
		if (!head || !head->next)
			return ;

		//逐个节点元素值交换
		ListNode *p = head, *pre = head , *q = head;
		while (p)
		{
			//只剩下一个尾节点
			if (q->next == NULL)
				return;

			//寻找当前末尾节点
			while (q->next->next)
			{
				q = q->next;
			}
			//保存末尾节点的前一个节点
			pre = q;
			//得到末尾节点
			q = q->next;

			//处理完毕
			if (p == pre)
				return;

			//改变链接
			q->next = p->next;
			p->next = q;
			//新末尾节点后继置空
			pre->next = NULL;


			p = q->next;
			q = p;
		}
	
		return;
	}

	void reorderList(ListNode* head) {
		//空链表或单节点或双节点链表直接返回
		if (!head || !head->next || !head->next->next)
			return;
		/* 先用快慢指针找到链表的中点，然后翻转链表后半部分，再和前半部分组合。
		 * 需要注意的是把链表分成两半时，前半段的尾节点要置为NULL，翻转链表时也要把尾节点置为NULL。
		 */
		ListNode *slow = head, *fast = head;
		//把整个链表划分成2个等长的子链表，如果原链表长度为奇数，那么第一个子链表的长度多1  
		while (fast->next != NULL) {
			fast = fast->next;
			if (fast->next != NULL)
				fast = fast->next;
			else 
				break;
			slow = slow->next;
		}
		ListNode *f_head = head, *s_head = slow->next;
		//将前半部分链表尾节点链接到空
		slow->next = NULL;

		//翻转第二个链表
		ListNode *p = s_head, *q = s_head->next;
		p->next = NULL;
		while (q)
		{
			ListNode *r = q->next;
			q->next = p;
			p = q;
			q = r;
		}
		s_head = p;

		//合并两个链表
		p = f_head, q = s_head;
		while (q)
		{
			//保存两个子链表下一节点
			ListNode *f_r = p->next , *s_r = q->next;
			p->next = q;
			q->next = f_r;

			p = f_r;
			q = s_r;
		}//while
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
	head = insert(head, 3);
	head = insert(head, 4);
	head = insert(head, 5);
	head = insert(head, 6);
	head = insert(head, 7);
	display(head);


	s.reorderList1(head);

	display(head);
	system("pause");
	return 0;

}