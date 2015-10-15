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

//class Solution {
//public:
//	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//		if (preorder.empty() && inorder.empty())
//			return NULL;
//
//		//求树中节点个数
//		int size = preorder.size();
//
//		//先序遍历第一个节点为树的根节点
//		TreeNode *root = new TreeNode(preorder[0]);
//
//		int pos = 0;
//		//在中序遍历结果中查找根节点
//		for (int i=0; i<size; ++i)
//		{
//			if (inorder[i] == preorder[0])
//			{
//				pos = i;
//				break;
//			}//if
//		}//for
//
//		if (pos >= 0 && pos < size)
//		{
//			//则在inOrder中（0 ， pos-1）为左子树中序遍历结果（pos+1，size-1）为右子树的中序遍历序列
//			//在preOrder中（1，pos）为左子树前序遍历结果（pos+1,size-1）为右子树前序遍历结果
//			vector<int> left_pre;
//			for (int j = 1; j <= pos; j++)
//				left_pre.push_back(preorder[j]);
//				
//			vector<int> left_in;
//			for (int j = 0; j < pos; ++j)
//				left_in.push_back(inorder[j]);
//
//			root->left = buildTree(left_pre, left_in);
//
//			//构造右子树
//			vector<int> right_pre , right_in;
//			for (int j = pos + 1; j < size; j++)
//			{
//				right_pre.push_back(preorder[j]);
//				right_in.push_back(inorder[j]);
//			}
//			
//			root->right = buildTree(right_pre, right_in);
//		}
//		return root;	
//
//	}
//};

class Solution {
public:

	template <typename Iter>
	TreeNode* make(Iter pre_begin, Iter pre_end, Iter in_begin, Iter in_end) {

		if (pre_begin == pre_end || in_begin == in_end)
			return NULL;

		//先序遍历第一个节点为树的根节点
		TreeNode *root = new TreeNode(*pre_begin);

		//在中序遍历结果中查找根节点
		Iter iter = find(in_begin, in_end, *pre_begin);

		int count = iter - in_begin;

		if (iter != in_end)
		{
			//则在inOrder中（0 ， pos-1）为左子树中序遍历结果（pos+1，size-1）为右子树的中序遍历序列
			//在preOrder中（1，pos）为左子树前序遍历结果（pos+1,size-1）为右子树前序遍历结果

			root->left = make(pre_begin + 1, pre_begin + count + 1, in_begin, iter);

			//构造右子树
			root->right = make(pre_begin + count + 1, pre_end, iter + 1, in_end);
		}
		return root;

	}

	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		if (preorder.empty() || inorder.empty())
			return NULL;
		
		return make(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
	}
};


int main()
{
	Solution s;
	vector<int> preOrder = { 1, 2, 4, 5, 3 };
	vector<int> inOrder = { 4, 2, 5, 1, 3 };

	TreeNode * root = s.buildTree(preOrder, inOrder);

	system("pause");

	return 0;
}