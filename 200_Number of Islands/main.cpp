#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:
	//等价于计算连通子图的个数
	int numIslands(vector<vector<char>>& grid) {
		if (grid.empty())
			return 0;

		//计算该二维数组的行列
		int rows = grid.size();
		int cols = grid[0].size();

		int count = 0;
		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < cols; ++j)
			{
				if (grid[i][j] == '1')
				{
					++count;
					dfs(grid, i, j);
				}
				continue;
			}//for
		}//for
		return count;
	}

	void dfs(vector<vector<char>> &grid, int r, int c)
	{
		if (grid.empty())
			return;

		//计算该二维数组的行列
		int rows = grid.size();
		int cols = grid[0].size();

		if (r < 0 || r >= rows || c < 0 || c >= cols)
			return;

		if (grid[r][c] == '1')
		{
			//改变当前元素值为非'1'
			grid[r][c] = '2';
			dfs(grid, r, c + 1);
			dfs(grid, r + 1, c);
			dfs(grid, r, c - 1);
			dfs(grid, r - 1, c);
		}//if
		return;
	}
};

int main()
{
	vector<vector<char>> v = { { '1', '1', '0', '0', '0' }, { '1', '1', '0', '0', '0' },
	{ '0', '0', '1', '0', '0' }, {'0','0','0','1','1'} };

	Solution s;
	int ret = s.numIslands(v);
	cout << ret << endl;
	system("pause");
	return 0;
}