#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Solution {
public:
	bool isAdditiveNumber(string num) {
		if (num.empty())
			return false;

		int len = num.size();
		for (int i = 1; i < len - 1; ++i)
		{
			string a = num.substr(0, i);

			//非首个以0开头的加数违反规则
			if (a[0] == '0' && i > 1)
				continue;

			for (int j = 1; j < len; ++j)
			{
				string b = num.substr(i, j);
				if (b[0] == 0 && j > 1)
					continue;
				string ret = add(a, b);
				if (i + j + ret.length() > len)
					continue;

				//存储原字符串中和上一和 同样长度的子串
				string val = num.substr(i + j, ret.length());
				
				//当前已经相加的末尾下标
				int pass = i + j;
				
				string tmp;
				while (ret == val)
				{
					//判断是否到字符串末尾
					pass += val.length();
					if (len == pass)
						return true;
					tmp = b;
					b = ret;
					//下一步骤加法实现
					ret = add(tmp, b);
					val = num.substr(pass, ret.length());
				}//while
			}//for
		}//for
		return false;
	}

	//字符串加法实现
	string add(string a, string b)
	{
		int len_a = a.size(), len_b = b.size();
		
		string ret = "";
		int i = len_a - 1, j = len_b - 1, carry = 0;

		while (i>=0 && j>=0)
		{
			int tmp = a[i] + b[j] - 2 * '0' + carry;
			carry = tmp / 10;
			char c = tmp % 10 + '0';

			ret += c;
			--i;
			--j;
		}//while

		while (i >= 0)
		{
			int tmp = a[i] - '0' + carry;
			carry = tmp / 10;
			char c = tmp % 10 + '0';

			ret += c;
			--i;
		}//while

		while (j >= 0)
		{
			int tmp = b[j] - '0' + carry;
			carry = tmp / 10;
			char c = tmp % 10 + '0';

			ret += c;
			--j;
		}//while

		if (carry != 0)
			ret += carry + '0';

		reverse(ret.begin(), ret.end());

		return ret;
	}
};

int main()
{
	string str = "112358";
	Solution s;
	cout << s.isAdditiveNumber(str) << endl;

	system("pause");
	return 0;
}