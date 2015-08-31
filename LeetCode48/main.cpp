#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		if (matrix.empty())
			return;

		int n = matrix.size();

		//首先，沿主对角线交换元素
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j <= i; j++)
				swap(matrix[i][j], matrix[j][i]);
		}
		//然后，交换对称列
		for (int i = 0, j = n - 1; i < j; i++, j--)
		{
			for (int k = 0; k < n; k++)
				swap(matrix[k][i], matrix[k][j]);
		}
	}
};

int main()
{
	Solution s;

	vector<vector<int> > ret = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 }, {13,14,15,16} };

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
			cout << ret[i][j] << "\t";
		cout << endl;
	}

	s.rotate(ret);
	cout << endl;
	cout << endl;
	cout << endl;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
			cout << ret[i][j] << "\t";
		cout << endl;
	}

	system("pause");
	return 0;
}