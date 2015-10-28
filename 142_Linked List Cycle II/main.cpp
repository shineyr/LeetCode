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
	ListNode *detectCycle(ListNode *head) {
		if (!head)
			return NULL;

		ListNode *slow = head, *fast = head;

		do{
			if (!slow || !fast)
				return NULL;

			slow = slow->next;
			fast = fast->next;

			if (fast == NULL)
				return NULL;
			else
				fast = fast->next;
		} while (slow != fast);

		slow = head;
		while (slow != fast)
		{
			slow = slow->next;
			fast = fast->next;
		}
		return slow;
	}	
};

int main()
{

}