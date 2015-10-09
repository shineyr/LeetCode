#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> getRow(int rowIndex) {
		if (rowIndex == 0)
			return  vector<int>(1,1);

		//存储上一行vector
		vector<int> pre = getRow(rowIndex - 1);

		//计算当前行
		vector<int> cur(rowIndex + 1, 0);
		//初始化首尾元素
		cur[0] = 1;
		cur[rowIndex] = 1;

		//计算中间元素
		for (int i = 1; i < rowIndex; ++i)
		{
			cur[i] = pre[i-1] + pre[i];
		}//for

		return cur;
	}
};

int main()
{
	Solution s;

	vector<int> ret = s.getRow(3);
	for (size_t j = 0; j < ret.size(); ++j)
		cout << ret[j] << "\t";
	cout << endl;


	system("pause");
	return 0;
}
