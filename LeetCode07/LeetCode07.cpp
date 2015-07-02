#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

class Solution
{
public:
	int reverse(int x)
	{
		if (overflow(x) == true)
		{
			return 0;
		}

		int result = 0;

		while (x != 0)
		{
			result = 10 * result + x % 10;
			x /= 10;
		}

		return result;
	}
private:
	bool overflow(int x)
	{
		if (x / 1000000000 == 0) // x的绝对值小于1000000000, 不越界
		{
			return false;
		}
		else if (x == INT_MIN) // INT_MIN反转后越界，也没法按下述方法取绝对值（需要特判），直接返回true
		{
			return true;
		}
		x = abs(x);
		// x = d463847412 ->  2147483647. (参数x，本身没有越界，所以d肯定是1或2)
		// or -d463847412 -> -2147483648. 
		for (int cmp = 463847412; cmp != 0; cmp /= 10, x /= 10)
		{
			if (x % 10 > cmp % 10)
			{
				return true;
			}
			else if (x % 10 < cmp % 10)
			{
				return false;
			}
		}

		return false;
	}
};

int main()
{
	Solution s;
	cout << s.reverse(2147482345) << endl;
	system("pause");
	return 0;
}