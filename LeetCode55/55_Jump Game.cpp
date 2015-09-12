#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

//贪心算法
class Solution {
public:
	bool canJump(vector<int>& nums) {
		if (nums.empty())
			return false;

		int maxStep = nums[0];
		int len = nums.size();

		for (int i = 1; i < len; ++i)
		{
			if (maxStep <= 0)
				return false;
			else{
				maxStep = max(--maxStep, nums[i]);
			}//else
		}//for

		return true;
	}
};



int main()
{
	Solution s;
	vector<int> v1 = { 2, 3, 1, 1, 4 };
	vector<int> v2 = { 3, 2, 1, 0, 4 };
	bool ret = s.canJump(v1);

	cout << ret << endl;

	system("pause");
	return 0;

}