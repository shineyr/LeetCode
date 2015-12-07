#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	//方法一：STL库函数Sort排序，T(n)=O(nlogn)
	int maximumGap1(vector<int>& nums) {
		if (nums.empty() || nums.size() < 2)
			return 0;
		
		int len = nums.size();
		sort(nums.begin(), nums.end());
		int gap = 0;
		for (int i = 1; i < len; ++i)
		{
			if (nums[i] - nums[i - 1] > gap)
				gap = nums[i] - nums[i - 1];
		}//for
		return gap;
	}

	//方法二：桶排序
	int maximumGap(vector<int>& nums) {
		if (nums.empty() || nums.size() < 2)
			return 0;
		int n = nums.size();
		int minAll = *min_element(nums.begin(), nums.end());
		int maxAll = *max_element(nums.begin(), nums.end());
		// type conversion!!!
		double gap = ((double)(maxAll - minAll)) / (n - 1);
		// compute min and max element for each bucket
		vector<int> minV(n - 1, INT_MAX);
		vector<int> maxV(n - 1, INT_MIN);
		for (int i = 0; i < n; i++)
		{
			if (nums[i] != maxAll)
			{// the bktId of maxAll will fall out of bucket range
				int bktId = (int)((nums[i] - minAll) / gap);
				minV[bktId] = min(minV[bktId], nums[i]);
				maxV[bktId] = max(maxV[bktId], nums[i]);
			}
		}
		int ret = 0;
		int curMax = maxV[0];
		for (int i = 1; i < n - 1; i++)
		{
			if (minV[i] != INT_MAX)
			{
				ret = max(ret, minV[i] - curMax);
				curMax = maxV[i];
			}
		}
		ret = max(ret, maxAll - curMax);
		return ret;
	}
};

int main()
{
	vector<int> v = { 2, 6, 8, 1, 4, 3 };
	Solution s;
	cout << s.maximumGap(v) << endl;

	system("pause");
	return 0;
}