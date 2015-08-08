#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> vv = KSum(nums, target, 4);
		int len = vv.size();
		for (int i = 0; i < len; i++)
			sort(vv[i].begin(), vv[i].end());

		return vv;
	}

	vector<vector<int>> KSum(vector<int> &nums, int target, int k)
	{
		vector<vector<int>> vv;
		int len = nums.size();

		if (len < k)
			return vv;

		sort(nums.begin() , nums.end());

		if (k == 1)
		{
			for (int i = 0; i < len; i++)
			{
				vector<int> v;
				if (nums[i] == target)
				{
					v.push_back(nums[i]);
					vv.push_back(v);				
				}

				while (((i + 1) < len) && (nums[i + 1] == nums[i]))
				{
					i++;
				}				
			}//for
		}//if
		else
		{
			vector<int>::iterator iter = nums.begin();
			for (int i = 0; i < nums.size(); i++)
			{
				iter++;
				int j = 0;
				vector<int > _nums(iter, nums.end());
				vector<vector<int>> _vv = KSum(_nums, target - nums[i], k - 1);

				int _len = _vv.size();
				if (_len <= 0)
					continue;
				
				for (int j = 0; j < _len; j++)
				{
					_vv[j].push_back(nums[i]);
					vv.push_back(_vv[j]);				
				}//for

				while (((i + 1) < len) && (nums[i + 1] == nums[i]))
				{
					i++;
					iter++;
				}
					
			}//for
		}//else
		return vv;
	}
};

int main()
{
	Solution *s = new Solution();

	//vector<int> v = { 1, 0, -1, 0, -2, 2 };
	/*vector<int>v = { 7, -1, 14, -12, -8, 7, 2, -15, 8,
		8, -8, -14, -4, -5, 7, 9, 11, -4, -15, -6, 1,
		-14, 4, 3, 10, -5, 2, 1, 6, 11, 2, -2, -5, -7, -6,
		2, -15, 11, -6, 8, -4, 2, 1, -1, 4, -6, -15, 1, 5, -15,
		10, 14, 9, -8, -6, 4, -6, 11, 12, -15, 7, -1, -9, 9, -1, 0,
		-4, -1, -12, -2, 14, -9, 7, 0, -3, -4, 1, -2, 12, 14, -10, 0,
		5, 14, -1, 14, 3, 8, 10, -8, 8, -5, -2, 6, -11, 12, 13, -7, -12,
		8, 6, -13, 14, -2, -5, -11, 1, 3, -6 };*/
	vector<int> v = { -493, -482, -482, -456, -427, -405, -392, -385, -351, 
		-269, -259, -251, -235, -235, -202, -201, -194, -189, -187, -186, -180,
		-177, -175, -156, -150, -147, -140, -122, -112, -112, -105, -98, -49,
		-38, -35, -34, -18, 20, 52, 53, 57, 76, 124, 126, 128, 132, 142, 147, 157, 
		180, 207, 227, 274, 296, 311, 334, 336, 337, 339, 349, 354, 363, 372, 378,
		383, 413, 431, 471, 474, 481, 492, 6189,
		-177, -175, -156, -150, -147, -140, -122, -112, -112, -105, -98, -49};

	vector<vector<int>> vv = s->fourSum(v , 0);

	vector<vector<int>>::iterator iter;
	for (iter = vv.begin(); iter != vv.end(); iter++)
	{
		
		//cout << (*iter)[0] << endl;
		//cout << "(" << (*iter)[0] << ", " << (*iter)[1] << ")" << endl;
		//cout << "(" << (*iter)[0] << ", " << (*iter)[1] << ", " << (*iter)[2] << ")" << endl;
		cout << "(" << (*iter)[0] << ", " << (*iter)[1] << ", " << (*iter)[2] << " , " << (*iter)[3] << ")" << endl;
		//cout << "(" << (*iter)[0] << ", " << (*iter)[1] << ", " << (*iter)[2] << " , " << (*iter)[3] <<  " , " << (*iter)[4] << ")" << endl;
	}

	system("pause");
	return 0;

}