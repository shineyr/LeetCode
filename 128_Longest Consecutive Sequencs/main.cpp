#include <iostream>
#include <cstdlib>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
	//方法一：使用unordered_set
	int longestConsecutive1(vector<int>& nums) {
		if (nums.empty() || nums.size() == 1)
			return nums.size();

		//保存序列元素个数
		int size = nums.size();
		unordered_set<int> existNums, visitedNums;
		for (int i = 0; i < size; ++i)
		{
			existNums.insert(nums[i]);
		}

		int maxCount = 0;
		for (int i = 0; i < size; ++i)
		{
			//每个连续序列中的元素只需要遍历一次,只有不在已遍历序列中时,向两侧探查
			if (visitedNums.find(nums[i]) != visitedNums.end())
				continue;
			int count = 1, less = nums[i] - 1, great = nums[i] + 1;
			while (existNums.find(less) != existNums.end())
			{
				visitedNums.insert(less);
				++count;
				--less;
			}//while
			while (existNums.find(great) != existNums.end())
			{
				visitedNums.insert(great);
				++count;
				--less;
			}//while
			if (count > maxCount)
				maxCount = count;
		}//for
		return maxCount;
	}

	//方法二：使用unordered_map
	int longestConsecutive(vector<int>& nums) {
		if (nums.empty() || nums.size() == 1)
			return nums.size();

		//保存序列元素个数
		int size = nums.size();
		unordered_map<int, bool> visitedNums;
		for (int i = 0; i < size; ++i)
		{
			visitedNums[nums[i]] = false;
		}

		int maxCount = 0;
		for (int i = 0; i < size; ++i)
		{
			//若已访问过，则跳过
			if (visitedNums[nums[i]])
				continue;
			int count = 1;
			//改变访问标记
			visitedNums[nums[i]] = true;

			int less = nums[i] - 1, great = nums[i] + 1;
			while (visitedNums.find(less) != visitedNums.end())
			{
				visitedNums[less] = true;
				--less;
				++count;			
			}//while

			while (visitedNums.find(great) != visitedNums.end())
			{
				visitedNums[great] = true;
				++great;
				++count;
			}//while			
		if (count > maxCount)
				maxCount = count;	
		}//for
		return maxCount;
	}

};

int main()
{
	vector<int> v = { 100, 4, 200, 1, 3, 2 };

	Solution s;
	cout << s.longestConsecutive(v) << endl;

	system("pause");
	return 0;
}