#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maxArea(vector<int>& height) {
		if (height.empty())
			return 0;

		int maxCapacity = 0;
		size_t lhs = 0, rhs = height.size() - 1;

		while (lhs < rhs)
		{
			int capacity = (rhs - lhs) * min(height[lhs], height[rhs]);
			if (capacity > maxCapacity)
			{
				maxCapacity = capacity;
			}

			if (height[lhs] < height[rhs])
				++lhs;
			else
				--rhs;
		}//while
		return maxCapacity;
	}
};

int main()
{
	Solution s;
	vector<int> v = { 1, 2, 3, 4 };
	cout << s.maxArea(v) << endl;

	system("pause");
	return 0;
}
