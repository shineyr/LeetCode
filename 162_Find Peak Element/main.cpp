#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:
	//方法一：顺序遍历 T(n) = O(n) 比较次数O(2n)
	int findPeakElement1(vector<int>& nums) {
		if (nums.empty())
			return -1;

		int len = nums.size();
		if (len == 1)
			return 0;

		for (int i = 0; i < len; ++i)
		{
			if (i == 0)
			{
				if (nums[i] > nums[i + 1])
					return i;
				else
					continue;
			}//if			
			if (i == len - 1)
			{
				if (nums[i] > nums[i - 1])
					return i;
				else
					continue;
			}//if

			if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1])
				return i;
		}//for
		return 0;
	}

	/* 按照题意，num[0]是大于左边的不存在的那个元素的，num[size-1]也是大于右边那个不存在的元素的，
	 * 假如不存在，那么就会有num[0]<num[1]，num[1]<num[2]，就是增序，num[size-2]<num[size-1]，
	 * 这样num[size-1]就是peak elem了，所以一定存在。
	 * 于是就是这样的思路，num[NULL] < num[0],我们假设左边的元素小于右边的元素，
	 * 那么第一个左边元素大于右边的那个一定是peak elem.如num[0].为什么第一个就是呢？
	 * 因为前面的都是左<右，判断左>右为false。
	 */
	//方法二：T(n) = O(n) 比较次数O(n)
	int findPeakElement2(const vector<int> &num) {//smart O(n), compare n times.
		for (int i = 1; i < num.size(); i++){
			if (num[i] < num[i - 1])
				return i - 1;
		}
		return num.size() - 1;
	}
	
	//方法三：时间O(logn)
	int findPeakElement(const vector<int> &num) {
		int left = 0, right = num.size() - 1;

		while (left <= right){
			if (left == right)
				return left;
			int mid = (left + right) / 2;

			if (num[mid] < num[mid + 1])
				left = mid + 1;
			else
				right = mid;
		}//while
	}

};

int main()
{
	vector<int> v = { 1, 2, 3, 1 };
	Solution s;
	cout << s.findPeakElement(v) << endl;

	system("pause");
	return 0;
}