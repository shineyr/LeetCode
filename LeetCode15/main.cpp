#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	//vector<vector<int>> threeSum(vector<int>& nums) {
	//	vector<vector<int>> vv;

	//	int size = nums.size();

	//	if (size < 3)
	//		return vv;

	//	for (int i = 0; i < size; i++)
	//	{
	//		for (int j = i + 1; j < size; j++)
	//		{
	//			for (int k = j + 1; k < size; k++)
	//			{
	//				if (nums[i] + nums[j] + nums[k] == 0)
	//				{
	//					int arr[3] = { nums[i], nums[j], nums[k] };
	//					//将arr中的元素从小到大排序
	//					sort(arr ， arr+3);

	//					vector<int> v = { arr, arr + 3 };
	//					if (!find(vv , v))
	//						vv.push_back(v);
	//				}
	//				else{
	//					continue;
	//				}
	//			}//for
	//		}//for
	//	}//for		
	//	return vv;
	//}

	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> vv;

		int size = nums.size();

		if (size < 3)
			return vv;

		sort(nums.begin() , nums.end());

		for (int i = 0; i < size; i++)
		{
			//跳过重复数字减少循环
			if ((i>0) && nums[i] == nums[i - 1])
				continue;

			int j = i + 1;
			int k = size - 1;


			//如果最大的数还小于0 则直接返回空集合
			if (nums[k] < 0)
				return vv;
			while (j < k)
			{
				int sum = nums[i] + nums[j] + nums[k];

				if (sum == 0)
				{
					//元素nums[i], nums[j], nums[k]本来就是从小到大排序
					int arr[3] = { nums[i], nums[j], nums[k] };

					vector<int> v = { arr, arr + 3 };
					
					vv.push_back(v);
						
					//跳过重复数字减少循环
					while ( (j<k) && (nums[j] == nums[j + 1]))
						j++;

					while ((j<k) && (nums[k] == nums[k - 1]))
						k--;

					j++;
					k--;
				}
				else if(sum < 0){
					j++;				
				}
				else{
					k--;
				}
			}
		}//for		
		return vv;
	}

	/*bool find(vector<vector<int>> &vv, vector<int> &v)
	{
		vector<vector<int>>::iterator iter;

		for (iter = vv.begin(); iter != vv.end(); iter++)
		{		
			if ((*iter)[0] == v[0] && (*iter)[1] == v[1] && (*iter)[2] == v[2])
			{
				return true;
			}						
		}
		return false;
	}*/

};

int main()
{
	Solution *s = new Solution();

	//vector<int> v = { -1, 0, 1, 2, -1, -4 };
	vector<int>v = { 7, -1, 14, -12, -8, 7, 2, -15, 8,
		8, -8, -14, -4, -5, 7, 9, 11, -4, -15, -6, 1,
		-14, 4, 3, 10, -5, 2, 1, 6, 11, 2, -2, -5, -7, -6, 
		2, -15, 11, -6, 8, -4, 2, 1, -1, 4, -6, -15, 1, 5, -15,
		10, 14, 9, -8, -6, 4, -6, 11, 12, -15, 7, -1, -9, 9, -1, 0, 
		-4, -1, -12, -2, 14, -9, 7, 0, -3, -4, 1, -2, 12, 14, -10, 0,
		5, 14, -1, 14, 3, 8, 10, -8, 8, -5, -2, 6, -11, 12, 13, -7, -12, 
		8, 6, -13, 14, -2, -5, -11, 1, 3, -6 };

	vector<vector<int>> vv = s->threeSum(v);
	
	vector<vector<int>>::iterator iter;
	for (iter = vv.begin(); iter != vv.end(); iter++)
	{
		cout << "(" << (*iter)[0] << ", " << (*iter)[1] << ", " << (*iter)[2] << ")"<<endl;
	}

	system("pause");
	return 0;
	
}