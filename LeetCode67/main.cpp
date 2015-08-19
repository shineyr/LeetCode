#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Solution {
public:
	string addBinary(string a, string b) {
		//首先，求得两个字符串的长度
		int la = strlen(a.c_str());
		int lb = strlen(b.c_str());

		//若其中一个字符串为空，直接返回另一个字符串即可
		if (la == 0)
			return b;
		else if (lb == 0)
			return a;

		//保存进位
		int carry = 0 ;
		//保存结果
		string r = la > lb ? a : b ;
		int k = la > lb ? la - 1 : lb - 1;
		//循环变量
		int ia = la - 1, ib = lb - 1;
		for (; ia >= 0 && ib >= 0; --ia, --ib)
		{ 
			//转换为整数计算
			int temp = (a[ia] - '0') + (b[ib] - '0') + carry;
			if (temp >= 2)
			{
				temp -= 2;
				carry = 1;
			}
			else{
				carry = 0;
			}//if
			//保存结果为相应字符类型
			r[k] = temp + '0';
			--k;
		}//while

		while (ia >= 0)
		{
			int temp = (a[ia] - '0') + carry;
			if (temp >= 2)
			{
				temp -= 2;
				carry = 1;
			}
			else{
				carry = 0;
			}//if
			r[k] = temp + '0';
			--ia;
			--k;
		}//while

		while (ib >= 0)
		{
			int temp = (b[ib] - '0') + carry;
			if (temp >= 2)
			{
				temp -= 2;
				carry = 1;
			}
			else{
				carry = 0;
			}//if
			r[k] = temp + '0';
			--ib;
			--k;
		}

		//若首位也有进位，则用"1"链接
		if (carry == 0)
			return r;
		else{
			return "1"+r;
		}
			
	}
};

int main()
{
	string a = "1", b = "1111";

	Solution s;

	cout << s.addBinary(a, b) << endl;

	system("pause");
	return 0;

}
