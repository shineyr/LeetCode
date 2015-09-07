#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//调用STL库中标准算法next_permutation(),该方法造成Time Limited Exceed
//class Solution {
//public:
//	string getPermutation(int n, int k) {
//		if (n <= 0 || k <= 0 )
//			return "";
//		int f = factorial(n);
//		if (k > f)
//			return "";
//
//		vector<int> v;
//		for (int i = 1; i <= n; i++)
//			v.push_back(i);
//
//		int index = 1;
//		while (index < k && next_permutation(v.begin(), v.end()))
//			index++;
//
//		string str = "";
//		for (int i = 0; i < n; i++)
//			str += IntToStr(v[i]);
//		str += '\0';
//
//		return str;
//		
//	}
//
//	string IntToStr(int n)
//	{
//		string str = "";
//
//		while (n != 0)
//		{
//			str += (n % 10 + '0');
//			n /= 10;
//		}
//
//		reverse(str.begin(), str.end());
//
//		return str;
//	}
//
//	long factorial(int n)
//	{
//		if (n <= 1)
//			return 1;
//		else
//			return n * factorial(n - 1);
//	}
//};

class Solution {
public:

	string getPermutation(int n, int k) {
		vector<int> nums(n);

		int pCount = 1;
		for (int i = 0; i < n; ++i) {
			nums[i] = i + 1;
			pCount *= (i + 1);
		}

		k--;
		string res = "";
		for (int i = 0; i < n; i++) {
			pCount = pCount / (n - i);
			int selected = k / pCount;
			res += ('0' + nums[selected]);

			for (int j = selected; j < n - i - 1; j++)
				nums[j] = nums[j + 1];
			k = k % pCount;
		}
		return res;
	}

};

int main()
{
	Solution s;

	cout << s.getPermutation(8, 8590) << endl;

	system("pause");
	return 0;
}