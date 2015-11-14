#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		if (triangle.empty())
			return 0;

		int rows = triangle.size();

		//动态规划,由于空间复杂度要求，现利用原始二维数组triangle改为存储当前(i,j)位置的最小和
		for (int i = 1; i < rows; ++i)
		{
			int cols = triangle[i].size();
			for (int j = 0; j < cols; ++j)
			{
				//本行的第一个元素
				if (0 == j)
				{
					triangle[i][j] = triangle[i][j] + triangle[i - 1][j];
				}
				//本行的最后一个元素
				else if (j == cols - 1)
				{
					triangle[i][j] += triangle[i - 1][j - 1];
				}
				else{
					triangle[i][j] = min(triangle[i][j] + triangle[i - 1][j - 1], triangle[i][j] + triangle[i - 1][j - 1]);
				}//else
			}//for
		}//for
		//最小路径和为最后一行的最小值
		int minSum = triangle[rows - 1][0];
		for (int j = 0; j < triangle[rows - 1].size(); ++j)
		{
			if (minSum > triangle[rows - 1][j])
				minSum = triangle[rows - 1][j];
		}//for
		return minSum;
	}
};

int main()
{
	vector<vector<int>> v = { { 2 }, { 3, 4 }, { 6, 5, 7 }, { 4, 1, 8, 3 } };
	Solution s;
	cout << s.minimumTotal(v) << endl;

	system("pause");
	return 0;
}
