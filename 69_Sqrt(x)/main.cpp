#include <iostream>
#include <cstdlib>

using namespace std;

class Solution {
public:
	int mySqrt(int x) {
		if (x < 0)
			return -1;

		//使用二分法求解
		unsigned long long lhs = 0, rhs = (x + 1) / 2;

		while (lhs <= rhs)
		{
			unsigned long long mid = (lhs + rhs) / 2;
			//注意溢出问题，使用无符号长整型存储临时乘积
			unsigned long long tmp1 = mid * mid;
			if (tmp1 == x)
			{
				return mid;
			}
			else if (tmp1 < x)
			{
				lhs = mid + 1;
			}				
			else{
				rhs = mid - 1;
			}//else
		}//while

		unsigned long long tmp = lhs * lhs;
		if (tmp <= x)
			return lhs;
		else
			return rhs;
	}

	//牛顿迭代法 
	int mySqrt2(int x)
	{
		if (x < 0)
			return -1;

		double pre, cur = 1;		
		do
		{
			pre = cur;
			cur = x / (2 * pre) + pre / 2.0;
		} while (abs(cur - pre) > 0.00001);

		return (int)cur;
	}
};


int main()
{
	Solution s;
	cout << s.mySqrt(3) << endl;
	cout << s.mySqrt(10) << endl;
	system("pause");
	return 0;
}