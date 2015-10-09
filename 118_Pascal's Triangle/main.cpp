#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		if (numRows == 0)
			return vector<vector<int>>();
		else if (numRows == 1)
			return vector<vector<int>>(1, vector<int>(1, 1));

		//存储当前金字塔
		vector<vector<int> > ret = generate(numRows - 1);
		//计算当前行
		vector<int> cur(numRows, 0);
		cur[0] = 1;
		cur[numRows - 1] = 1;

		for (int i = 1; i < numRows - 1; ++i)
		{
			cur[i] = ret[numRows - 2][i - 1] + ret[numRows - 2][i];
		}//for
		ret.push_back(cur);

		return ret;
	}
};

int main()
{
	Solution s;

	vector<vector<int> > ret = s.generate(6);
	for (size_t i = 0; i < ret.size(); ++i)
	{
		for (size_t j = 0; j < ret[i].size(); ++j)
			cout << ret[i][j] << "\t";
		cout << endl;
	}

	system("pause");
	return 0;
}