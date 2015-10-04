#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
private:
	const int N = 9;
public:
	void solveSudoku(vector<vector<char>>& board) {
		if (board.empty())
			return;
		isValidSudoku(board);
	}

	bool isValidSudoku(vector<vector<char> > &board)
	{
		//所给非空九宫格
		for (int r = 0; r < N; r++)
		{
			for (int c = 0; c < N; c++)
			{
				//如果当前为待填充数字
				if ('.' == board[r][c])
				{
					for (int i = 1; i <= 9; i++)
					{
						board[r][c] = i + '0';
							//判断当前填充数字是否合理
						if (judge(board, r, c))
						{
							if (isValidSudoku(board))
								return true;
						}//if
						board[r][c] = '.';
					}//for
					return false;
				}//if			
			}//for
		}//for
	}//isValid

	//判断当前row，col中所填数字是否合理，只需要判断当前行，当前列，以及当前所在的3*3块
	bool judge(vector<vector<char> > &board, int row, int col)
	{
		//(1)判断当前行
		for (int j = 0; j < N; j++)
		{
			if (col != j && board[row][j] == board[row][col])
				return false;
		}

		//(2)判断当前列
		for (int i = 0; i < N; i++)
		{
			if (row != i && board[i][col] == board[row][col])
				return false;
		}//for

		//(3)判断当前3*3块
		for (int i = row / 3 * 3; i < (row / 3 + 1) * 3; ++i)
		{
			for (int j = col / 3 * 3; j < (col / 3 + 1) * 3; ++j)
			{
				if (row != i && j != col && board[row][col] == board[i][j])
					return false;
			}//for
		}//for
		return true;
	}
};

int main()
{
	Solution s;
	vector<vector<char> > v = 
	{ { '5', '3', '.', '.', '7', '.', '.', '.', '.' },
	{ '6', '.', '.', '1', '9', '5', '.', '.', '.' },
	{ '.', '9', '8', '.', '.', '.', '.', '6', '.' },
	{ '8', '.', '.', '.', '6', '.', '.', '.', '3' },
	{ '4', '.', '.', '8', '.', '3', '.', '.', '1' },
	{ '7', '.', '.', '.', '2', '.', '.', '.', '6' },
	{ '.', '6', '.', '.', '.', '.', '2', '8', '.' },
	{ '.', '.', '.', '4', '1', '9', '.', '.', '5' },
	{ '.', '.', '.', '.', '8', '.', '.', '7', '9' }
	};

	s.solveSudoku(v);

	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
			cout << v[i][j] << '\t';
		cout << endl;
		cout << endl;
	}
	cout << endl;

	system("pause");
	return 0;
}