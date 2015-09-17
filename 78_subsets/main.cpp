#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		if (nums.empty())
			return vector<vector<int>>();

		sort(nums.begin(), nums.end());

		vector<vector<int>> ret =  getSubsets(nums);
		ret.push_back(vector<int>());

		return ret;
	}

	vector<vector<int>> getSubsets(vector<int>& nums) {
		if (nums.empty())
			return vector<vector<int>>();
		int len = nums.size();
		//初始化一个包含空元素的结果vector
		vector<vector<int> > ret;

		//用0~len-1个原数组元素，建立一个新数组
		vector<int> tem_nums(nums.begin(), nums.begin() + len - 1);
		vector<vector<int>> tmp = getSubsets(tem_nums);
		int t_size = tmp.size();
		
		//第一部分，0~len-1所有元素的真子集
		for (int i = 0; i < t_size; i++)
		{
			ret.push_back(tmp[i]);
		}//for
		
		//第二部分，加入第len个元素
		ret.push_back(vector<int>(1, nums[len - 1]));
		
		//第三部分，0~len-1所有元素的真子集，加入第len个元素
		for (int i = 0; i < t_size; i++)
		{
			tmp[i].push_back(nums[len - 1]);
			ret.push_back(tmp[i]);
		}//for

		return ret;
	}
};

int main()
{
	Solution s;

	vector<int> vi = { 1, 2, 3 };
	vector<vector<int> > v = s.subsets(vi);
	int len = v.size();
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < v[i].size(); j++)
		{
			cout << v[i][j] << "\t";
		}//for
		cout << endl;
	}

	system("pause");
	return 0;
}

