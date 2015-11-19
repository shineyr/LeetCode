#include <iostream>
#include <cstdlib>
#include <vector>
#include <unordered_set>
#include <map>
using namespace std;

class Solution {
public:
	//方法一，TLE
	bool containsNearbyAlmostDuplicate1(vector<int>& nums, int k, int t) {
		if (nums.empty())
			return false;

		int sz = nums.size();
		//使用容器unordered_set 其查找性能为常量
		unordered_set<int> us;
		int start = 0, end = 0;
		for (int i = 0; i < sz; ++i)
		{
			int len = us.size();
			for (int j = 0; j < len; ++j)
			{
				int tmp = abs(nums[j] - nums[i]);
				if (tmp <= t)
					return true;
			}//for
			us.insert(nums[i]);
			++end;
			
			if (end - start > k)
			{
				us.erase(nums[start]);
				++start;
			}
		}//for
		return false;

	}
	//方法二：
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		if (nums.empty())
			return false;

		int sz = nums.size();
		map<long long, int > m;
		int start = 0;
		for (int i = 0; i < sz; ++i)
		{
			if (i - start >k && m[nums[start]] == start)
				m.erase(nums[start++]);

			auto a = m.lower_bound(nums[i] - t);
			if (a != m.end() && abs(a->first - nums[i]) <= t)
				return true;
			//将元素值和下标插入map
			m[nums[i]] = i;
		}//for
		return false;
		return false;

	}
};

int main()
{
	vector<int> v = { 1, 2, 3, 4, 5, 6, 2 };
	Solution s;
	bool ret = s.containsNearbyAlmostDuplicate(v, 6,2);

	cout << ret;
	system("pause");
	return 0;
}