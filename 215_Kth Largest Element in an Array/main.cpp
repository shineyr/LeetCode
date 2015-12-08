#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	//方法一：直观解法 时间复杂度O(nlogn)
	int findKthLargest1(vector<int>& nums, int k) {
		int len = nums.size();
		if (len <= 0 || k > len || k < 0)
			return INT_MIN;

		sort(nums.begin(), nums.end());

		return nums[len - k];
	}

	//方法二：快速选择算法，利用两个辅助数组
	int findKthLargest(vector<int>& nums, int k) {
		int len = nums.size();
		if (len <= 0 || k > len || k < 0)
			return INT_MIN;
		vector<int> A1, A2;
		int idx = rand() % len;
		int key = nums[idx];
		for (int i = 0; i < len; ++i)
		{
			if (nums[i] < key)
				A1.push_back(nums[i]);
			else if (nums[i] < key)
				A2.push_back(nums[i]);
			else
				continue;
		}//for

		if (k <= A1.size())
			return findKthLargest(A1, k);
		else if (k > (len - A2.size()))
			return findKthLargest(A2, k - (len - A2.size()));
		else
			return key;
	}
};

int main()
{
	Solution s;
	vector<int> v = { 3, 2, 1, 5, 6, 4 };
	cout << s.findKthLargest1(v, 2) << endl;

	system("pause");
	return 0;
}