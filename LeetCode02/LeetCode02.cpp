#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL){}
};

class Solution
{
public:
	ListNode *addTwoNumbers(ListNode* l1, ListNode *l2)
	{
		if (l1 == NULL)
			return l2;
		if (l2 == NULL)
			return l1;

		vector<int> v1;
		vector<int> v2;
		ListNode *head = NULL, *rear = NULL;
		while (l1 != NULL)
		{
			v1.push_back(l1->val);
			l1 = l1->next;
		}
		while (l2 != NULL)
		{
			v2.push_back(l2->val);
			l2 = l2->next;
		}

		if (v1.size() < v2.size())
		{
			for (int k = v1.size(); k < v2.size(); k++)
				v1.push_back(0);
		}
		else
		{
			for (int k = v2.size(); k < v1.size(); k++)
				v2.push_back(0);
		}
		int temp = 0;
		int value = 0;
		for (int j = 0; j < v1.size(); j++)
		{
			int sum = v1[j] + v2[j] + temp;
			temp = sum / 10;
			value = sum % 10;
			ListNode *node = new ListNode(value);
			if (head == NULL)
				head = node;
			if (rear == NULL)
				rear = node;
			else
			{
				rear->next = node;
				rear = rear->next;
			}
		}
		if (temp != 0 && rear != NULL)
		{
			ListNode *node = new ListNode(temp);
			rear->next = node;
		}
		return head;
	}
};

int main()
{
	ListNode *l1 = NULL, *r1 = NULL, *l2 = NULL, *r2 = NULL, *result = NULL;
	int arr1[3] = { 2, 4, 3 };
	int arr2[3] = { 5, 6, 4 };
	for (int i = 0; i < 3; i++)
	{
		ListNode *node1 = new ListNode(arr1[i]);
		ListNode *node2 = new ListNode(arr2[i]);
		if (l1 == NULL)
			l1 = node1;
		if (r1 == NULL)
			r1 = node1;
		else{
			r1->next = node1;
			r1 = r1->next;
		}
		if (l2 == NULL)
			l2 = node2;
		if (r2 == NULL)
			r2 = node2;
		else{
			r2->next = node2;
			r2 = r2->next;
		}
	}
	Solution s;
	result = s.addTwoNumbers(l1, l2);
	for (; result != NULL; result = result->next)
		cout << result->val << "->";
	cout << endl;
	system("pause");
	return 0;
}
