#include <iostream>
#include <cstdlib>
#include <vector>
#include <iterator>
#include <algorithm>
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

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

class Solution {
public:
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		if (nums.empty())
			return NULL;

		else
			return make(nums.begin(), nums.end());
		
	}

	template <typename Iter>
	TreeNode *make(Iter beg, Iter end)
	{
		if (beg == end)
			return NULL;

		//求元素节点个数
		int size = end - beg;

		TreeNode *root = new TreeNode(*(beg + size / 2));

		root->left = make(beg, beg + size / 2);
		root->right = make(beg + size / 2 + 1, end);
		return root;
	}
};

int main()
{
	vector <int> v = { 1, 2, 3, 4 };

	Solution s;
	TreeNode *root = s.sortedArrayToBST(v);

	system("pause");
	return 0;
}