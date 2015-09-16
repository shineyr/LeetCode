#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {

		if (matrix.empty())
			return;

		//求得所给矩阵的行数、列数
		int m = matrix.size();
		int n = matrix.front().size();

		//初始化首行，首列标志位false，代表元素不为0
		bool f_row = false, f_col = false;

		for (int j = 0; j < n; j++)
		{
			if (matrix[0][j] == 0)
			{
				f_row = true;
				break;
			}//if
		}//for

		//记录首行、首列的状态
		for (int i = 0; i < m; i++)
		{
			if (matrix[i][0] == 0)
			{
				f_col = true;
				break;
			}//if
		}//for

		//下面用原矩阵的首行和首列
		for (int i = 1; i < m; i++)
		{
			for (int j = 1; j < n; j++)
			{
				//如果元素（i,j）为0，则将该元素对应的首行位置（0，j）以及首列位置（i,0）值赋为0
				if (matrix[i][j] == 0)
				{
					matrix[0][j] = 0;
					matrix[i][0] = 0;
				}//if
			}//for
		}//for

		//下面根据首行，首列元素值，更新矩阵中的0
		for (int j = 1; j < n; j++)
		{
			//找到元素为0的坐标，将矩阵中该列元素全部更改为0
			if (matrix[0][j] == 0)
			{
				for (int i = 0; i < m; i++)
					matrix[i][j] = 0;
			}//if
		}

		for (int i = 1; i < m; i++)
		{
			if (matrix[i][0] == 0)
			{
				for (int j = 0; j < n; j++)
					matrix[i][j] = 0;
			}//if
		}//for


		//最后处理首行和首列
		if (f_row)
		{
			for (int j = 0; j < n; j++)
				matrix[0][j] = 0;
		}

		if (f_col)
		{
			for (int i = 0; i < m; i++)
				matrix[i][0] = 0;
		}

	}
};

int main()
{
	Solution s;



	vector<vector<int> > v = { { 0, 0, 0, 5 }, { 4, 3, 1, 4 }, { 0, 1, 1,4 }, { 1, 2, 1, 3 }, { 0, 0, 1, 1 } };

	cout << "before:" << endl;

	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v[0].size(); j++)
		{
			cout << v[i][j] << "\t";
		}//for
		cout << endl;
	}//for

	s.setZeroes(v);

	cout << endl << "after:" << endl;

	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v[0].size(); j++)
		{
			cout << v[i][j] << "\t";
		}//for
		cout << endl;
	}//for

	system("pause");
	return 0;
}