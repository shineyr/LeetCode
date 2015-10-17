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

	template <typename Iter>
	TreeNode* make(Iter in_begin, Iter in_end , Iter post_begin, Iter post_end ) {
	
		if (post_begin == post_end || in_begin == in_end)
			return NULL;
	
		int size = post_end - post_begin;
		//后序遍历最后一个节点为树的根节点
		TreeNode *root = new TreeNode(*(post_begin + size-1));
	
		//在中序遍历结果中查找根节点
		Iter iter = find(in_begin, in_end, *(post_begin + size - 1));
	    
		//计算左子树个数
		int count = iter - in_begin;
		
		if (iter != in_end)
		{
			//则在inOrder中（0 ， count-1）为左子树中序遍历结果（count+1，size-1）为右子树的中序遍历序列
			//在preOrder中（0，count-1）为左子树前序遍历结果（count,size-2）为右子树前序遍历结果
	
			root->left = make(in_begin, iter , post_begin, post_begin + count);
	
			//构造右子树
			root->right = make(iter + 1, in_end ,post_begin + count, post_begin + size - 1);
		}
		return root;
	
	}
	
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		if (inorder.empty() || postorder.empty())
			return NULL;

		return make(inorder.begin(), inorder.end() ,postorder.begin(), postorder.end());
	}
	
};

int main()
{
	Solution s;
	vector<int> postOrder = { 2, 1 };
	vector<int> inOrder = {1,2 };

	TreeNode * root = s.buildTree(inOrder, postOrder);

	system("pause");

	return 0;
}