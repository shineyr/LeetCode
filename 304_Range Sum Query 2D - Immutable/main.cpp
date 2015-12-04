#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class NumMatrix {
public:
	NumMatrix(vector<vector<int>> &matrix) {
		if (matrix.empty())
			return;

		//求得二维矩阵的行列
		int m = matrix.size(), n = matrix[0].size();
		sums = vector<vector<int>>(m+1, vector<int>(n+1, 0));
		sums[0][0] = matrix[0][0];
		for (int j = 1; j <= n; ++j)
		{
			sums[0][j] = 0;
		}

		for (int i = 1; i <= m; ++i)
		{
			sums[i][0] = 0;
		}

		//
		for (int i = 1; i <= m; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				sums[i][j] = sums[i][j - 1] + sums[i - 1][j] - sums[i - 1][j - 1] + matrix[i-1][j-1];
			}//for
		}//for		
	}

	int sumRegion(int row1, int col1, int row2, int col2) {
		//求得二维矩阵的行列
		int m = sums.size(), n = sums[0].size();
		if (row1 < 0 || row1 >= m || col1 < 0 || col1 >= n || row2<0 || row2 >= m ||
			col2<0 || col2 >= n || row1 >row2 || col1 > col2)
		{
			return 0;
		}

		return sums[row2+1][col2+1] - sums[row2+1][col1] - sums[row1][col2+1] + sums[row1][col1];
	}

private:
	vector<vector<int>> sums;
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);

int main()
{
	vector<vector<int>> matrix = { 
		{ 3, 0, 1, 4, 2 },
		{ 5, 6, 3, 2, 1 },
		{ 1, 2, 0, 1, 5 },
		{ 4, 1, 0, 1, 7 },
		{ 1, 0, 3, 0, 5 } 
	};
	NumMatrix nm(matrix);

	cout << nm.sumRegion(0, 2, 0, 2) << endl;
	cout << nm.sumRegion(1, 1, 2, 2) << endl;
	cout << nm.sumRegion(1, 2, 2, 4) << endl;

	system("pause");
	return 0;
}