//350. Intersection of Two Arrays II

#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		if (nums1.empty() || nums2.empty())
			return vector<int>();

		int l1 = nums1.size(), l2 = nums2.size();
		map<int, int> m;
		for (int i = 0; i < l1; ++i)
		{
			++m[nums1[i]];
		}//for

		vector<int> ret;
		for (int i = 0; i < l2; ++i)
		{
			if (m[nums2[i]] > 0)
			{
				ret.push_back(nums2[i]);
				--m[nums2[i]];
			}//if
		}//for

		return ret;
	}
};

int main()
{
	vector<int> v1 = { 1,2,2,1 }, v2 = { 2,2 };
	vector<int> ret = Solution().intersect(v1, v2);

	system("pause");
	return 0;
}