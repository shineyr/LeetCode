#include <iostream>
#include <cstdlib>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
	//方法一：借助数据结构unordered_set,占用了额外O(n)的空间
	vector<int> singleNumber1(vector<int>& nums) {
		if (nums.empty())
			return vector<int>();

		int len = nums.size();

		unordered_set<int> us;
		for (int i = 0; i < len; ++i)
		{
			if (us.count(nums[i]) == 0)
				us.insert(nums[i]);
			else
				us.erase(nums[i]);
		}//for

		return vector<int>(us.begin(), us.end());
	}

	//方法二：线性时间复杂度，常量空间复杂度
	vector<int> singleNumber(vector<int>& nums) {
		if (nums.empty())
			return vector<int>();

		int len = nums.size();
		int res = 0;
		for (int i = 0; i < len; ++i)
		{
			res ^= nums[i];
		}//for

		vector<int> ret(2, 0);
		//利用位运算，将原数组一分为二，每个部分含有一个只出现一次的数字，其余数字出现两次
		int n = res & (~(res - 1));
		for (int i = 0; i < len; ++i)
		{
			if ((n & nums[i]) != 0)
			{
				ret[0] ^= nums[i];
			}
			else{
				ret[1] ^= nums[i];
			}//else
		}//for

		return ret;
	}
};

int main()
{
	Solution s;
	vector<int> nums = { 1, 2, 1, 3, 2, 5 };

	vector<int> ret = s.singleNumber(nums);

	cout << ret[0] << "\t" << ret[1] << endl;

	system("pause");
	return 0;
}