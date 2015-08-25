#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:
	int search(vector<int>& nums, int target) {
		if (nums.empty())
			return -1;

		//找到旋转点
		int pivot = findPivot(nums , 0 , nums.size()-1);
		int pos = binarySearch(nums, 0, pivot - 1, target);
		if (pos != -1)
			return pos;
		else
			pos = binarySearch(nums, pivot, nums.size() - 1, target);

		return pos != -1 ? pos : -1;

	}

	//寻找旋转点
	int findPivot(vector<int> &nums , const int &lhs , const int &rhs)
	{
	
		if (nums.empty() || lhs > rhs)
			return -1;
		
		int middle = (lhs + rhs) / 2;

		if (nums[middle] >= nums[lhs])
		{
			int pivot = findPivot(nums, middle + 1, rhs);
			if (pivot == -1)
				return lhs;
			else if (nums[lhs] < nums[pivot])
				return lhs;
			else
				return pivot;
		}
		else{
			int pivot = findPivot(nums, lhs, middle-1);
			if (pivot == -1)
				return middle;
			else if (nums[middle] < nums[pivot])
				return middle;
			else
				return pivot;
		}//else	
	}

	int binarySearch(vector<int> &nums, const int &lhs , const int &rhs ,int target)
	{
		if (nums.empty() || lhs > rhs)
			return -1;

		int middle = (lhs + rhs) / 2;
		if (nums[middle] == target)
			return middle;
		else if (nums[middle] < target)
		{
			return binarySearch(nums, middle + 1, rhs, target);
		}
		else{
			return binarySearch(nums, lhs, middle - 1, target);
		}//else
	}
};

int main()
{
	Solution s;
	int arr[8] = { 5, 6, 7, 0, 1, 2, 3, 4 };
	vector<int> v(arr, arr + 8);

	cout << s.search(v, 0) << endl;

	system("pause");

	return 0;

}