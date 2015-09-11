#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

//直接用非递归算法求解
class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

		if (obstacleGrid.empty())
			return 0;

		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();

		vector<vector<int> > ret(m, vector<int>(n, 0));

		//矩阵首列
		for (int i = 0; i < m; i++)
		{
			//无障碍，则有一条路径，否则不通
			if (obstacleGrid[i][0] != 1)
				ret[i][0] = 1;
			else
				break;
		}//for

		//矩阵首行
		for (int j = 0; j < n; j++)
		{
			//无障碍，则有一条路径，否则不通
			if (obstacleGrid[0][j] != 1)
				ret[0][j] = 1;
			else
				break;
		}//for

		//其余位置
		for (int i = 1; i < m; i++)
		{
			for (int j = 1; j < n; j++)
			{
				//当前位置为障碍，则到此处路径数为0
				if (obstacleGrid[i][j] == 1)
					ret[i][j] = 0;
				else{
					ret[i][j] = ret[i][j - 1] + ret[i - 1][j];
				}//else
			}//for
		}//for

		return ret[m - 1][n - 1];
	}//uniques

};

int main()
{
	Solution s;

	//vector<vector<int> > v = { { 0, 0, 0 }, { 0, 1, 0 }, { 0, 0, 0 } };
	vector<vector<int> > v = { { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }};
	cout << s.uniquePathsWithObstacles(v) << endl;

	system("pause");

	return 0;
}