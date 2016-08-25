/*349. Intersection of Two Arrays*/
#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		int l1 = nums1.size(), l2 = nums2.size();

		map<int, int> m;
		set<int> s;
		for (int i = 0; i < l1; ++i)
		{
			++m[nums1[i]];
		}//for

		vector<int> ret;
		for (int i = 0; i < l2; ++i)
		{
			if (m[nums2[i]] > 0)
				s.insert(nums2[i]);
				
		}//for

		return vector<int>(s.begin(), s.end());
	}
};

int main()
{
	vector<int> v1 = { 1 }, v2 = { 1};

	vector<int> ret = Solution().intersection(v1, v2);

	for (auto iter = ret.begin(); iter != ret.end(); ++iter)
		cout << *iter << "\t";
	cout << endl;

	system("pause");
	return 0;
}