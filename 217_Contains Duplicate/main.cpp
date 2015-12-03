#include <iostream>
#include <cstdlib>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		if (nums.empty())
			return false;

		unordered_set<int> us;
		int len = nums.size();

		for (int i = 0; i < len; ++i)
		{
			if (us.count(nums[i]) != 0)
				return true;
			else
				us.insert(nums[i]);
		}
		return false;
				
	}
};

int main()
{
	Solution s;
	vector<int> v = { 1, 2, 3 };
	cout << s.containsDuplicate(v) << endl;

	system("pause");
	return 0;
}