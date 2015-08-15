#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int majorityElement(vector<int>& nums) {
		//题目假设输入数组非空，且出现次数大于[n/2]的元素存在
		int len = nums.size() , count = len/2;

		sort(nums.begin(), nums.end());

		if (len == 1)
			return nums[0];
		int tmp = 1;
		for (int i = 0; i < len-1; i++)
		{
			if (nums[i + 1] == nums[i])
			{
				++tmp;
				if (tmp > count)
					return nums[i];
			}
			else{
				tmp = 1;
			}//if
		}//for
		return -1;
	}
};

int main()
{
	int arr[10] = { 1, 2, 3, 4, 4, 6, 4, 4, 5, 6 };
	//int arr[1] = { 1};
	vector<int> v(arr, arr + 10);

	Solution s;
	cout << s.majorityElement(v) << endl;

	system("pause");
	return 0;
}
