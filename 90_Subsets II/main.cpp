#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		vector<vector<int> > ret(1, vector<int>());

		if (nums.empty())
			return ret;

		sort(nums.begin(), nums.end());

		int size = nums.size();
		for (int i = 0; i < size; ++i)
		{
			ret = subSets(ret, nums, i);
		}
		return ret;
	}

	vector<vector<int> > subSets(vector<vector<int> > &ret, vector<int> &nums, int &idx)
	{
		vector<int> tmp;
		int count = ret.size();

		//对于每一个已有子集合，加入新元素
		for (int i = 0; i < count; ++i)
		{
			//当前集合
			tmp = ret[i];		
			//加入第idx个元素
			tmp.push_back(nums[idx]);
			//判重
			if (find(ret.begin(), ret.end(), tmp) != ret.end())
				continue;
			ret.push_back(tmp); 
		}//for

		return ret;
	}
};

int main()
{
	Solution s;
	vector<int> nums = { 1, 2, 2 };
	vector<vector<int> > ret = s.subsetsWithDup(nums);

	for (size_t i = 0; i < ret.size(); ++i)
	{
		cout << "[";
		for (size_t j = 0; j < ret[i].size(); ++j)
		{
			cout << " " << ret[i][j];
		}
		cout << "]" << endl;
	}//for

	system("pause");
	return 0;
}