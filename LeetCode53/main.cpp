#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

//class Solution {
//public:
//	int maxSubArray(vector<int>& nums) {
//		
//		if (nums.empty())
//			return 0;
//
//		//求数组的长度
//		int len = nums.size();
//
//		//将最大和赋值为首元素值，temp记录临时子序列和
//		int maxSum = nums[0], temp = 0;
//		for (int i = 0; i < len; i++)
//		{
//			temp += nums[i];
//			
//			//若元素和大于当前最大和
//			if(temp > maxSum)
//			{
//				maxSum = temp;
//			}//else
//
//			//若子系列和为非正数，则从下一个元素重新记录
//			if (temp <= 0)
//			{
//				temp = 0;
//			}
//			
//		}//for
//
//		return maxSum;
//	}
//};

class Solution {
public:
	int maxSubArray(vector<int>& nums) {

		if (nums.empty())
			return 0;

		//求数组的长度
		int len = nums.size();

		return Divide(nums , 0 , len-1);
	}

	//分治法
	int Divide(const vector<int> &nums, int lhs, int rhs)
	{
		if (lhs == rhs)
			return nums[lhs];

		int mid = (lhs + rhs) / 2;
		int leftMaxSum = Divide(nums, lhs, mid);
		int rightMaxSum = Divide(nums, mid + 1, rhs);

		int lsum = INT_MIN;
		int rsum = INT_MIN;

		int temp = 0;
		for (int i = mid; i >= lhs; i--)
		{
			temp += nums[i];
			if (temp > lsum)
				lsum = temp;
		}

		temp = 0;
		for (int i = mid + 1; i <= rhs; i++)
		{
			temp += nums[i];
			if (temp > rsum)
				rsum = temp;
		}

		//跨越中点的最大子序列和
		temp = lsum + rsum;

		return std::max(temp, std::max(leftMaxSum, rightMaxSum));
	}
};


int main()
{
	vector<int> v1 = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
	vector<int> v2 ={-1 , -2 , -3 , 0};
	Solution s;

	cout << s.maxSubArray(v1) << endl;

	system("pause");

	return 0;
}