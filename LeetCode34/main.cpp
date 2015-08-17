#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> ret;
		if (nums.size() == 0)
		{
			ret.push_back(-1);
			ret.push_back(-1);
			return ret;
		}

		//寻找目标元素的下标
		int pos = BinarySearch(nums, target);

		//目标元素不存在
		if (pos == -1)
		{
			ret.push_back(-1);
			ret.push_back(-1);
			return ret;
		}
		else{
			int left = BinarySearchLeft(nums, 0, pos, target);
			int right = BinarySearchRight(nums, pos, nums.size()-1 , target);
			ret.push_back(left);
			ret.push_back(right);
			return ret;
		}//if

	}


	int BinarySearch(vector<int> & nums, int target)
	{
		int left = 0, right = nums.size() - 1;

		while (left <= right)
		{
			int mid = (left + right) / 2;
			if (nums[mid] == target)
				return mid;
			else if (nums[mid] < target)
			{
				left = mid + 1;
				continue;
			}
			else{
				right = mid - 1;
				continue;
			}
		}//while

		return -1;
	}

	int BinarySearchLeft(vector<int> & nums, int left, int right, int target)
	{
		while (left < right)
		{
			int mid = (left + right) / 2;
			if (nums[mid] == target && nums[mid-1] < target)
				return mid;
			else if (nums[mid] < target)
			{
				left = mid + 1;
				continue;
			}
			else{
				right = mid - 1;
				continue;
			}
		}//while
		return left;
	}

	int BinarySearchRight(vector<int> & nums, int left, int right, int target)
	{
		while (left < right)
		{
			int mid = (left + right) / 2;
			if (nums[mid] == target && nums[mid + 1] > target)
				return mid;
			else if (nums[mid] <= target)
			{
				left = mid + 1;
				continue;
			}
			else{
				right = mid - 1;
				continue;
			}
		}//while
		return right;
	}
};

int main()
{
	Solution s;

	int arr[2] = { 5, 6 };

	vector<int> v(arr, arr + 2);

	vector<int> ret = s.searchRange(v, 7);

	cout << "[ " << ret[0] << " , " << ret[1] << " ]" << endl;

	system("pause");
	return 0;

}