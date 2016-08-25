/*179. Largest Number*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string &s1, string &s2)
{
	string a = s1 + s2, b = s2 + s1;
	return a > b;
}

class Solution {
public:
	string largestNumber(vector<int>& nums) {
		if (nums.empty())
			return "";

		vector<string> vs;
		int n = nums.size();

		for (int i = 0; i < n; ++i)
		{
			char tmp[10];
			snprintf(tmp, 10, "%d", nums[i]);

			vs.push_back(tmp);
		}//for

		sort(vs.begin(), vs.end(),cmp);

		string ret;
		for (int i = 0; i < n; ++i)
			ret += vs[i];
		int idx = 0,len = ret.size();
		while (idx < len - 1 && ret[idx] == '0')
			++idx;

		return ret.substr(idx);
	}
};

int main()
{
	vector<int> v = { 0,0 };

	cout << Solution().largestNumber(v) << endl;

	system("pause");
	return 0;
}