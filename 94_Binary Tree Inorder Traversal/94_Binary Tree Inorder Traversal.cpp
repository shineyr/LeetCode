#include <iostream>
#include <cstdlib>
#include <vector>
#include <stack>

using namespace std;

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		//Ê÷¿Õ£¬·µ»Ø¿Õvector
		if (!root)
			return vector<int>();
		
		vector<int> ret;
		stack<TreeNode *> s;
		
		//±éÀú
		TreeNode *p = root;
		do
		{
			while (p != NULL)
			{
				s.push(p);
				p = p->left;
			}

			if (!s.empty())
			{
				p = s.top();
				s.pop();

				ret.push_back(p->val);

				p = p->right;
			}
		} while (!s.empty() || p != NULL);

		return ret;
	}
};

int main()
{

}
