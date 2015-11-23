#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:
	int findDuplicate(vector<int>& nums) {
		if (nums.empty())
			return 0;
		//数组中共有n个元素 范围在1-(n-1)
		int len = nums.size();
		int min = 0, max = len - 1;
		while (min <= max){
			// 找到中间那个数
			int mid = min + (max - min) / 2;
			int cnt = 0;
			// 计算总数组中有多少个数小于等于中间数
			for (int i = 0; i < len; i++){
				if (nums[i] <= mid){
					cnt++;
				}
			}
			// 如果小于等于中间数的数量大于中间数，说明前半部分必有重复
			if (cnt > mid){
				max = mid - 1;
				// 否则后半部分必有重复
			}
			else {
				min = mid + 1;
			}
		}
		return min;
	}
};

int main()
{
	vector<int> v = { 1, 2, 2, 3, 4 };
	Solution s;
	cout << s.findDuplicate(v) << endl;

	system("pause");
	return 0;
}