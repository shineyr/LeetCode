#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		int len = digits.size();

		if (len == 0)
			return digits;

		int carry = 1;
		for (int i = len - 1; i >= 0; --i)
		{
			digits[i] += carry;
			if (digits[i] >= 10)
			{
				digits[i] -= 10;
				carry = 1;
				continue;
			}
			else{
				carry = 0;
				break;
			}
		}

		if (carry == 0)
			return digits;
		else
		{
			vector<int> v;
			v.push_back(1);
			for (int i = 0; i < len; i++)
				v.push_back(0);
			return v;
		}
	}
};

int main()
{
	Solution s;
	int arr[3] = { 9, 9, 9 };

	vector<int> v{ arr, arr + 3 };

	vector<int> r;
	r = s.plusOne(v);

	for (int i = 0; i < r.size(); ++i)
		cout << r[i];
	cout << endl;

	system("pause");
	return 0;
}