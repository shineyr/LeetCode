#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		if (matrix.empty())
			return vector<int>();

		vector<int> ret;

		//输入矩阵行数
		int m = matrix.size() - 1;

		//输入矩阵的列数
		int n = matrix[0].size() - 1;

		for (int x = 0, y = 0; x <= m && y <= n; x++, y++)
		{
			//输出矩阵首行
			for(int j=y ; j<=n ; ++j)
			{
				ret.push_back(matrix[x][j]);
			}//while

			
			//输出矩阵最右列
			for (int i = x + 1; i <= m; ++i)
			{
				ret.push_back(matrix[i][n]);
			}//while

			//输出矩阵最底行
			for (int j = n - 1; j >= y && x != m; --j)
			{
				ret.push_back(matrix[m][j]);
			}

			//输出矩阵最左列
			for (int i = m - 1; i > x && y != n; --i)
			{
				ret.push_back(matrix[i][y]);
			}

			m--;
			n--;
		}//for

		return ret;
	}
};

int main()
{
	Solution s;
	vector<vector<int> > v = { { 1, 2, 3, 4 }/*, { 5, 6, 7, 8 }, { 9, 10, 11, 12 }, { 13, 14, 15, 16 }*/ };

	vector<int> ret = s.spiralOrder(v);

	for (int i = 0; i < ret.size(); i++)
		cout << ret[i] << "\t";
	cout << endl;

	system("pause");
	return 0;
}