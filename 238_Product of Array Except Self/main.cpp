#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		if (nums.empty())
			return vector<int>();

		int sz = nums.size();
		vector<int> ret(sz, 0);

		//对每个i位置的元素得到ret[i] = nums[0] * nums[1] * ... *nums[i-1]
		ret[0] = 1;
		for (int i = 1; i < sz; ++i)
		{
			ret[i] = ret[i - 1] * nums[i-1];
		}//for

		//对每个i位置的元素当前乘积ret[i] *= nums[i+1] ... nums[sz-1]
		int tmp = 1;
		for (int i = sz - 1; i >= 0; --i)
		{
			ret[i] *= tmp;
			tmp *= nums[i];
		}
		return ret;
	}
};

int main()
{
	Solution s;
	vector<int> v = { 1, 2, 3, 4 };

	v = s.productExceptSelf(v);

	for (unsigned i = 0; i < v.size(); ++i)
		cout << v[i] << endl;
	cout << endl;

	system("pause");
	return 0;
}