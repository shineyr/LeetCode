#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		if (candidates.empty() || target < 0)
			return vector<vector<int> >();

		ret.clear();
		//将给定序列排序
		sort(candidates.begin(), candidates.end());

		vector<int> tmp;
		combination(candidates, 0, tmp, target);
		return ret;
	}

	//递归实现
	void combination(vector<int> &candidates, int idx, vector<int> &tmp, int target)
	{
		if (target == 0)
		{
			ret.push_back(tmp);
			return;
		}
		else{
			int len = candidates.size();
			for (int i = idx; i < len; i++)
			{
				if (target >= candidates[i])
				{
					tmp.push_back(candidates[i]);
					combination(candidates, i, tmp, target - candidates[i]);
					tmp.pop_back();
				}//if
			}//for
		}//else
	}

private:
	vector<vector<int> > ret;
};

int main()
{
	Solution s;
	vector<int> v = { 2, 3, 6, 7 };
	int target = 7;

	vector<vector<int> > ret = s.combinationSum(v, target);

	if (!ret.empty())
	{
		int size = ret.size();
		for (int i = 0; i < size; i++)
		{
			int len = ret[i].size();
			for (int j = 0; j < len; j++)
			{
				cout << ret[i][j] << "\t";
			}
			cout << endl;
		}
	}

	system("pause");
	return 0;
}