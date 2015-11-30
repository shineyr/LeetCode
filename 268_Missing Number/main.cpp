#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	/*方法一：排序法，时间复杂度为O(nlogn)*/
	int missingNumber1(vector<int>& nums) {
		if (nums.empty())
			return 0;

		sort(nums.begin(), nums.end());

		for (unsigned i = 0; i < nums.size(); ++i)
		{
			if (nums[i] != i)
				return i;
		}//for
		return nums.size();
	}

	/*方法二：等差数列，期望序列元素为 0 - n ; 实际元素缺失一个，用(0+1+...+n)-(实际元素之和)即是缺失元素*/
	int missingNumber(vector<int>& nums) {
		if (nums.empty())
			return 0;
		int n = nums.size();

		//先求得0+1+2+...+n的和
		int sum = 0, i = 0;
		while (i <= n)
		{
			sum += (i++);
		}
		//找出缺失元素
		for (int i = 0; i < n; ++i)
		{
			sum -= nums[i];
		}//for
		return sum;
	}
};

int main()
{
	Solution s;
	vector<int> v = { 0, 1, 2 };
	cout << s.missingNumber(v) << endl;

	system("pause");
	return 0;
}