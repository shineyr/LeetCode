#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		if (nums.empty())
			return;

		int sz = nums.size();
		
		int count = 0;
		for (int i = 0, k = 0; i < sz; ++i)
		{
			if (nums[i] != 0)
			{
				nums[count] = nums[i];
				++count;
			}
			continue;
		}
		while (count < sz){
			nums[count++] = 0;
		}
		return;
	}
};

int main()
{
	Solution s;
	vector<int> v = { 0, 1, 0, 3, 12 };
	s.moveZeroes(v);

	for (unsigned i = 0; i < v.size(); ++i)
	{
		cout << v[i] << "\t";
	}//for
	cout << endl;

	system("pause");
	return 0;
}