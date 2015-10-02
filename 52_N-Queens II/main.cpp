#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
	int ret = 0;
public:
	int totalNQueens(int n) {
		if (n <= 0)
			return 0;
		
		//存储安置皇后的当前解(存储N皇后所在的列数，初始化为-1)
		vector<int> state(n, -1);
		set_queens(state, 0);
		return ret;
	}

	void set_queens(vector<int> &state, int row)
	{
		int n = state.size();
		if (row == n)
		{
			ret++;
			return;
		}
		else{
			for (int col = 0; col < n; col++)
			{
				if (isValid(state, row, col))
				{
					state[row] = col;
					set_queens(state, row + 1);
					state[row] = -1;
				}//if
			}//for
		}
	}

	//判断在row行col列位置放一个皇后，是否是合法的状态
	//已经保证了每行一个皇后，只需要判断列是否合法以及对角线是否合法。
	bool isValid(vector<int> &state, int row, int col)
	{
		for (int i = 0; i < row; i++)
		{
			if (state[i] == col || abs(row - i) == abs(col - state[i]))
				return false;
		}//for
		return true;
	}
};

int main()
{
	Solution s;
	int ret = s.totalNQueens(4);
	cout << ret << endl;

	system("pause");
	return 0;
}
