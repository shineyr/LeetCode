#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:
	int findMin(vector<int>& nums) {
		if (nums.empty())
			return INT_MIN;

		//元素个数
		int size = nums.size();

		int lhs = 0, rhs = size - 1;
		while (lhs <= rhs)
		{
			//递增状态，返回低位值
			if (nums[lhs] <= nums[rhs])
				return nums[lhs];
			//相邻，返回较小值
			else if (rhs - lhs == 1)
				return nums[lhs] < nums[rhs] ? nums[lhs] : nums[rhs];

			//判断子序列
			int mid = (lhs + rhs) / 2;
			//右侧递增，则最小值位于左半部分
			if (nums[mid] < nums[rhs])
			{
				rhs = mid;
			}
			//否则，最小值位于右半部分
			else{
				lhs = mid + 1;
			}
		}//while
	}

	//优化函数
	int findMin2(vector<int>& nums)
	{
		if (nums.size() == 1)
			return nums[0];

		int lhs = 0, rhs = nums.size() - 1;

		while (nums[lhs] > nums[rhs])
		{
			int mid = (lhs + rhs) / 2;
			if (nums[mid] > nums[rhs])
				lhs = mid + 1;
			else
				rhs = mid;
		}//while
		return nums[lhs];
	}
};

int main()
{
	Solution s;
	vector<int> v = { 4, 5, 6, 7, 0, 1, 2 };
	cout << s.findMin2(v) << endl;

	system("pause");
	return 0;
}