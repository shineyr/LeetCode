#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int trap(vector<int>& height) {
		if (height.empty())
			return 0;

		int len = height.size();

		int lhs = 0, rhs = len - 1, secHeight = 0;

		int area = 0;

		//从两边向中间统计，分别统计每个竖立格子可以盛的水量
		while (lhs < rhs)
		{
			if (height[lhs] < height[rhs])
			{
				secHeight = max(height[lhs], secHeight);
				//加上lhs竖格的盛水量
				area += secHeight - height[lhs];
				//左侧右移一格
				lhs++;
			}
			else{
				secHeight = max(height[rhs], secHeight);
				//加上rhs竖格的盛水量
				area += secHeight - height[rhs];
				//右侧左移一格
				rhs--;
			}//fi
		}//while

		return area;
	}
};

int main()
{
	Solution s;

	vector<int> height = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };

	cout << s.trap(height) << endl;

	system("pause");
	return 0;
}