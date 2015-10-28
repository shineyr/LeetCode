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
	bool hasCycle(ListNode *head) {
		if (head == NULL)
			return false;

		ListNode *slow = head, *fast = head;

		do{
			if (!slow || !fast)
				return false;

			slow = slow->next;
			fast = fast->next;

			if (fast == NULL)
				return false;
			else
				fast = fast->next;
		} while (slow != fast);

		return true;
	}
};

int main()
{

}