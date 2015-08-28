#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Solution {
public:
	string multiply(string num1, string num2) {
		//如果有其中一个乘数的字符串表示为空，则返回空字符串
		if (num1.empty() || num2.empty())
			return string();

		if (num1 == "0" || num2 == "0")
			return "0";

		//按照整数从低位到高位计算，翻转两个乘数字符串
		reverse(num1.begin(), num1.end());
		reverse(num2.begin(), num2.end());
		//求两个乘数字符串的长度
		int len1 = strlen(num1.c_str()), len2 = strlen(num2.c_str());

		//定义乘法结果字符串
		string ret = "";
		//保存进位
		int carry = 0; 

		for (int i = 0; i < len1; i++)
		{
			//乘数的处理起始位
			size_t pos = i;
			for (int j = 0; j < len2; j++)
			{
				int temp = (num1[i] - '0') * (num2[j] - '0') + carry;
			
				//向当前位加入结果
				if (pos < ret.length())
				{
					temp = temp + (ret[pos] - '0');
					ret[pos] = temp % 10 + '0';
				}//if
				else{
					ret.append(1, temp % 10 + '0');
				}//else
				//计算下一个进位
				carry = temp / 10;
				//处理乘数的下一位
				pos++;
			}//for
			if (carry > 0)
				ret.append(1, carry + '0');
			carry = 0;
		}//for
		
		//翻转整个结果字符串
		reverse(ret.begin(), ret.end());
		return ret;

	}
};

int main()
{
	Solution s;
	cout << s.multiply("123", "0") << endl;

	system("pause");
	return 0;
}