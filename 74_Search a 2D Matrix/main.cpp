#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.empty())
			return false;

		int m = matrix.size();

		//将矩阵首列，压入临时vector，寻找，目标元素所在的行
		vector<int> v;
		for (int i = 0; i < m; i++)
			v.push_back(matrix[i][0]);

		//寻找 <=target 最近的元素下标
		int pos = binarySearchPos(v, 0, m - 1, target);

		//不存在任何一行中
		if (pos == -1)
			return false;
		else if(matrix[pos][0] == target)
			return true;
		else
			return binarySearch(matrix[pos], 0, matrix[pos].size() - 1, target);

	}

	int binarySearchPos(vector<int> &nums, int lhs, int rhs, int &target)
	{
		if (nums.empty())
			return -1;

		while (lhs <= rhs)
		{
			int mid = (lhs + rhs) / 2;

			if (nums[mid] == target)
				return mid;

			else if (nums[mid] < target)
			{
				lhs = mid + 1;
			}
			else{
				rhs = mid - 1;
			}//else
		}//while

		if (lhs < rhs && nums[lhs] < target)
		{
			return lhs;
		}
		else{
			return lhs - 1;
		}
	}

	bool binarySearch(vector<int> &nums, int lhs, int rhs, int &target)
	{
		if (nums.empty())
			return false;

		while (lhs <= rhs)
		{
			int mid = (lhs + rhs) / 2;

			if (nums[mid] == target)
				return true;

			else if (nums[mid] < target)
			{
				lhs = mid + 1;
			}
			else{
				rhs = mid - 1;
			}//else
		}//while
		return false;
	}
};

int main()
{
		Solution s;
	
		vector<vector<int> > v = { {1} };

		cout << s.searchMatrix(v, 2) << endl;

		system("pause");
		return 0;


}