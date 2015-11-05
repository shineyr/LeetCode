#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>

using namespace std;

class Solution {
public:
	//方法一：逐个判断O(n^(3/2))算法，TLE
	int countPrimes1(int n) {
		int count = 0;
		for (int i = 2; i < n; ++i)
		{
			if (isPrime(i))
				++count;
		}
		return count;
	}

	bool isPrime(int n)
	{
		for (int i = 2; i <= sqrt(n); ++i)
			if (n % i == 0)
				return false;
		return true;
	}

	//方法二：素数不能被比它小的整数整除,建一个标志数组,从2开始,把其倍数小于N的都删掉
	int countPrimes2(int n)
	{
		vector<int> flags(n + 1, 1);
		for (int i = 2; i*i <= n; ++i)
		{
			//把素数的倍数全部设置为非素数标志
			if (flags[i])
			{
				//内层循环从i开始, 比i小的会在以前就被check过
				for (int j = i; i*j < n; ++j)
				{
					flags[i*j] = 0;
				}//for
			}//for
		}//for

		int count = 0;
		for (int i = 2; i < n; ++i)
		{
			if (flags[i])
				++count;
		}
		return count;
	}

	//方法三，与二思路相同，另一种实现方式
	int countPrimes(int n)
	{
		if (n <= 2)
			return 0;

		vector<int> flags(n, 1);
		//记录素数的个数
		int count = n - 2;
		for (int i = 2; i*i <= n; ++i)
		{
			if (flags[i])
			{
				//内层循环从i开始, 比i小的会在以前就被check过
				for (int j = i; i*j < n; ++j)
				{
					//如果原来标记的为素数，现在改为非素数，同时更新素数个数
					if (flags[i*j])
					{
						flags[i*j] = 0;
						--count;
					}//if
				}//for
			}//if
		}//for
		return count;
	}
};

int main()
{
	Solution s;
	cout << s.countPrimes(13) << endl;

	system("pause");

	return 0;

}
