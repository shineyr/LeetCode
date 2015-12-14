#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <set>

using namespace std;


class Solution {
public:
	/*4-sum算法，递归实现，TLE*/
	vector<vector<int>> fourSum1(vector<int>& nums, int target) {
		if (nums.empty())
			return vector<vector<int>>();

		sort(nums.begin(), nums.end());

		return k_Sum(nums, 0, 4, target);
	}
	/*k-sum算法*/
	vector<vector<int>> k_Sum(vector<int> &nums, int begPos, int count, int target)
	{
		if (nums.empty())
			return vector<vector<int>>();
		/*所输入序列为已排序*/
		int len = nums.size();
		unordered_set<int> visited;
		vector<vector<int>> ret;
		vector<int> tmp;
		/*2-sum 处理*/
		if (2 == count)
		{
			int i = begPos, j = len - 1;
			while (i < j)
			{
				int sum = nums[i] + nums[j];
				if (sum == target && visited.find(nums[i]) == visited.end())
				{
					tmp.clear();
					tmp.push_back(nums[i]);
					tmp.push_back(nums[j]);
					ret.push_back(tmp);
				
					/*加入已访问set*/
					visited.insert(nums[i]);
					visited.insert(nums[j]);

					++i;
					--j;
				}//if
				else if (sum < target)
					++i;
				else
					--j;
			}//while
		}//if
		else{
			for (int i = begPos; i < len; ++i)
			{
				if (visited.find(nums[i]) == visited.end())
				{
					visited.insert(nums[i]);
					/*得到k-1 sum的序列*/
					vector<vector<int>> subRet = k_Sum(nums, i+1, count - 1, target-nums[i]);
					if (!subRet.empty())
					{
						int sz = subRet.size();
						for (int j = 0; j < sz; ++j)
						{
							subRet[j].insert(subRet[j].begin(), nums[i]);
						}//for
						ret.insert(ret.end(), subRet.begin(), subRet.end());
					}//if
				}//if
			}//for
		}//else
		/*返回结果集*/
		return ret;
	}

	/*4-sum算法，方法二，2-sum的变形*/
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		if (nums.empty() || nums.size() < 4)
			return vector<vector<int>>();

		sort(nums.begin(), nums.end());
		int len = nums.size();
		set<vector<int>> tmpRet;
		vector<vector<int>> res;

		for (int i = 0; i < len; ++i)
		{
			for (int j = i + 1; j < len; ++j)
			{
				int beg = j + 1, end = len - 1;
				while (beg < end)
				{
					int sum = nums[i] + nums[j] + nums[beg] + nums[end];
					if (sum == target)
					{
						vector<int> tmp = { nums[i], nums[j], nums[beg], nums[end] };
						tmpRet.insert(tmp);

						++beg;
						--end;
					}
					else if (sum < target)
					{
						++beg;
					}
					else
						--end;
				}//while
			}//for			
		}//for
		auto iter = tmpRet.begin();
		while (iter != tmpRet.end())
		{
			res.push_back(*iter);
			++iter;
		}//while
		return res;
	}

};

int main()
{
	Solution s;
	vector<int> v = { 1, 0, -1, 0, -2, 2 };
	vector<vector<int>>ret = s.fourSum(v,0);

	system("pause");
	return 0;
}