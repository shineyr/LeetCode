#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	vector<string> summaryRanges(vector<int>& nums) {
		if (nums.empty())
			return vector<string>();

		int sz = nums.size();

		vector<string> ret;
		int start = nums[0], end = nums[0];
		for (int i = 1; i < sz; ++i)
		{
			if (nums[i] == end + 1)
				end = nums[i];
			else{
				string tmp;
				if (end == start)
					tmp = IntToString(start);
				else
					tmp = IntToString(start) + "->" + IntToString(end);
				
				ret.push_back(tmp);

				start = nums[i];
				end = nums[i];
			}
		}//for
		
		//加上最后一组
		string tmp;
		if (end == start)
			tmp = IntToString(start);
		else
			tmp = IntToString(start) + "->" + IntToString(end);
		ret.push_back(tmp);

		return ret;
	}

	string IntToString(long num)
	{
		if (num == 0)
			return "0";		
		else if (num == INT_MIN)
			return "-2147483648";		
		string str;
		bool flag = num < 0 ? false : true;

		num = abs(num);
		while (num)
		{
			char c = num % 10 + '0';
			num /= 10;
			str += c;
		}//while
		reverse(str.begin(), str.end());

		if (flag)
			return str;
		else
			return "-" + str;
	}
};

int main()
{
	vector<int> v = {INT_MIN, -2147483647, INT_MAX};

	Solution s;
	vector<string> vs = s.summaryRanges(v);

	for (unsigned i = 0; i < vs.size(); ++i)
		cout << vs[i] << "\t";
	cout << endl;

	system("pause");

	return 0;
}