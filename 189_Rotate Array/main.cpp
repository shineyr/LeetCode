#include <iostream>
#include <cstdlib>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		if (nums.empty())
			return;

		int size = nums.size();

		//确定最终右旋元素个数
		
		k %= size;

		vector<int>::iterator beg = nums.begin();
		//旋转0~(size-k) (size-k , size);
		reverse(beg, beg + size - k);
		reverse(beg + size - k, nums.end());
		//最后一次全部反转，即可完成
		reverse(beg, nums.end());
	}
};


int main()
{
	vector<int> v = { 1, 2, 3, 4, 5, 6, 7 };
	Solution s;
	s.rotate(v,5);

	for (size_t i = 0; i < v.size(); ++i)
		cout << v[i] << "\t";
	cout << endl;

	system("pause");
	return 0;
}