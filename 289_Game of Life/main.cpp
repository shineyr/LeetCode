#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:
	//方法一：复制原来棋盘，空间复杂度为O(n)
	void gameOfLife1(vector<vector<int>>& board) {
		if (board.empty())
			return;

		//求出所给定棋盘的行列
		int m = board.size(), n = board[0].size();

		vector<vector<int>> tmp(board.begin(), board.end());
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				int count = getLiveNum(tmp, i, j);
				if (board[i][j] == 0)
				{
					//dead状态
					if (count == 3)
						board[i][j] = 1; //dead —> live
				}//if
				else{
					//live状态
					if (count > 3)
					{
						board[i][j] = 0; //live—>dead
					}//if
					//若是count == 2 || count == 3 则live—>dead,board[i][j]值不变
				}//else
			}//for
		}//for
		return;
	}

	//方法二：inplace 使用不同数值（十进制）代表状态 0 ：dead；  10 ：dead—>live； 11：live—>live；  1：live；
	void gameOfLife(vector<vector<int>>& board) {
		if (board.empty())
			return;

		//求出所给定棋盘的行列
		int m = board.size(), n = board[0].size();
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				int count = getLiveNum(board, i, j);
				if (board[i][j] == 0)
				{
					//dead状态
					if (count == 3)
						board[i][j] += 10; //dead —> live
				}
				else{
					//live状态
					if (count == 2 || count == 3)
					{
						board[i][j] += 10; //live—>live
					}//if
					//若是count>=4 则live—>dead,board[i][j]值不变
				}//else
			}//for
		}//for
		//更新状态
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				board[i][j] /= 10;
			}//for
		}//for
		return;
	}

	//计算位于(r,c)邻居，live状态的数量
	int getLiveNum(vector<vector<int>> &board, int x, int y)
	{
		int count = 0;
		for (int i = x - 1; i <= x + 1; ++i)
		{
			for (int j = y - 1; j <= y + 1; ++j)
			{
				if (i < 0 || j < 0 || i >= board.size() || j >= board[x].size() || (x == i && j == y))	
				{
					continue;
				}
				else{
					if (board[i][j] % 10 == 1)
						++count;
				}//else
			}//for
		}//for
		return count;
	}
	
};

int main()
{
	vector<vector<int>> v = { { 1, 1 }, { 1, 0 } };
	Solution s;
	s.gameOfLife1(v);

	for (unsigned i = 0; i < v.size(); ++i)
	{
		for (unsigned j = 0; j < v[0].size(); ++j)
		{
			cout << v[i][j] << "\t";
		}//for
		cout << endl;
	}//for
	system("pause");
	return 0;
}