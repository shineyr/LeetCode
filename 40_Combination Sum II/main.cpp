#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		if (candidates.empty())
			return vector<vector<int> >();

		sort(candidates.begin(), candidates.end());

		ret.clear();

		vector<int> tmp;
		combination(candidates, 0, tmp, target);
		return ret;
	}

	void combination(vector<int> &candidates, int idx, vector<int> &tmp, int target)
	{
		if (target == 0)
		{
			if (find(ret.begin(), ret.end(), tmp) == ret.end())
				ret.push_back(tmp);
			return;
		}
		else{
			int size = candidates.size();
			for (int i = idx; i < size; ++i)
			{
				if (target >= candidates[i])
				{
					tmp.push_back(candidates[i]);
					combination(candidates, i + 1, tmp, target - candidates[i]);
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
	vector<int> v = { 10, 1, 2, 7, 6, 1, 5 };
	int target = 8;

	vector<vector<int> > ret = s.combinationSum2(v, target);

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