#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:
	int climbStairs(int n) {

		//如果0层，返回0
		if (n <= 0)
			return 0;
		//如果只有1层阶梯，则只有一种方式
		else if (n == 1)
			return 1;
		//若有两层阶梯，则有两种方式（每次走一层，一次走两层）
		else if (n == 2)
			return 2;
		
		int *r = new int[n];
		//其余的情况方式总数 = 最终剩余1层的方式 + 最终剩余两层阶梯的方式
		r[0] = 1;
		r[1] = 2;

		for (int i = 2; i < n; i++)
			r[i] = r[i - 1] + r[i - 2];

		int ret = r[n - 1];
		delete []r;
		return ret;
	}
};

int main()
{
	Solution s;

	cout << s.climbStairs(8) << endl;

	system("pause");

	return 0;

}