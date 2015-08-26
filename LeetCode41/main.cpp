
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		if (nums.empty())
			return 1;

		//给定序列的长度
		int len = nums.size();
		vector<int> hash(len+1);
		
		for (int i = 0; i < len; i++)
		{
			if (nums[i] <= 0 || nums[i]>len)
				continue;
			else
				hash[nums[i]] = 1;
		}

		////利用O(n)的时间复杂度，常数空间，调整序列中元素，没有实现！！！
		//for (int i = 0; i < len; i++)
		//{
		//	//不符合规则的元素对应位置设为-1
		//	if (nums[i] <= 0 || nums[i] > len)
		//	{
		//		nums[i] = -1;
		//		continue;
		//	}//if

		//	else if (nums[i] != (i+1)) //元素值为value的下标应该位于value-1上，如果不是，与value-1位置的元素交换
		//	{
		//		//记录在对应位置的元素
		//		int temp = nums[nums[i] - 1];
		//		//交换元素只需要常数空间
		//		swap(nums[i], nums[nums[i] - 1]);
		//		
		//		//此时temp位于
		//		if (temp <= 0 || temp > len)
		//		{
		//			nums[i] = -1;
		//			continue;
		//		}
		//		else{

		//			swap(nums[temp - 1], nums[i]);
		//		}//else
		//	}//elif
		//}//for

		for (int i = 1; i < len+1; i++)
			if (hash[i] != 1)
				return i;
		return len+1;
	}
};

int main()
{
	Solution s;
	vector<int> v = {  1 , 2 };
	cout << s.firstMissingPositive(v) << endl;

	system("pause");
	return 0;
}