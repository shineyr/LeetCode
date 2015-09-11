#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		if (grid.empty())
			return 0;

		//求当前矩阵的行数、列数
		int m = grid.size();
		int n = grid[0].size();

		vector<vector<int> > sum(m, vector<int>(n, 0));

		//记录首元素和
		sum[0][0] = grid[0][0];
		int minSum = sum[0][0];

		for (int i = 1; i < m; i++)
		{
			sum[i][0] = sum[i - 1][0] + grid[i][0];
			//此时路径和唯一，也是最小路径和
		}//for

		for (int j = 1; j < n; j++)
		{
			sum[0][j] = sum[0][j - 1] + grid[0][j];
			//此时路径和唯一，也是最小路径和
		}//for

		for (int i = 1; i < m; i++)
		{
			for (int j = 1; j < n; j++)
			{
				sum[i][j] = min(sum[i - 1][j], sum[i][j - 1]) + grid[i][j];
			}//for
		}//for

		return sum[m - 1][n - 1];
	}
};

int main()
{
	Solution s;
	vector<vector<int> > v = { { 1, 2, 3 }, { 4, 5, 6 }, { 8, 7, 9 } };
	//vector<vector<int> > v = { { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 } };
	cout << s.minPathSum(v)<< endl;

	system("pause");

	return 0;

}

