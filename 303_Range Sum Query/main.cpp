#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class NumArray {
public:
	NumArray(vector<int> &nums) {
		if (nums.empty())
			return ;
		else
		{
			sums.push_back(nums[0]);
			//求得给定数列长度
			int len = nums.size();
			for (int i = 1; i < len; ++i)
			{
				sums.push_back(sums[i - 1] + nums[i]);
			}//for
		}
	}

	//计算[i,j]序列和
	int sumRange(int i, int j) {
		if (0 == i)
			return sums[j];
		int len = sums.size();

		if (i < 0 || i >= len || j < 0 || j >= len || i > j)
		{
			return 0;
		}//if
		return sums[j] - sums[i-1];
	}

private:
	//存储数列和
	vector<int> sums;
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);

int main()
{
	vector<int> nums = { -2, 0, 3, -5, 2, -1 };

	NumArray na(nums);
	cout << na.sumRange(0, 2) << endl;
	cout << na.sumRange(2, 5) << endl;
	cout << na.sumRange(0, 5) << endl;

	system("pause");
	return 0;
}