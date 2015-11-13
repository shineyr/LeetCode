#include <iostream>
#include <cstdlib>

using namespace std;

/**
* Definition for singly-linked list with a random pointer.
* struct RandomListNode {
*     int label;
*     RandomListNode *next, *random;
*     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
* };
*/

struct RandomListNode{
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) :label(x), next(NULL), random(NULL){}
};

class Solution {
public:
	//方法一：直接复制，再修改random指针
	RandomListNode *copyRandomList1(RandomListNode *head) {
		if (!head)
			return NULL;
		
		RandomListNode *ret = new RandomListNode(head->label), *q = ret;
		RandomListNode *p = head->next;
		while (p)
		{
			RandomListNode *tmp = new RandomListNode(p->label);
			q->next = tmp;
			q = q->next;

			p = p->next;
		}//while
		q->next = NULL;

		//处理原始链表的random指针
		p = head, q = ret;
		RandomListNode *idx1 = head, *idx2 = ret;
		while (p)
		{
			if (p->random == NULL)
				q->random = NULL;
			else{
				idx1 = head;
				idx2 = ret;
				while (p->random->label != idx1->label)
				{
					idx1 = idx1->next;
					idx2 = idx2->next;
				}//while
				q->random = idx2;
			}//else
			p = p->next;
			q = q->next;
		}//while
		return ret;
	}

	//方法二：充分利用原始链表信息，在每个节点后复制添加
	RandomListNode *copyRandomList(RandomListNode *head) {
		if (!head)
			return NULL;

		//首先，复制原始的节点，连接自身后面
		RandomListNode *p = head;
		while (p)
		{
			RandomListNode *tmp = new RandomListNode(p->label);
			//保存后续节点
			RandomListNode *r = p->next;

			tmp->next = r;
			p->next = tmp;

			p = r;
		}//while

		//然后，将添加的节点random 链接到原始节点random的下一个位置
		p = head;
		while (p)
		{
			RandomListNode *q = p->next;
			if (p->random == NULL)
				q->random = NULL;
			else{
				q->random = p->random->next;
			}//else
			//处理下一个原始节点
			p = q->next;
		}//while
		
		//最后，恢复原始链表，得到新链表
		RandomListNode *ret = head->next;

		p = head;
		RandomListNode *q = head->next;
		while (q->next)
		{
			p->next = q->next;
			p = q;
			if (q->next)
				q = q->next;
		}
		p->next = NULL;
		q->next = NULL;
		return ret;
	}

};

RandomListNode * insert(RandomListNode *head, int label)
{
	RandomListNode *p = new RandomListNode(label);
	if (head == NULL)
	{
		head = p;
	}
	else{
		RandomListNode *q = head;
		while (q->next != NULL)
		{
			q = q->next;
		}
		q->next = p;
	}
	return head;
}

void display(RandomListNode *head)
{
	if (head == NULL)
		return;
	else if (head->next == NULL)
		cout << head->label << endl;
	else{
		RandomListNode *q = head;
		while (q->next)
		{
			cout << q->label << " -> ";
			q = q->next;
		}
		cout << q->label << endl;
	}
}

int main()
{
	Solution s;

	RandomListNode *head1 = NULL, *head2 = NULL;

	head1 = insert(head1, 1);
	head1 = insert(head1, 2);
	head1 = insert(head1, 1);
	head1 = insert(head1, 2);
	head1 = insert(head1, 3);
	display(head1);
	
	head2 = s.copyRandomList1(head1);

	display(head2);



	system("pause");
	return 0;

}