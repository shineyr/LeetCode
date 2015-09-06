#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int> > ret(n,vector<int>(n , 0));
		if (n <= 0)
			return ret;
		
		int index = 1 , row = n-1 , col = n-1;
		for (int x = 0, y = 0; x <= row && y <= col; x++, y++)
		{
			//为矩阵首行赋值
			for (int j = y; j <= col; ++j , index++)
				ret[x][j] = index;

			//为矩阵最右列赋值
			for (int i = x + 1; i <= row; ++i,index++)
				ret[i][col] = index;

			//为矩阵最底行赋值
			for (int j = col - 1; j >= y && x != row; --j, index++)
				ret[row][j] = index;

			//为矩阵最左列赋值
			for (int i = row - 1; i > x && y != col; --i, index++)
				ret[i][y] = index;

			//为内旋子矩阵赋值
			row--;
			col--;

		}//for
		return ret;
	}
};

int main()
{
	Solution s;
	int n = 5;
	vector<vector <int> > v = s.generateMatrix(n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << v[i][j] << "\t";
		}
		cout << endl;
	}//for

	system("pause");
	return 0;
}