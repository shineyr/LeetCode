#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

	//方法一：使用stl库函数
	int findMin1(vector<int>& nums) {
		if (nums.empty())
			return 0;

		vector<int>::iterator iter = min_element(nums.begin(), nums.end());
		return *iter;
	}

	//方法二：整个数列除一处为最大值到最小值的跳转外，为两部分的递增
	int findMin2(vector<int>& nums)
	{
		if (nums.empty())
			return 0;
		if (nums.size() == 1)
			return nums[0];
		for (size_t i = 1; i < nums.size(); ++i)
		{
			if (nums[i - 1] > nums[i])
				return nums[i];
		}//for
		//没有找到跳转元素，则序列无旋转
		return nums[0];
	}

	//方法三：二分查找
	int findMin(vector<int> &nums)
	{
		if (nums.empty())
			return 0;
		else if (nums.size() == 1)
			return nums[0];
		else{
			int lhs = 0, rhs = nums.size() - 1;

			while (lhs < rhs && nums[lhs] >= nums[rhs])
			{
				int mid = (lhs + rhs) / 2;
				if (nums[lhs] > nums[mid])
					rhs = mid;
				else if (nums[lhs] == nums[mid])
					++lhs;
				else
					lhs = mid + 1;
			}//while
			return nums[lhs];
		}
	}
};

int main()
{
	Solution s;
	vector<int> v = { 10,1,10,10 };
	cout << s.findMin(v) << endl;

	system("pause");
	return 0;
}