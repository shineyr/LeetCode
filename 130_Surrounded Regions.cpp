/*
LeetCode 130. Surrounded Regions
*/

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:
	void solve(vector<vector<char>>& board) {
		if (board.empty())
		{
			return;
		}

		int m = board.size(), n = board[0].size();
		/*核心思想，只有当边界节点为O*/
		for (int i = 0; i < m; ++i)
		{
			//检查每行第一个元素
			check(board, i, 0, m, n);
			//若矩阵多列，则继续检查每行最后一个元素
			if (n > 1)
				check(board, i, n - 1, m, n);
		}

		for (int j = 1; j < n-1; ++j)
		{
			//检查每列第一个元素
			check(board, 0, j, m, n);

			//若矩阵多行，继续检查每列最底元素
			if (m > 1)
				check(board, m - 1, j, m, n);
		}

		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (board[i][j] == 'O')
					board[i][j] = 'X';
			}//for
		}//for

		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (board[i][j] == '1')
					board[i][j] = 'O';
			}//for
		}//for
		
	}

	/*检查（i,j）位置是否为'o',若为'o'，标记为'1' */
	void check(vector<vector<char>>& board,int i, int j, int row, int col)
	{
		if (i < 0 || i >= row || j < 0 || j >= col)
			return;

		if (board[i][j] == 'O')
		{
			board[i][j] = '1';
			if (i > 1)
				check(board, i - 1, j, row, col);
			
			if (i < row - 1)
				check(board, i + 1, j, row, col);

			if (j > 1)
				check(board, i, j - 1, row, col);

			if (j < col - 1)
				check(board, i, j + 1, row, col);
		}
	}
};

int main()
{
	vector<vector<char>> v = { {'X','X','X'},
	{ 'X','O','X' } ,
	{'X','X','X'} };

	Solution().solve(v);

	system("pause");
	return 0;
}