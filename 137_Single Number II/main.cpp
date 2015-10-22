#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	/*利用算法库的排序实现，复杂度为O(nlogn)*/
	//int singleNumber(vector<int>& nums) {
	//	if (nums.empty())
	//		return -1;

	//	sort(nums.begin(), nums.end());

	//	int size = nums.size();

	//	for (int i = 0; i < size - 2; i+=3)
	//	{
	//		if (nums[i] != nums[i + 1])
	//			return nums[i];
	//	}
	//	return nums[size - 1];
	//}

	/* 方法二：
	 * int 数据共有32位,可以用32变量存储这 N 个元素中各个二进制位上 1 出现的次数，
	 * 最后 在进行 模三 操作，如果为1，那说明这一位是要找元素二进制表示中为 1 的那一位。
	 * 时间：O(32*N)，这是一个通用的解法，如果把出现3次改为 k 次，那么只需模k就行了
	 */
	//int singleNumber(vector<int>& nums) {
	//	if (nums.empty())
	//		return -1;
	//	vector<int> bitnum(32, 0);
	//	int res = 0 , size = nums.size();
	//	for (int i = 0; i < 32; i++){
	//		for (int j = 0; j < size; j++){
	//			bitnum[i] += (nums[j] >> i) & 1;
	//		}
	//		res |= (bitnum[i] % 3) << i;
	//	}
	//	return res;
	//}
	/* 方法三：
	 * 利用三个变量分别保存各个二进制位上 1 出现一次、两次、三次的分布情况，最后只需返回变量一。
	 */

	int singleNumber(vector<int>& nums) {
		if (nums.empty())
			return -1;
		int size = nums.size();
		int one = 0, two = 0, three = 0;
		for (int i = 0; i < size; i++){
			two |= one&nums[i];
			one ^= nums[i];
			//cout<<one<<endl;
			three = one&two;
			one &= ~three;
			two &= ~three;
		}
		return one;
	}
};

int main()
{
	Solution s;
	vector<int> v = { 1,2, 3,3,2,  3, 2 };

	cout << s.singleNumber(v) << endl;

	system("pause");
	return 0;
}