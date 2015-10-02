#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>

using namespace std;

//class Solution {
//private:
//	vector<vector<string> > ret;
//public:
//	vector<vector<string>> solveNQueens(int n) {
//		if (n <= 0)
//			return vector<vector<string>>();
//
//		//二维字符矩阵，存储当前满足N皇后的解
//		vector<string> cur(n, string(n, '.'));
//
//		//调用主函数
//		set_queens(cur, 0);
//		return ret;	
//	}
//
//	void set_queens(vector<string> &cur, int row)
//	{
//		int size = cur.size();
//		if (row == size)
//		{
//			ret.push_back(cur);
//			return;
//		}
//		else{
//			for (int col = 0; col < size; col++)
//			{
//				if (isValid(cur, row, col))
//				{
//					cur[row][col] = 'Q';
//					//安置下一个皇后
//					set_queens(cur, row + 1);
//					cur[row][col] = '.';
//				}//for
//			}//for
//		}
//	}
//
//	//判断在cur[row][col]位置放一个皇后，是否是合法的状态
//	//已经保证了每行一个皇后，只需要判断列是否合法以及对角线是否合法。
//	bool isValid(vector<string> &cur, int row, int col)
//	{
//		//判断是否同列
//		for (int i = 0; i < row; i++)
//		{
//			if (cur[i][col] == 'Q')
//				return false;
//		}//for
//
//		//判断是否同一左对角线
//		for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j)
//		{
//			if (cur[i][j] == 'Q')
//				return false;
//		}
//
//		//判断是否同一右对角线
//		for (int i = row - 1, j = col + 1; i >= 0 && j <= cur.size(); --i, ++j)
//		{
//			if (cur[i][j] == 'Q')
//				return false;
//		}
//
//		return true;
//	}
//};


class Solution {
private:
	vector<vector<string> > res;
public:
	vector<vector<string> > solveNQueens(int n) {
		vector<int> state(n, -1);
		helper(state, 0);
		return res;
	}
	void helper(vector<int> &state, int row)
	{
		//放置第row行的皇后
		int n = state.size();
		if (row == n)
		{
			vector<string>tmpres(n, string(n, '.'));
			for (int i = 0; i < n; i++)
				tmpres[i][state[i]] = 'Q';
			res.push_back(tmpres);
			return;
		}
		for (int col = 0; col < n; col++)
		if (isValid(state, row, col))
		{
			state[row] = col;
			helper(state, row + 1);
			state[row] = -1;;
		}
	}

	//判断在row行col列位置放一个皇后，是否是合法的状态
	//已经保证了每行一个皇后，只需要判断列是否合法以及对角线是否合法。
	bool isValid(vector<int> &state, int row, int col)
	{
		for (int i = 0; i < row; i++)//只需要判断row前面的行，因为后面的行还没有放置
		if (state[i] == col || abs(row - i) == abs(col - state[i]))
			return false;
		return true;
	}
};



int main()
{
	Solution s;

	vector<vector<string> > ret = s.solveNQueens(4);

	int m = ret.size(), n = ret[0].size();
	//一共m个解，每个解放置一行
	for (size_t i = 0; i < m; i++)
	{
		for (size_t j = 0; j < n; j++)
			cout << ret[i][j] << "\t";
		cout << endl;
	}

	system("pause");
	return 0;
}