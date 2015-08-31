#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int> > ret;

		if (nums.empty())
			return ret;

		sort(nums.begin(), nums.end());
		ret.push_back(nums);
		while (next_permutation(nums.begin(), nums.end()))
			ret.push_back(nums);

		return ret;
	}
};

int main()
{
	Solution s;
	vector<vector<int> > v = s.permute(vector<int>{0, -1, 1});

	for (int i = 0; i < v.size(); i++)
		cout << v[i][0] << "\t" << v[i][1] << "\t" << v[i][2] << endl;

	system("pause");

	return 0;
}