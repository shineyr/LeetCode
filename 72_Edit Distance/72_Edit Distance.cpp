#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//编辑距离问题属于动态规划
class Solution {
public:
	int minDistance(string word1, string word2) {
		//若其中一个字符串为空，则最短编辑距离为另一字符串的长度
		if (word1.empty())
			return word2.size();
		else if (word2.empty())
			return word1.size();

		//注意下标处理
		int m = word1.size() + 1, n = word2.size() + 1;

		//记录编辑距离的二维数组
		vector<vector<int> > distance(m, vector<int>(n, 0));
		for (int i = 0; i < m; i++)
			distance[i][0] = i;
		for (int j = 0; j < n; j++)
			distance[0][j] = j;

		for (int i = 1; i < m; i++)
		{
			for (int j = 1; j < n; j++)
			{
				if (word1[i-1] == word2[j-1])
					distance[i][j] = distance[i - 1][j - 1];
				else
					distance[i][j] = distance[i - 1][j - 1] + 1;

				distance[i][j] = min(distance[i][j], min(distance[i - 1][j] + 1, distance[i][j - 1] + 1));
			}//for
		}//for
		return distance[m - 1][n - 1];
	}
};

int main()
{
	Solution s;
	cout << s.minDistance("eeba", "abca") << endl;

	system("pause");
	return 0;
}
