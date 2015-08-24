#include <iostream>
#include <cstdlib>

using namespace std;

//方法一，翻倍累和  结果是：Time Limit Exceeded
//class Solution {
//public:
//	int divide(int dividend, int divisor) {
//
//		//如果被除数或者除数有一者为0 或者绝对值除数大于被除数则返回0
//		if (dividend == 0 || divisor == 0 || abs(divisor) > abs(dividend))
//			return 0;
//
//		int sign = ((dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0)) ? 1 : -1;
//
//		long long Dividend = abs(dividend), Divisor = abs(divisor);
//
//		long long sum = 0;
//		int count = 0, ret = 0;
//
//		while (Divisor <= Dividend)
//		{
//			count = 1;
//			sum = Divisor;
//			while ((sum + sum) < Dividend)
//			{
//				sum += sum;
//				count += count;
//			}
//			Dividend -= sum;
//			ret += count;
//		}
//
//		if (sign == -1)
//			return 0 - ret;
//		else
//			return ret;
//	}
//};

//方法二：位运算
class Solution {
public:
	int divide(int dividend, int divisor) {

		//如果被除数或者除数有一者为0 或者绝对值除数大于被除数则返回0
		if (dividend == 0 || divisor == 0)
			return 0;

		
		// without using * / mod
		// using add
		auto sign = [=](long long x) {
			return x < 0 ? -1 : 1;
		};

		int d1 = sign(dividend);
		int d2 = sign(divisor);

		long long n1 = abs(static_cast<long long>(dividend));
		long long n2 = abs(static_cast<long long>(divisor));

		long long ans = 0;

		while (n1 >= n2) {
			long long base = n2;
			for (int i = 0; n1 >= base; ++i) {
				n1 -= base;
				base <<= 1;
				ans += 1LL << i;
			}
		}
		//如果转换为int类型，结果溢出,返回INT_MAX ，int类型表示范围[-2147483648 , 2147483648)
		if (ans > INT_MAX && d1 == d2)
			return INT_MAX;

		int res = static_cast<int>(ans);
		if (d1 != d2) 
			return -res;
		else 
			return res;
	}
};

int main()
{
	Solution s;
	int a = 2147483648;

	cout << s.divide(-a, 1) << endl;

	system("pause");
	return 0;

}