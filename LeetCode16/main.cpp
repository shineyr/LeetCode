#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

	////方法一：三层穷举，超时异常 
	//int threeSumClosest(vector<int>& nums, int target) {

	//	int len = nums.size();
	//	if (len < 3)
	//	{
	//		return 0;
	//	}
	//	int closest = nums[0] + nums[1] + nums[2];

	//	for (int i = 1; i < len-2; i++)
	//	{
	//		//首先进行去重操作
	//		if (nums[i] == nums[i - 1])
	//			continue;

	//		for (int j = i + 1; j < len - 1; j++)
	//		{
	//			if (nums[j] == nums[j - 1])
	//				continue;
	//			for (int k = j + 1; k < len; k++)
	//			{
	//				if (nums[k] == nums[k - 1])
	//					continue;
	//				int sum = nums[i] + nums[j] + nums[k];

	//				if (sum == target)
	//				{
	//					closest = sum;
	//					break;
	//				}//if
	//				else	if (abs(sum - target) < abs(closest - target))
	//				{
	//					closest = sum;
	//				}//elif
	//				else
	//					continue;
	//			}//for
	//		}//for
	//	}//for

	//	return closest;
	//}

	/** 参考
	* 处理复杂度为O(n2)
	* 主要思路：
	* 1、先对输入数组进行排序，主要为了计算中的首尾逼近，还有在数组含有重复元素时可以避免重复计算
	* 2、设置判断上限为表示距离类型的最大值
	*   （距离为相对距离，判断过程中：如果小于目标值，则目标值减中间结果；如果大于目标值则中间结果减目标值）
	* 3、穷举法选取符合条件的三元组中的第一个元素，范围为[0...n-3]。
	*    对于剩下的两个元素则从第一个元素之后的位置与数组结尾位置之间通过首尾逼近的方法来选取最小距离
	*    由于每个元素只能取一次，所以当前循环的起始为上次循环起始之后
	*    同时在穷举和逼近的过程中跳过求和结果和上次相同的计算和判断过程，加速判断过程
	* 4、对于穷举的每个三元组求和后，获取距离最近（可能大于目标值也可能小于目标值）的那一组。如果遇到和目标值相同的结果则直接返回该结果
	* 提交结果：
	* (Judge Small)
	* Run Status: Accepted!
	* Program Runtime: 8 milli secs （基本在几毫秒）
	* Progress: 28/28 test cases passed.
	* (Judge Large)
	* Run Status: Accepted!
	* Program Runtime: 48 milli secs （基本稳定在五十毫秒左右）
	* Progress: 311/311 test cases passed.
	*/
	int threeSumClosest(vector<int>& nums, int target) {
		size_t size = nums.size();
		if (size < 3)
		{
			cout << "num size must bigger than there!" << endl;
			return 0;
		}
		sort(nums.begin(), nums.end());   // 对于以下的处理过程必须事先排序，类似二分搜索  
		int result = 0;     // 记录最终结果  
		int distance = numeric_limits<int>::max();    // signed int  
		int sum = 0;        // 中间结果  
		size_t i = 0, j = i + 1, k = size - 1;

		for (i = 0; i < size - 2; i++)    // 三元组的第一个元素一次遍历，范围为[0...n-3]  
		{
			// 去重避免重复计算，如果和上次同则跳过  
			if (i > 0 && nums[i] == nums[i - 1])
			{
				continue;
			}

			j = i + 1;  // 选定三元组第一个元素后，第二个元素从第一个元素的下一个位置开始考察  
			k = size - 1;   // 选定三元组第一个元素后，第三个元素从数组末尾开始考察  
			while (j < k)    // 三元组的后两个元素利用左右逼近来跳过效率，选定第一个元素后，其后的所有元素只需考察一遍  
			{
				sum = nums[i] + nums[j] + nums[k];
				if (sum == target)  // 存在距离最近为0则直接返回，否则穷举选取非0最小距离  
				{
					return sum;
				}
				else if (sum < target)
				{
					if ((target - sum) < distance)
					{
						result = sum;
						distance = target - sum;
					}
					j = j + 1;
					// 避免重复计算，如果和上次同则跳过  
					if (nums[j] == nums[j - 1])
					{
						j = j + 1;
					}
				}
				else if (sum > target)
				{
					if ((sum - target) < distance)
					{
						result = sum;
						distance = sum - target;
					}
					k = k - 1;
					// 避免重复计算如果和上次同则跳过  
					if (nums[k] == nums[k + 1])
					{
						k = k - 1;
					}

				}
			}
		}
		return result;
	}
	int abs(int a)
	{
		return a > 0 ? a : 0-a;
	}
};

int main()
{
	/*int arr[35] = { 38, 60, -3, -12, 48, 100, 18, -76, -12, -99, 45, 67, 42, 66, -25, -38,
		-52, -53, 57, 53, 100, -60, 75, -75, -52, -98, 80, 49, 87, 35, 9, 6, -37, 48, 23 };*/

	int arr[4] = {-1 , 2 , 1 , -4};
		
	vector<int> v(arr , arr+4);
	int target = 1;

	Solution *s = new Solution();
	cout << s->threeSumClosest(v, target) << endl;
	system("pause");
	return 0;
}