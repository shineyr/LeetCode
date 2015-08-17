#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		if (nums.size() == 0)
			return 0;
		else if (nums.size() == 1)
		{
			if (nums[0] >= target)
				return 0;
			else
				return 1;
		}
		else{
			return BinarySearch(nums, target);
		}
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
				if (mid == right || nums[mid + 1] > target)
					return mid + 1;
				else
					left = mid + 1;
			}
			else{
				if (mid == left || nums[mid - 1] < target)
					return mid;
				else
					right = mid - 1;
			}
		}//while

		return -1;
	}
};

int main()
{
	int arr1[4] = { 1, 3, 5, 6 };
	//5 → 2
	int arr2[4] = { 1, 3, 5, 6 }; 
	//2 → 1
	int arr3[4] = { 1, 3, 5, 6 };
	//7 → 4
	int arr4[4] = { 1 };
	//0 → 0

	vector<int> v(arr4, arr4 + 1);
	Solution s;
	cout << s.searchInsert(v, 2);

	system("pause");
	return 0;
}