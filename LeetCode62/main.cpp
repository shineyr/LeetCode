#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

////递归实现回溯，会超时
//class Solution {
//public:
//	int uniquePaths(int m, int n) {
//		if (m == 0 || n == 0)
//			return 0;
//		//如果矩阵为单行或者单列，则只有一条路径
//		else if (m == 1 || n == 1)
//			return 1;
//
//		else
//			return uniquePaths(m, n - 1) + uniquePaths(m - 1, n);
//	}
//};

//非递归实现回溯，会超时
class Solution {
public:
	int uniquePaths(int m, int n) {
		if (m == 0 || n == 0)
			return 0;
		vector<vector<int> > ret(m, vector<int>(n, 1));
		//如果矩阵为单行或者单列，则只有一条路径
		for (int i = 1; i < m; i++)
		for (int j = 1; j < n; j++)
			ret[i][j] = ret[i - 1][j] + ret[i][j - 1];
		
		return ret[m-1][n-1];
	}
};


int main()
{
	Solution s;
	cout << s.uniquePaths(23, 12) << endl;

	system("pause");
	return 0;
}