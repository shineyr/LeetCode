#include <iostream>
#include <cstdlib>
#include <vector>
#include <iterator>

using namespace std;

class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		vector<int> ret;
		int i = 0, j = 0;
		while (i < m && j < n)
		{
			if (nums1[i] <= nums2[j])
			{
				ret.push_back(nums1[i]);
				i++;
			}else{
				ret.push_back(nums2[j]);
				j++;
			}//elif
		}//while

		while (i < m)
		{
			ret.push_back(nums1[i]);
			i++;
		}//while

		while (j < n)
		{
			ret.push_back(nums2[j]);
			j++;
		}//while

		nums1 = ret;

	}

};

int main()
{
	int arr1[4] = { 1, 2, 2, 5 };
	int arr2[6] = { 1, 2, 3, 4, 5, 6 };

	vector<int> v1(arr1, arr1 + 4);
	vector<int> v2(arr2, arr2 + 6);

	Solution s;
	s.merge(v1, 4 , v2 , 6);

	vector<int>::iterator iter = v1.begin();
	while (iter != v1.end())
	{
		cout << *iter << "\t";
		iter++;
	}

	cout << endl;

	system("pause");
	return 0;
	
}