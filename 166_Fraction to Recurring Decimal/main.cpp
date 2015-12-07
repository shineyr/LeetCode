#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
	string fractionToDecimal(int numerator, int denominator) {
		string str = "";
		//除数为0，为异常情况
		if (denominator == 0)
			return str;
		//被除数为0，结果为0
		if (numerator == 0)
			return "0";
		//异或，numerator<0和denominator<0仅有一个为真
		if (numerator < 0 ^ denominator < 0) 
			str += '-';   
		//转化为正数，INT_MIN转化为正数会溢出，故用long long;long long int n=abs(INT_MIN)得到的n仍然是负的，所以写成下面的形式
		long long r = numerator; r = abs(r);
		long long d = denominator; d = abs(d);

		//得到整数部分并保存
		str += to_string(r / d);

		r = r % d;

		//可以整除，直接返回
		if (r == 0)
			return str;

		//添加小数点
		str += ".";
		//下面处理小数部分，用哈希表
		unordered_map<int, int> map;
		while (r){
			//检查余数r是否在哈希表中，是的话则开始循环了
			if (map.find(r) != map.end()){
				str.insert(map[r], 1, '(');
				str += ')';
				break;
			}
			map[r] = str.size();	//这个余数对应于result的哪个位置
			//正常运算
			r *= 10;
			str += to_string(r / d);
			r = r % d;
		}
		return str;
		
	}

	//整数到字符串的转换函数
	string intToStr(long long num)
	{
		string str = "";
		if (num < 10)
		{
			char c = num + '0';
			return str + c;
		}
		else
		{
			while (num)
			{
				int d = num % 10;
				char c = d + '0';
				str += c;
				num /= 10;
			}//while
			reverse(str.begin(), str.end());
			return str;
		}//else
	}
};

int main()
{
	Solution s;
	cout << s.fractionToDecimal(INT_MIN, -1) << endl;
	cout << s.fractionToDecimal(2, 1) << endl;
	cout << s.fractionToDecimal(1, 17) << endl;

	system("pause");
	return 0;
}