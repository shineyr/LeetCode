#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	//方法一：遗憾的TLE
	int maxProduct1(vector<int>& nums) {
		if (nums.empty())
			return 0;

		int size = nums.size();
		//求从0~size-1处开始，每处能够得到的最大子数组乘积
		vector<int> maxP(size, 1);
		for (int i = 0; i < size; ++i)
		{
			maxP[i] = nums[i];
		}//for

		for (int i = 0; i < size; ++i)
		{
			int curP = maxP[i];

			for (int j = i + 1; j<size; ++j)
			{
				curP *= nums[j];
				if (maxP[i] < curP)
					maxP[i] = curP;
			}			
		}//for
	
		//找到最大子数组乘积中的最大乘积值
		int maxRet = maxP[0];
		for (int i = 1; i < size; ++i)
		{
			if (maxP[i] > maxRet)
				maxRet = maxP[i];
		}//for
		return maxRet;
	}

	//方法二：时间复杂度为O(n)
	int maxProduct(vector<int>& nums) {
		if (nums.empty())
			return 0;

		int size = nums.size();
		
		//存储最大子数组乘积，当前最大、最小值
		int maxRetP = nums[0], curMaxP = nums[0], curMinP = nums[0];
		for (int i = 1; i < size; ++i)
		{
			int tmpMax = curMaxP * nums[i];
			int tmpMin = curMinP * nums[i];

			//更新当前最大、最小值
			curMaxP = max(max(tmpMax , tmpMin), nums[i]);
			curMinP = min(min(tmpMax , tmpMin), nums[i]);

			//更新当前最大子数组结果
			maxRetP = max(maxRetP, curMaxP);
		}//for
		return maxRetP;
	}
};

int main()
{
	Solution s;
	vector<int> v = { 2, 3, -2, 4 };
	cout << s.maxProduct(v) << endl;

	system("pause");
	return 0;
}