#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		if (board.empty())
			return false;

		//数独游戏符合9宫格，也就是为一个9*9的矩阵
		int size = board.size();

		//根据数独游戏的规则，需要进行三次检验（按行、按列、按照3*3块）
		//利用哈希的思想，记录每个关键字的出现次数，若是次数>1，则返回false
		vector<int> count;
		for (int i = 0; i < size; ++i)
		{
			//每行开始前，将记录次数的vector清零,元素1~9分别对应下标0~8,对应vector中值为该元素的出现次数
			count.assign(9, 0);
			for (int j = 0; j < size; j++)
			{
				if (board[i][j] != '.')
				{
					int pos = board[i][j] - '1';					
					if (count[pos] > 0)
						return false;
					else
						++count[pos];
				}
				else
					continue;
					
			}//for
		}//for

		//同理，按列检验
		for (int j = 0; j < size; j++)
		{
			count.assign(9, 0);
			for (int i = 0; i < size; i++)
			{
				if (board[i][j] != '.')
				{
					int pos = board[i][j] - '1';
					
					if (count[pos] > 0)
						return false;
					else
						++count[pos];;
				}
				else
					continue;
			}//for
		}//for

		//按3*3小块检验
		for (int i = 0; i < size; i += 3)
		{			
			for (int j = 0; j < size; j += 3)
			{
				count.assign(9, 0);
				//每个块又是一个3*3的矩阵
				for (int row = i; row < i + 3;row++)
				for (int col = j; col < j + 3; col++)
				{
					if (board[row][col] != '.')
					{
						int pos = board[row][col] - '1';
						if (count[pos] > 0)
							return false;
						else
							++count[pos];;
					}
					else
						continue;
				}
			}//for
		}//for

		return true;
	} 
};

int main()
{
	Solution s;
	vector<vector<char>> v = { { '5', '3', '.', '.', '7', '.', '.', '.', '.' },
	{ '6', '.', '.', '1', '9', '5', '.', '.', '.' },
	{ '.', '9', '8', '.', '.', '.', '.', '6', '.' },
	{ '8', '.', '.', '.', '6', '.', '.' ,'.','3'},
	{ '4', '.', '.', '8', '.', '3', '.', '.' ,'1'},
	{ '7', '.', '.', '.', '2',  '.', '.' ,'.','6'},
	{ '.', '6',  '.', '.', '.', '.' ,'2','8','.'},
	{ '.', '.', '.', '4', '1', '9', '.', '.' ,'5'},
	{ '.', '.', '.', '.', '8', '.', '.', '7','9'}
	};

	cout << s.isValidSudoku(v) << endl;
	system("pause");
	return 0;

}