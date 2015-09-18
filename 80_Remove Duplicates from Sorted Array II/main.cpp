#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.empty())
			return 0;

		int len = nums.size();
		if (len <= 2)
			return len;

		vector<int> ret;
		for (int i = 0; i < len; i++)
		{
			int temp = nums[i];
			int count = 1;
			while (i < (len-1) &&nums[i + 1] == temp)
			{
				i++;
				count++;
			}
			if (count >= 2)
			{
				ret.push_back(nums[i]);
				ret.push_back(nums[i]);
			}
			else if (count == 1)
				ret.push_back(nums[i]);
		}//for

		nums.clear();
		nums = ret;

		return ret.size();
	}
};

int main()
{
	Solution s;
	vector<int> v = { 1, 1, 1, 2, 2, 3 };

	cout << s.removeDuplicates(v) << endl;

	system("pause");
	return 0;
}