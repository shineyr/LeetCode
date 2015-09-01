#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

class Solution {
public:
	double myPow(double x, int n) {
		if (n == 0)
			return 1.0;
		else {

			if (n < 0)
			{
				//判断是否溢出
				if (n == INT_MIN)
					return 1.0 / (pow(x, INT_MAX)*x);
				else
					return 1.0 / pow(x, -n);
			}else{
				if (n % 2 == 0)
				{
					double temp = myPow(x, n >> 1);
					return temp * temp;
				}
				else{
					double temp = myPow(x, (n - 1) >> 1);
					return temp * temp * x;
				}
				
			}//else
			
		}//else
	}
};
//
//class Solution {
//public:
//	double myPow(double x, int n) {
//		// Start typing your C/C++ solution below
//		// DO NOT write int main() function
//		if (n<0)
//		{
//			if (n == INT_MIN)
//				return 1.0 / (pow(x, INT_MAX)*x);
//			else
//				return 1.0 / pow(x, -n);
//		}
//		if (n == 0)
//			return 1.0;
//		double ans = 1.0;
//		for (; n>0; x *= x, n >>= 1)
//		{
//			if (n & 1>0)
//				ans *= x;
//		}
//		return ans;
//	}
//};

int main()
{
	Solution s;
	cout << s.myPow(2, 4) << endl;
	cout << s.myPow(2, -4) << endl;
	cout << s.myPow(0.00001, 2147483647) << endl;

	//cout << s.myPow(1.00000, -2147483648) << endl;

	cout << INT_MIN << endl;
	system("pause");
	return 0;

}