#include <iostream>
#include <cstdlib>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		if (nums.empty())
			return false;

		int sz = nums.size();
		//使用容器unordered_set 其查找性能为常量
		unordered_set<int> us;
		int start = 0, end = 0;
		for (int i = 0; i < sz; ++i)
		{
			if (us.count(nums[i]) == 0)
			{
				us.insert(nums[i]);
				++end;
			}
			else{
				return true;
			}

			if (end - start > k)
			{
				us.erase(nums[start]);
				++start;
			}
		}//for
		return false;

	}
};

int main()
{
	vector<int> v = { 1, 2, 3, 4, 5, 6, 2 };
	Solution s;
	bool ret = s.containsNearbyDuplicate(v, 6);

	cout << ret;
	system("pause");
	return 0;
}